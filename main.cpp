/*
Project 3
SNHU CS210
Joe Emrick
08/13/2023
*/
#include <iostream>
#include <fstream>
#include <map>
#include "GroceryItem.h"


// Function to read an inventory from a file and return it as a map.
std::map<std::string, int> readInventory()
{
    std::map<std::string, int> items;
    std::ifstream file("inventory.txt");
    std::string name;

    while (std::getline(file, name))
    {
        items[name]++;
    }

    file.close();

    return items;
}

void backupInventory(const std::map<std::string, int>& items)
{
    // Create the frequency.dat file for writing.
    std::ofstream outfile("frequency.dat");

    // Loop through the map and write each item and its frequency to the file.
    for (const auto& item : items)
    {
        outfile << item.first << " " << item.second << "\n";
    }
    outfile.close();
}


int main()
{
    int userInput = 0;
    // Read the inventory from a file and store it in a map where keys are item names and values are their quantities.
    std::map<std::string, int> items = readInventory();

    // Loop for user input
    while (userInput != 4) {
        std::cout << "Please make a selection \n";
        std::cout << "1. Search for an item \n" << "2. Display all frequencies \n" << "3. Print histogram \n" << "4. Exit \n";
        std::cin >> userInput;
     
        if (userInput == 1) {
            // Prompt user for a specific item
            std::cout << "Enter the name of the item you wish to look for: ";
            std::string inputItem;
            std::cin >> inputItem;
            if (items.find(inputItem) != items.end())
            {
                std::cout << inputItem << " appears " << items[inputItem] << " times.\n";
            }
            else
            {
                std::cout << inputItem << " does not appear in the inventory.\n";
            }
        }

        else if (userInput == 2) {
            // Print frequency of all items
            std::cout << "\nFrequency of all items purchased:\n";
            for (const auto& item : items)
            {
                std::cout << item.first << ": " << item.second << "\n";
            }
        }

        else if (userInput == 3) {
            // Print histogram
            std::cout << "\nHistogram:\n";
            for (const auto& item : items)
            {
                std::cout << item.first << ": ";
                for (int i = 0; i < item.second; ++i)
                {
                    std::cout << "*";
                }
                std::cout << "\n";
            }
        }
        // Check for exit input 
        else if (userInput == 4) {
            // Backup the inventory before exiting
            backupInventory(items);
            std::cout << "Goodbye!";
        }
        // Input validation for selection
        else {
            std::cout << "Please enter a valid selection. \n";
        }
    }
        return 0;
}