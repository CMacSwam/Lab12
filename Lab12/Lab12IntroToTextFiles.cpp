#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
void pressEnterToContinue();
bool readFromFile(string filename);
bool readFromCSVFile(string filename);

int main() {
	cout << "Lab 12 Intro to Text Files!\n";

	string datafile;
	char separator;
	string ext;
	cout << "Enter filename: ";
	cin >> datafile >> separator >> ext;
	string file = datafile + separator + ext;

	cout << file << endl;
	bool status = readFromCSVFile(file);
	if (status) cout << "Success!\n";
	else cout << "failure. :-(\n";
	pressEnterToContinue();
}

void pressEnterToContinue() {
	cout << "\nPress enter to continue...\n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

bool readFromFile(string filename) {
	ifstream inFile;
	string movieTitle;
	int year;
	inFile.open(filename);

	if (inFile.fail()) {
		cout << "read error - sorry\n";
		return false;
	}

	while (true) {
		inFile >> movieTitle >> year;
		if (inFile.fail()) break;

		cout << movieTitle << ": " << year << endl;
	}

	inFile.close();
	return true;
}

bool readFromCSVFile(string filename) {
	ifstream inFile;
	istringstream thisLine;
	string movieInfo;
	string movieTitle;
	string year;
	string director;
	cout << "check3";
	inFile.open(filename);
	if (inFile.fail()) {
		cout << "read error sorry \n";
		return false;
	}
	cout << "check1" << endl;
	while (true) {
		getline(inFile, movieInfo);
		if (inFile.fail()) break;
		thisLine.clear();
		thisLine.str(movieInfo);
		getline(thisLine, movieTitle, ',');
		getline(thisLine, year, ',');

		vector<string> directorList;
		string dir;
		while (getline(thisLine, dir, ',')) {
			directorList.push_back(dir);
		}
		cout << "check2";
		director = directorList[0];
		for (int i = 1; i < directorList.size(); i++) {
			director = director + "and " + directorList[i];
		}

		cout << movieTitle << " is a " << year << " film directed by " << director << endl;
	}

	inFile.close();
	return true;

}