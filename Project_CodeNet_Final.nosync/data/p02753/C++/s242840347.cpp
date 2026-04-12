#include<iostream>
using namespace std;

int main() {
	string S;
	cin >> S;

	if (S == "AAB" || S == "ABA" || S == "BAA" ||
		S == "ABB" || S == "BAB" || S == "BBA") {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}