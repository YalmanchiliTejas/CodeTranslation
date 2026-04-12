#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool isreturn = false;
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == 'A' && s.at(i + 1) == 'C') {
			isreturn = true;
			break;
		}
	}
	if (isreturn == true) cout << "Yes" << endl;
	else cout << "No" << endl;
}