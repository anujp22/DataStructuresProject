#pragma once
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
struct SneakerX {
    string Brand;       // Brand   Name
    string SName;       // Sneaker Name
    double SPrice;      // Selling Price
    double RPrice;      // Retail  Price
    double SSize;       // Shoe    Size
};

struct MyPairHash {
    size_t operator()(const pair<string, string>& pair) const {
        return hash<string>{}(pair.first) ^ hash<string>{}(pair.second);
    }
};

class Hash {
public:
    Hash(); // Constructor

    void PutItem(SneakerX item);                     // Adds the item to the table
    void PopulateFromCSV(const string& csvfile); // Reading the values from the csv file into the hashtable 
    void DisplaySneakersInPriceRange(double minPrice, double maxPrice); // Display shoes in the given price range
    void DisplayDiscountedItems();                   // Display discounted price sneakers
    void PrintList();                                // Print all elements of the hashtable

private:
    int length;
    vector<vector<pair<string, SneakerX>>> SneakersMap;
};
