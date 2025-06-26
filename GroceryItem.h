#ifndef GROCERYITEM_H
#define GROCERYITEM_H
#include <string>
#include <fstream>
#include <map>
using namespace std;


/*
* Handles reading grocery data from a file, calculating item frequencies, and shows the data to the user
* through various options (numeric, histogram, and specific item)
*/
class GroceryItem
{
public:

	int menuChoice;
	ifstream inputFS;
	ofstream outputFS;
	map<string, int> GroceryList;

	// Displays the main menu options to the user
	void displayMainMenu();

	// Prompt and validate the user's menu choice (1 to 4)
	int validMenuOption(int menuChoice);

	// Read items from the input file and build a frequency map
	void fileManaging();

	// Prompt the user for an item and display its purchase frequency
	void specificItem();

	// Display all items and their frequencies in numeric format
	void allItemsNumerically();

	// Display a histogram of item frequencies using asterisks (*)
	void allItemsHistogram();

private:
	string name;
	string tempName;
	int quantity;

};

#endif

