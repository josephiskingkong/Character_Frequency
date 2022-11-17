/***********************************
*                                  *
*          Perelygin Egor          *
*              PI-221              *
*       Character Frequency        *
*                                  *
************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int oneLetterArray[128];
	fstream oneLetterFile;
	char letterIndex;
	
	oneLetterFile.open("Pandas.txt");
	if (!oneLetterFile) {
		cout << "File not found.";
		return 0;
	}
	
	for (int oneLetterIndex = 0; oneLetterIndex < 128; ++oneLetterIndex) {
		oneLetterArray[oneLetterIndex] = 0;
	}
	letterIndex = oneLetterFile.get();
	while (letterIndex != EOF) {
		letterIndex = toupper(letterIndex);
		++oneLetterArray[letterIndex];
		letterIndex = oneLetterFile.get();
	}
	
	cout << "All letters, which repeat in this file: " << endl << "\n";
	for (letterIndex = 'A'; letterIndex <= 'Z'; ++letterIndex) {
		if (oneLetterArray[letterIndex] > 1) {
			cout << letterIndex << " : " << oneLetterArray[letterIndex] << "\n";
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
	
	char firstLetterIndex, secondLetterIndex;
	
	firstLetterIndex = twoLetterFile.get();
	secondLetterIndex = twoLetterFile.get();
	
	while (secondLetterIndex != EOF) {
		firstLetterIndex = toupper(firstLetterIndex);
		secondLetterIndex = toupper(secondLetterIndex);
		++twoLetterArray[firstLetterIndex][secondLetterIndex];
		firstLetterIndex = twoLetterFile.get();
		secondLetterIndex = twoLetterFile.get();
	}
	
	cout << "All double letters, which repeat in this file: " << endl << "\n";
	for (firstLetterIndex = 'A'; firstLetterIndex <= 'Z'; ++firstLetterIndex) {
	    for (secondLetterIndex = 'A'; secondLetterIndex <= 'Z'; ++secondLetterIndex) {
	        if (twoLetterArray[firstLetterIndex][secondLetterIndex] > 1) {
	            cout << firstLetterIndex << secondLetterIndex << " : " << twoLetterArray[firstLetterIndex][secondLetterIndex] << "\n";
	        }
	    }
    }
    system("pause");
} 
