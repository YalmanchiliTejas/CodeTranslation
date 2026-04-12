#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string S;
	
	cin >> S;
	if (S.find("AC") != string::npos) {
		cout << "Yes";
	}else {
		cout << "No";
	}

	return 0;
}