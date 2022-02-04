#include <iostream>
#include "IntArray.h"

int main()
{
	IntArray arr;      // default container object

	int operation = 0; // variable for operations choice
	bool on = true;    // main while loop condition variable

	std::cout << "        *Welcome to IntegerArray 1.0!*" << std::endl;

	while (on)
	{
		arr.currentIntArrayInfo(); // displays current information to the user at all times
		operationsInfo();          // shows operation choices available
		
		std::cout << "enter Your choice here     : ";
		std::cin >> operation;

		switch (operation)
		{
		case 1: // sets size of intArray object

			try { arr.setSize(); } // if size input is less then zero exception caught
			catch (const char* exception) { std::cout << exception << std::endl; }
			break;

		case 2: // shows chosen element from the array

			try { arr.ShowSpecificElement(); } // if user tries to access a non-existing element
			catch (const char* exception) { std::cout << exception << std::endl; }
			break;

		case 3: // choice to change specific element from the array

			try { arr.changeElement(); }  // if user tries to access a non-existing element
			catch (const char* exception) { std::cout << exception << std::endl; }
			break;

		case 4: // removes chosen element from the array

			try { arr.removeElement(); } // if user tries to access a non-existing element
			catch (const char* exception) { std::cout << exception << std::endl; }
			break;

		case 5: // inserts new element in to the array before existing one
		
			try { arr.insertElementBefore(); } // if user tries to access a non-existing element
			catch (const char* exception) { std::cout << exception << std::endl; }
			break;

		case 0: 
			on = false;
			break;

		default: // wrong input check
			std::cout << "You made an illegal choice. Please try again." << std::endl;
			on = true;
			break;
		}
	}

	std::cout << "\n"; // fare well message :)
	std::cout << "Thank u for using IntegerArray 1.0 see u next time:) " << std::endl;

	return 0;
}