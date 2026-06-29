#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

class GroceryTracker
{
private:
    // Stores each grocery items and how many items it appears
    map<string, int> itemFrequency;

public:
    // Reads the grocery list and counts each item
    void LoadFile(string fileName);

    // Creates the frequency.dat backup file
    void CreateBackupFile();

    // Returns how many times one item appears
    int SearchItem(string itemName);

    // Prints every item with its frequency
    void PrintFrequencyList();

    // Prints the histogram using *
    void PrintHistogram();
};

#endif