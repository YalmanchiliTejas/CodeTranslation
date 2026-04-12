#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	bool ans = false;
	vector<char> vec;
	for (int i = 0; i < 3; i++) {
		char c;
		cin >> c;
		vec.push_back(c);
	}
	for (int i = 1; i < 3; i++) {
		if (vec.at(i) != vec.at(i - 1)) {
			ans = true;
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}