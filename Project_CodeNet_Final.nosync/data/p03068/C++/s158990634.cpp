#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {
	int n,k;
	string s;
	cin >> n >> s >> k;

	char c = s[k - 1];
	for (int i = 0; i < s.size(); i++) {
		if (c != s[i]) {
			cout << "*";
		}
		else {
			cout << c;
		}
	}
	cout << endl;

	return 0;
}
