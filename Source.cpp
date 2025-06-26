#include <string>
#include <iostream>
#include "GroceryItem.h"
using namespace std;

int main() {
	GroceryItem grocer;

	// Loop until user exits the program
	do {
		// Load and updates the latest grocery data to make sure the data is up to date
		grocer.fileManaging();

		grocer.displayMainMenu();
		
		grocer.validMenuOption(grocer.menuChoice);
		
		switch (grocer.menuChoice) {
		case 1:
			grocer.specificItem();
			break;
		case 2:
			grocer.allItemsNumerically();
			break;
		case 3:
			grocer.allItemsHistogram();
			break;
		default:
			break;
		}

		// Cleans up before next loop iteration
		grocer.inputFS.close();
		grocer.outputFS.close();
		grocer.GroceryList.clear();
	} while (grocer.menuChoice != 4);
	
	cout << "Goodbye" << endl;
	return 0;
}