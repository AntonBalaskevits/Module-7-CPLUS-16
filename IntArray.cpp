#include <iostream>
#include "IntArray.h"

IntArray::IntArray(int size) : size_(size) {}

IntArray::~IntArray() { delete[] elements_; }

void IntArray::setSize()
{
	erase();
	int size = 0;
	std::cout << "enter size value here      : ";
	std::cin >> size;

	if (size <= 0)
	{
		throw "Set Size ERROR: input value can not be less the ZERO!";
	}
	else
	{
		size_ = size;
		elements_ = new int[size];
	}
	for (int i = 0; i < size_; ++i)
	{
		elements_[i] = i + 1;
	}
}

int IntArray::getSize() const
{
	return size_;
}

void IntArray::ShowElements()
{
	for (int i = 0; i < size_; ++i)
	{
			std::cout << elements_[i] << " ";
	}
	std::cout << std::endl;
}

void IntArray::changeElement()
{
	int index = 0;
	int value = 0;
	std::cout << "enter position value here  : ";
	std::cin >> index;
	std::cout << "enter new value here       : ";
	std::cin >> value;
	if (index < 0 || index >= size_)
	{
		throw "Change Element ERROR: input value is out of range!";
	}
	else
	{
		elements_[index] = value;
	}
} 

void IntArray::erase()
{
	delete[] elements_;
	size_ = 0;
	elements_ = nullptr;
}

void IntArray::removeElement()
{
	int index = 0;
	std::cout << "enter position value here  : ";
	std::cin >> index;

	if (index < 0 || index >= size_)
	{
		throw "Remove Element ERROR: input value is out of range!";
	}
	else if (size_ == 1)
	{
		erase();
		return;
	}
	else
	{
		int* elements = new int[size_ - 1];

		for (int i = 0; i < index; ++i)
		{
			elements[i] = elements_[i];
		}
		for (int i = index + 1; i < size_; ++i)
		{
			elements[i - 1] = elements_[i];
		}

		delete[] elements_;
		elements_ = elements;
		--size_;
	}
}

void IntArray::insertElementBefore()
{
	int index = 0;
	int value = 0;

	std::cout << "enter position value here  : ";
	std::cin >> index;
	std::cout << "enter element value here   : ";
	std::cin >> value;

	if (index < 0 || index >= size_)
	{
		throw "Insert Element ERROR: input value is out of range!";
	}
	else
	{
		int* elements = new int[size_ + 1];

		for (int i = 0; i < index; ++i)
		{
			elements[i] = elements_[i];
		}
		elements[index] = value;
		for (int i = index; i < size_; ++i)
		{
			elements[i + 1] = elements_[i];
		}

		delete[] elements_;
		elements_ = elements;
		++size_;
	}
}

int IntArray::calculateTotal()
{
	int sum = 0;

	for (int i = 0; i < size_; ++i)
	{
		sum += elements_[i];
	}

	return sum;
}

void IntArray::ShowSpecificElement()
{
	int index;
	std::cout << "enter position value here  : ";
	std::cin >> index;

	if (index < 0 || index >= size_)
	{
		throw "display specific element ERROR: the input value is out of range!";
	}
	else
	{
		std::cout << "element at the position -> " << index << " is " << elements_[index] << std::endl;
	}
}

void IntArray::currentIntArrayInfo()
{
	std::cout << "\n";
	std::cout << "                *current INFO!*" << std::endl;
	std::cout << "current number of elements in the array is    : " << size_ << std::endl;
	std::cout << "current total of all elements in the array is : " << IntArray::calculateTotal() << std::endl;
	std::cout << "\n";
	if (IntArray::getSize() == 0)
	{
		std::cout << "current list of elements is EMPTY!" << std::endl;
	}
	else
	{
		IntArray::ShowElements();
	}
	std::cout << "\n";
	std::cout << "^current elements listed right above the string^ " << std::endl;
	std::cout << "\n";
}


void operationsInfo()
{
	std::cout << "\n";
	std::cout << "               *operations list*" << std::endl;
	std::cout << "to set Size press............................(1)" << std::endl; 
	std::cout << "to display specific Element press............(2)" << std::endl; 
	std::cout << "to change specific Element press.............(3)" << std::endl; 
	std::cout << "to remove Element press......................(4)" << std::endl; 
	std::cout << "to insert new Element press..................(5)" << std::endl;
	std::cout << "to Quit press................................(0)" << std::endl;
	std::cout << "\n";
}
