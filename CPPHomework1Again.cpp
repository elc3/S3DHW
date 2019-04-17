// CPPHomework1Again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
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
		}
		if (option == 2) {
			cout << "Printing out current sequences: ";
			cout << endl;
			for (size_t i = 0; i < sequencesV.size(); i++){
				cout << "Sequence #" << i << endl;
				vector<double> element = { sequencesV.at(i) };
				for (size_t i = 0; i < (double)element.size(); i++) {
					cout << element.at(i)<<" ";
				}
				cout << endl;
			}
		}
		if (option == 3) {
			cout << "Enter the number sequence you want to print and compute for";
			int seqNum;
			cin >> seqNum;
			if (seqNum <= sequencesV.size()) {
				vector<double> selected = { sequencesV.at(seqNum) };
				cout << "Here is the sequence again: " << endl;
				for (size_t i = 0; i < (double)selected.size(); i++) {
					cout << selected.at(i);
				}
				//find the minimum
				double min = selected.at(0);//asssume its the first
				for (size_t i = 0; i < (double)selected.size(); i++) {
					if (selected.at(i) <= min)
						min = selected.at(i);
				}
				cout << "The minimum value is: " << min << endl;
				//find the max
				double max = selected.at(0);//again assume its the first
				for (size_t i = 0; i < (double)selected.size(); i++) {
					if (selected.at(i) >= max) {
						max = selected.at(i);
					}
				}
				cout << "The maximum value is: " << max << endl;
				double sum = 0;
				for (size_t i = 0; i < (double)selected.size(); i++) {
					sum = sum+selected.at(i);
				}
				cout << "The sum of the values is: " << sum << endl;
				double mean = sum / ((double)selected.size());
				cout << "The mean is: " << mean << endl;
			}
			else {
				cout << "There isn't a sequence of that index" << endl;
			}
		}
		else if(option != 1 && option != 2 && option != 3 ){
			cout << "Closing the window now.";
			ending = true;
		}
	}
}