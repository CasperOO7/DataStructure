#include<iostream>
using namespace std;
class Array {
private:
	int size;
	int* arrptr;
	int length;
public:
	Array(int arrsize);
	void fill();
	int get_length();
	int get_size();
	void display();
	int search(int item);
	void Append(int item);
	void insert(int index,int item);
	void del(int index);
	void larger(int newsize);
	void merge(Array otherarr);
};
int main() {
	int size;
	/*int index;*/
	cout << "Enter Array size: ";
	cin >> size;
	Array list1(size);
	list1.fill();
	list1.display();
	cout<<"\t"<<"List length : "<<list1.get_length() << endl;
	cout<< "\t" << "List Size: "<<list1.get_size() << endl;
	//******************************************************************************
	/*index = list1.search(50);
	if (index == -1)
		cout << "Item Not Found! \n";
	else
		cout << "Item Found at index: " << index;*/
	//**********************************************************************************
	/*list1.Append(50);
	list1.display();
	cout << "\t" << "List length after append : " << list1.get_length() << endl;
	cout << "\t" << "List Size after append: " << list1.get_size() << endl;*/
	//***************************************************************************************
	/*list1.insert(2, 30);*/
	/*list1.display();
	cout << "\t" << "List length after insert : " << list1.get_length() << endl;*/
	/*list1.del(1);
	list1.display();
	cout << "\t" << "List length after deletion : " << list1.get_length() << endl;*/
	//*********************************************************************************************
	/*list1.larger(6);
	list1.Append(60);
	list1.display();
	cout << "\t" << "List length after expanding : " << list1.get_length() << endl; 
	cout << "\t" << "List Size after expanding: " << list1.get_size() << endl;*/
	//**********************************************************************************************
	Array list2(5);
	list2.fill();
	list1.merge(list2);
	list1.display();
	cout << "\t" << "List length after merging : " << list1.get_length() << endl;
	cout << "\t" << "List Size after merging: " << list1.get_size() << endl; 
	return 0;
}
Array::Array(int arrsize) {
	size = arrsize;
	length = 0;
	arrptr = new int[arrsize];
}
void Array::fill() {
	int items;
	cout << "Enter number of items: ";
	cin >> items;
	if (items < 0) {
	cout << "Invalid Input!!";
	return;
}
	else
		if (items > size) {
			cout << "Input excced array size!!";
				return;
		}
	else
		for (int i = 0; i < items; i++) {
			cout << "Enter Element No_" << i + 1<<": \n";
			cin >> arrptr[i];
			length++;
		}
}
void Array:: display() {
	cout << "\t" << "Elements of the list: \n" << "********************************************"<<endl;
	for (int i = 0; i < length; i++) {
		cout <<"\t"<< "Element No_" << i + 1 << ": "<< arrptr[i] << " ";
		cout << endl;

	}
	cout << endl;


}
int Array::get_length() {
	return length;
}
int Array::get_size() {
	return size;
}
int Array::search(int item) {
	int index = -1;
	for (int i = 0; i < length; i++) {
	
		if ( arrptr[i]==item )
		{
			index = i;
			break;
		}	
	}
	return index;
}
void Array::Append(int item) {
	if (length == size) {
		cout << "\t" << "List is full cant append \n";
		return;
	}
	else {
		arrptr[length] = item;
		length++;
	}
}
void Array::insert(int index, int item) {
	if (index >= 0 && index < size) {
		for (int i = length; i > index; i--) {
			arrptr[i] = arrptr[i - 1];
		}
		arrptr[index] = item;
		length++;
	}
	else
		cout << "Invalid index! \n";
}
void Array::del(int index) {

	if (index >= 0 && index < size) {
		for (int i = index;i<length-1;i++) 
			arrptr[i] = arrptr[i + 1];
			length--;
	}
	else
		cout << "Invalid index! \n";
}
void Array::larger(int newsize) {
	if (newsize <= size) {
		cout << "Invalid new size, new size must be larger than old size \n";
		return;
	}
	else {
		size = newsize;
		int* newptr = arrptr;
		arrptr = new int[size];
		for (int i = 0; i < length; i++) {
			arrptr[i] = newptr[i];
		}
		delete[]newptr;
	}


}
void Array::merge(Array otherarr) {
	int newsize = size + otherarr.get_size();
	size = newsize;
	int* newptr = arrptr;
	arrptr = new int[newsize];
	int i;
	for (i = 0; i < length; i++)
		arrptr[i] = newptr[i];
	delete[]newptr;
	int j = i;
	for (int i = 0; i < otherarr.get_length(); i++) {
		arrptr[j++] = otherarr.arrptr[i];
		length++;
	}










}


