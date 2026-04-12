#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	int k = s.find("AC");
	if (k >= 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}