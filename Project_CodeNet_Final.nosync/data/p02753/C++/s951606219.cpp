#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	for (int i = 1; i < str.size(); i++) {
		if (str[i - 1] != str[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}