#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int oneLetterArray[128];
	fstream oneLetterFile;
	char letter;
	
	oneLetterFile.open("Pandas.txt");
	if (!oneLetterFile) {
		cout << "File not found.";
		return 0;
	}
	
	for (int oneLetterIndex = 0; oneLetterIndex < 128; ++oneLetterIndex) {
		oneLetterArray[oneLetterIndex] = 0;
	}
	letter = oneLetterFile.get();
	while (letter != EOF) {
		letter = toupper(letter);
		++oneLetterArray[letter];
		letter = oneLetterFile.get();
	}
	
	cout << "All letters, which repeat in this file: " << endl << "\n";
	for (letter = 'A'; letter <= 'Z'; ++letter) {
		if (oneLetterArray[letter]) {
			cout << letter << " : " << oneLetterArray[letter] << "\n";
		}
	}

    cout << "\n";

	int twoLetterArray[128][128];
	fstream twoLetterFile;
	
	twoLetterFile.open("Pandas.txt");
	if (!twoLetterFile) {
		cout << "File not found.";
		return 0;
	}
	
	for (int firstIndex = 0; firstIndex < 128; ++firstIndex) {
		for (int secondIndex = 0; secondIndex < 128; ++secondIndex) {
		    twoLetterArray[firstIndex][secondIndex] = 0;
		}
	}
	
	char firstLetter, secondLetter;
	
	firstLetter = twoLetterFile.get();
	secondLetter = twoLetterFile.get();
	
	while (secondLetter != EOF) {
		firstLetter = toupper(firstLetter);
		secondLetter = toupper(secondLetter);
		++twoLetterArray[firstLetter][secondLetter];
		firstLetter = twoLetterFile.get();
		secondLetter = twoLetterFile.get();
	}
	
	cout << "All double letters, which repeat in this file: " << endl << "\n";
	for (firstLetter = 'A'; firstLetter <= 'Z'; ++firstLetter) {
	    for (secondLetter = 'A'; secondLetter <= 'Z'; ++secondLetter) {
	        if (twoLetterArray[firstLetter][secondLetter]) {
	            cout << firstLetter << secondLetter << " : " << twoLetterArray[firstLetter][secondLetter] << "\n";
	        }
	    }
    }
} 
