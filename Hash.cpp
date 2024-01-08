#include "Hash.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;
Hash::Hash() {
    length = 0;
    // Initialize the hash table with a default size (e.g., 1000)
    SneakersMap.resize(1000);
}

void Hash::PutItem(SneakerX item) {
    auto& bucket = SneakersMap[MyPairHash{}(make_pair(item.Brand, item.SName)) % SneakersMap.size()];
    bucket.push_back(make_pair(item.Brand, item));
    length++;
}

void Hash::DisplaySneakersInPriceRange(double minPrice, double maxPrice) {
    for (const auto& bucket : SneakersMap) {
        for (const auto& entry : bucket) {
            const SneakerX& curitem = entry.second;
            if (curitem.SPrice >= minPrice && curitem.SPrice <= maxPrice) {
                cout << "Brand: " << curitem.Brand << ", SName: " << curitem.SName << ", "
                    << "SPrice: " << curitem.SPrice << ", RPrice: " << curitem.RPrice << ", SSize: " << curitem.SSize << endl;
            }
        }
    }
}

void Hash::DisplayDiscountedItems() {
    for (const auto& bucket : SneakersMap) {
        for (const auto& entry : bucket) {
            const SneakerX& curitem = entry.second;
            if (curitem.SPrice < curitem.RPrice) {
                cout << "Brand: " << curitem.Brand << ", SName: " << curitem.SName << ", "
                    << "SPrice: " << curitem.SPrice << ", RPrice: " << curitem.RPrice << ", SSize: " << curitem.SSize << endl;
            }
        }
    }
}

void Hash::PrintList() {
    for (const auto& bucket : SneakersMap) {
        for (const auto& entry : bucket) {
            const SneakerX& curitem = entry.second;
            cout << "Brand: " << curitem.Brand << ", SName: " << curitem.SName << ", "
                << "SPrice: " << curitem.SPrice << ", RPrice: " << curitem.RPrice << ", SSize: " << curitem.SSize << endl;
        }
    }
}

void Hash::PopulateFromCSV(const string& csvfile) {
    ifstream ReadFile(csvfile);
    if (!ReadFile.is_open()) {
        cerr << "Error: Unable to open file " << csvfile << endl;
        return;
    }

    string line, curvalue;
    getline(ReadFile, line); // Throw away the first line (column names)

    while (getline(ReadFile, line)) {
        stringstream ss(line);
        int fielditer = 0;
        SneakerX newrec;
        while (getline(ss, curvalue, ',')) {
            switch (fielditer) {
            case 0: newrec.Brand = curvalue; break;
            case 1: newrec.SName = curvalue; break;
            case 2: newrec.SPrice = stod(curvalue); break;
            case 3: newrec.RPrice = stod(curvalue); break;
            case 4: newrec.SSize = stod(curvalue); break;
            }
            fielditer++;
        }
        PutItem(newrec);
    }
}
