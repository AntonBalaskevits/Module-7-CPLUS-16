#pragma once

class IntArray
{
	int size_ = 0;
	int* elements_ = nullptr;
public:
	IntArray() = default;
	IntArray(int size);
	~IntArray();

	void setSize();
	int getSize() const;

	void ShowElements();

	void changeElement();

	void erase();

	void removeElement();
	void insertElementBefore();

	int calculateTotal();

	void ShowSpecificElement();

	void currentIntArrayInfo();
};

void operationsInfo();