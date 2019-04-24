// CPPHomework1Again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int DEF_SIZE = 100;

int main(int argc, char* argv[])
{
	vector<vector<double> > sequencesV;
	
	cout << "Main Menu Options\n";
	bool ending = false;
	while (!ending) {
		string option;
		bool isInt = false;
			cout << "Press 1 for adding a new sequence\nPress 2 for listing the existing sequences\nPress 3 for printing a specific sequence and computing max, min, sum, and mean\nPress 9 to exit\n";
			cin >> option;

			if (option == "1") {
				cout << "Adding a new Sequence\n";
				int numOfVals;
				cout << "Enter the number of values you are going to put in this sequence: ";
				cin >> numOfVals;
				while (cin.fail() || numOfVals <=0) {
					cout << "That is not a positive number" << endl;
					cout << "Enter the number of values you are going to put in this sequence: ";
					cin.clear();
					cin.ignore(10000,'\n');
					cin >> numOfVals;
				}
				vector<double> newSeqV(numOfVals);
				for (size_t i = 0; i < numOfVals; i++) {
					
					double valDouble;
					/*
					bool isDouble = false;
					string val;
					while (!isDouble) {
						cin >> val;
						int decimal = 0;
						for (size_t j = 0; j < val.size(); j++) {
							if (!isdigit(val[j])) {
								cout<<"Not a double"<<endl;
								cin.clear();
								cin.ignore(10000, '\n');
								break;
							}
							if (val[j] == '.') {
								decimal++;
							}
							if (decimal > 1) {
								cout << "Incorrect input, only one decimal point allowed in a double" << endl;
								cin.clear();
								cin.ignore(10000, '\n');
								break;
							}
							
						}
						isDouble = true;
					}
					*/
					bool valid = false;
					while (!valid) {
						cout << "Enter value #" << i << ": ";
						if (cin >> newSeqV.at(i))
							valid = true;
						else {
							cout << "Not a properly formatted double" << endl;
							cin.clear();
							cin.ignore(10000,'\n');
						}
					}
					cin.clear();
					cin.ignore(10000, '\n');
				}
				cout << "Vector contents:\n";
				for (size_t i = 0; i < (double)newSeqV.size(); i++) {
					cout << newSeqV.at(i) << endl;
				}
				sequencesV.push_back(newSeqV);
				continue;
			}
			if (option == "2") {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Printing out current sequences: ";
				cout << endl;
				for (size_t i = 0; i < sequencesV.size(); i++) {
					cout << "Sequence #" << i << endl;
					vector<double> element = { sequencesV.at(i) };
					for (size_t i = 0; i < (double)element.size(); i++) {
						cout << element.at(i) << " ";
					}
					cout << endl;
				}
			}
			if (option == "3") {
				
				int seqNum;
				bool valid = false;
				while (!valid) {
					cout << "Enter the number sequence you want to print and compute for ";
					if (cin >> seqNum) {
						if (seqNum < sequencesV.size()) {

							vector<double> selected = { sequencesV.at(seqNum) };
							cout << "Here is the sequence again: " << endl;
							for (size_t i = 0; i < (double)selected.size(); i++) {
								cout << selected.at(i)<< " ";
							}
							cout << " " << endl;
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
								sum = sum + selected.at(i);
							}
							cout << "The sum of the values is: " << sum << endl;
							double mean = sum / ((double)selected.size());
							cout << "The mean is: " << mean << endl;

							valid = true;
						}
						else {
							cout << "There isn't a sequence of that index" << endl;
							cin.clear();
							cin.ignore(1000, '\n');
						}
					}

					else {
						cout << "There isn't a sequence of that index, please enter a positive integer from 0 to " << sequencesV.size() << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
			}
			if (option == "9") {
				cout << "Closing the window now. Thank you!";
				ending = true;
			}
			else if (option != "1" && option != "2" && option != "3" && option != "9"){
				cout << "Not an option that was correctly formatted." << endl;
			}
		
	}
}