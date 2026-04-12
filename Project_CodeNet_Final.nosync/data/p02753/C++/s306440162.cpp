#include<iostream>
#include<string>
using namespace std;

int main() {
	string station;
	cin >> station;
	if (station.at(0) == 'A') {
		for (int i = 1; i < 3; i++) {
			if (station.at(i) == 'B') {
				cout << "Yes" << endl;
				break;
			}
			else if(i == 2) {
				cout << "No" << endl;
				break;
			}
		}
	}
	if (station.at(0) == 'B') {
		for (int j = 1; j < 3; j++) {
			if (station.at(j) == 'A') {
				cout << "Yes" << endl;
				break;
			}
			else if(j == 2){
				cout << "No" << endl;
				break;
			}
		}
	}
}