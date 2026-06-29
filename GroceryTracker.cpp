#include "GroceryTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

void GroceryTracker::LoadFile(string fileName) {
    ifstream inputFile;
    string itemName;

    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        cout << "Error: Could not open the input file." << endl;
        return;
    }

    while (inputFile >> itemName) {
        itemFrequency[itemName]++;
    }

    inputFile.close();
}

void GroceryTracker::CreateBackupFile() {
    ofstream outputFile;

    outputFile.open("frequency.dat");

    if (!outputFile.is_open()) {
        cout << "Error: Could not create frequency.dat." << endl;
        return;
    }

    for (auto item : itemFrequency) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
}

int GroceryTracker::SearchItem(string itemName) {
    if (itemFrequency.count(itemName) > 0) {
        return itemFrequency[itemName];
    }

    return 0;
}

void GroceryTracker::PrintFrequencyList() {
    for (auto item : itemFrequency) {
        cout << item.first << " " << item.second << endl;
    }
}

void GroceryTracker::PrintHistogram() {
    for (auto item : itemFrequency) {
        cout << item.first << " ";

        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }

        cout << endl;
    }
}