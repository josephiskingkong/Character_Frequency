#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int OneLetterArray[128];
	fstream OneLetterFile;
	char Letter;
	
	OneLetterFile.open("Pandas.txt");
	if (!OneLetterFile) {
		cout << "File not found.";
		return 0;
	}
	
	for (int OneLetterIndex = 0; OneLetterIndex < 128; ++OneLetterIndex) {
		OneLetterArray[OneLetterIndex] = 0;
	}
	Letter = OneLetterFile.get();
	while (Letter != EOF) {
		Letter = toupper(Letter);
		++OneLetterArray[Letter];
		Letter = OneLetterFile.get();
	}
	
	cout << "All letters, which repeat in this file: " << endl << "\n";
	for (Letter = 'A'; Letter <= 'Z'; ++Letter) {
		if (OneLetterArray[Letter]) {
			cout << Letter << " : " << OneLetterArray[Letter] << "\n";
		}
	}

    cout << "\n";

	int TwoLetterArray[128][128];
	fstream TwoLetterFile;
	
	TwoLetterFile.open("Pandas.txt");
	if (!TwoLetterFile) {
		cout << "File not found.";
		return 0;
	}
	
	for (int FirstIndex = 0; FirstIndex < 128; ++FirstIndex) {
		for (int SecondIndex = 0; SecondIndex < 128; ++SecondIndex) {
		    TwoLetterArray[FirstIndex][SecondIndex] = 0;
		}
	}
	
	char FirstLetter, SecondLetter;
	
	FirstLetter = TwoLetterFile.get();
	SecondLetter = TwoLetterFile.get();
	
	while (SecondLetter != EOF) {
		FirstLetter = toupper(FirstLetter);
		SecondLetter = toupper(SecondLetter);
		++TwoLetterArray[FirstLetter][SecondLetter];
		FirstLetter = TwoLetterFile.get();
		SecondLetter = TwoLetterFile.get();
	}
	
	cout << "All double letters, which repeat in this file: " << endl << "\n";
	for (FirstLetter = 'A'; FirstLetter <= 'Z'; ++FirstLetter) {
	    for (SecondLetter = 'A'; SecondLetter <= 'Z'; ++SecondLetter) {
	        if (TwoLetterArray[FirstLetter][SecondLetter]) {
	            cout << FirstLetter << SecondLetter << " : " << TwoLetterArray[FirstLetter][SecondLetter] << "\n";
	        }
	    }
    }
} 
