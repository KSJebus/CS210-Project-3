#include "GroceryItem.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <map>
#include <iomanip>


void GroceryItem::displayMainMenu() {
	cout << "========================================" << endl;
	cout << "         Corner Grocer Tracking         " << endl;
	cout << "========================================" << endl;
	cout << "[1] Frequency of a SINGLE item" << endl;
	cout << "[2] Frequency of ALL items (Numerically)" << endl << "    Example: Cucumber 3" << endl;
	cout << "[3] Frequency of ALL items (Histogram)" << endl << "    Example: Cucumber ***" << endl;
	cout << "[4] Quit" << endl;
}

int GroceryItem::validMenuOption(int menuChoice) {
	// Checks to make sure input is not invalid
	try {
		cout << "Enter your choice: ";
		cin >> GroceryItem::menuChoice;
		// Creates an infinte loop if not
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			throw runtime_error("Invalid input: Enter a integer between 1, 2, 3, or 4");
		}

		if (GroceryItem::menuChoice < 1 || GroceryItem::menuChoice > 4) {
			throw out_of_range("Number must be between 1 & 4");
		}
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}

}

void GroceryItem::fileManaging() {
	// Opens the input file
	inputFS.open("CS210_Project_Three_Input_File.txt");
	if (!inputFS.is_open()) {
		cout << "Couldn't open 'CS210_Project_Three_Input_File.txt' file" << endl;
	}

	// Opens the output file and checks to make sure it is open
	outputFS.open("Frequency.dat");
	if (!outputFS.is_open()) {
		cout << "Couldn't open 'Frequency.dat' file" << endl;
	}

	// Reads each line(item) and counts each occurence in GroceryList map
	while (getline(inputFS, name)) {
		if (!name.empty()) {
			GroceryList[name]++;
		}
	}

	// Writes the data, in numeric format, into the 'Frequency.dat' file
	for (const auto& pair : GroceryList) {
		outputFS << pair.first << " " << pair.second << endl;
	}
}

void GroceryItem::specificItem() {
	cout << "What item are you looking for?" << endl;
	cin >> tempName;
	
	// Lowercase all letters, then capitalize the first
	transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
	tempName[0] = toupper(tempName[0]);
	
	// Searches the GroceryList map and displays the frequency if found
	if (GroceryList.find(tempName) != GroceryList.end()) {
		cout << tempName << " " << GroceryList[tempName] << endl;
	}
	else {
		cout << tempName << " not found." << endl;
	}
}

void GroceryItem::allItemsNumerically() {
	// Prints all grocery items and their frequency count, in numeric format
	for (const auto& pair : GroceryList) {
		cout << pair.first << " " << pair.second << endl;
	}
}

void GroceryItem::allItemsHistogram() {
	// Prints all items along with a histogram of '*' each representing a single iteration of the item
	cout << "-------------+------------" << endl;
	for (const auto& pair : GroceryList) {
		cout << setw(12) << left << pair.first << " | ";

		for (int i = 1; i <= pair.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
	cout << "-------------+------------" << endl;
}