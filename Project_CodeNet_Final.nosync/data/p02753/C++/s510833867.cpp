#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cou = 0;

	for (int i = 0; i < 3; i++) {
		if (s[i] == 'A') {
			cou++;
		}
	}

	if (cou == 3 || cou == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}
