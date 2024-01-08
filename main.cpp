#include "Hash.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    Hash map1;
    map1.PopulateFromCSV("ModifiedDS.csv");
    cout << "Welcome to the Program" << endl;

    double x1, x2;
    cout << "Please enter the price range in which you want to find sneakers" << endl;
    cout << "This is the lower bound and the minimum you can enter is $315" << endl;
    while (!(cin >> x1) || x1 < 315) {
        cout << "Invalid input. Please enter a valid price (minimum $315): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "This is the upper bound and the maximum you can enter is $1490" << endl;
    while (!(cin >> x2) || x2 > 1490) {
        cout << "Invalid input. Please enter a valid price (maximum $1490): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    map1.DisplaySneakersInPriceRange(x1, x2);

    char c1;
    bool validInput = false;

    while (!validInput) {
        cout << "If you want to display discounted sneakers, press Y else press N to exit: ";
        cin >> c1;

        // Check for valid input (Y, y, or anything else)
        if (c1 == 'Y' || c1 == 'y') {
            validInput = true;
            map1.DisplayDiscountedItems();
        }
        else if(c1 == 'N' || c1 == 'n') {
            break;
        }
        else {
            cout << "Invalid input. Please enter Y or y to continue" << endl;
        }
    }

    cout << "Thank you for using the program." << endl;

    return 0;
}
