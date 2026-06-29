#include <iostream>
#include <string>
#include "GroceryTracker.h"

using namespace std;

// Prints the menu choices for the user
void PrintMenu() {
    cout << endl;
    cout << "Corner Grocer Item Tracker" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print item histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker;
    int userChoice = 0;
    string itemName;

    // Loads all of the grocery data and creates the backup file immediately!
    tracker.LoadFile("CS210_Project_Three_Input_File.txt");
    tracker.CreateBackupFile();

    while (userChoice != 4) {
        PrintMenu();

        if (!(cin >> userChoice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (userChoice == 1) {
            cout << "Enter item name: ";
            cin >> itemName;

            cout << itemName << " was purchased "
                << tracker.SearchItem(itemName)
                << " time(s)." << endl;
        }
        else if (userChoice == 2) {
            tracker.PrintFrequencyList();
        }
        else if (userChoice == 3) {
            tracker.PrintHistogram();
        }
        else if (userChoice == 4) {
            cout << "Exiting program." << endl;
        }
        else {
            cout << "Invalid option. Please enter 1, 2, 3, or 4." << endl;
        }
    }

    return 0;
}