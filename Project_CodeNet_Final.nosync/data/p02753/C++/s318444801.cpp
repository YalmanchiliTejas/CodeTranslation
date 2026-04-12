#include<stdio.h>
#include <iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	string str;

	cin >> str;

	for (int i = 0; i < 2; i++) {
		if (str.at(i) != str.at(i + 1)) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

	return 0;
}