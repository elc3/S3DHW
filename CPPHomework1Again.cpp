// CPPHomework1Again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	double* data;
	Node* link;
};
Node* head = NULL;


int main(int argc, char* argv[])
{
	double sequences[5];
	vector<vector<double> > sequencesV;
	
	cout << "Main Menu Options\n";
	bool ending = false;
	while (!ending) {
		cout << "Press 1 for adding a new sequence\nPress 2 for listing the existing sequences\nPress 3 for printing a specific sequence and computing max, min, sum, and mean\nPress 9 to exit\n";
		int option;
		cin >> option;
		if(option ==1){
				cout << "Adding a new Sequence\n";
				int numOfVals;
				cout << "Enter the number of values you are going to put in this sequence: ";
				cin >> numOfVals;
				/*
				double* newSeq = new double[numOfVals];//an array of pointers
				for (size_t i = 0; i < numOfVals; i++) {
					cout << "Enter the " << i << " value: ";
					cin >> newSeq[i];
				}
				cout << "The new sequence is: ";
				for (size_t i = 0; i < numOfVals; i++) {
					cout << newSeq[i] << " ";
				}
				cout << endl;
				*/
				vector<double> newSeqV(numOfVals);
				for (size_t i = 0;i< numOfVals; i++) {
					cout << "Enter value #" << i <<": ";
					cin >> newSeqV.at(i);
				}
				cout << "Vector contents:\n";
				for (size_t i = 0; i < (double)newSeqV.size(); i++) {
					cout << newSeqV.at(i) << endl;
				}
				sequencesV.push_back(newSeqV);
				

			/*
			Node* ptr = new Node();
			ptr->data = newSeq;
			ptr->link = NULL;
			if (head == NULL) {
				head = ptr;
			}
			*/
		}
		if (option == 2) {
			cout << "Printing out current sequences: ";
			cout << endl;
			for (size_t i = 0; i < sequencesV.size(); i++){
				cout << "Sequence #" << i << endl;
				vector<double> element = { sequencesV.at(i) };
				for (size_t i = 0; i < (double)element.size(); i++) {
					cout << element.at(i)<<endl;
				}
			}
		}
		else if(option != 1 && option != 2 && option != 3 ){
			ending = true;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
