#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> alpha(26, 99999);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;

		vector<int> tmp(26, 0);
		for (char c: s) {
			tmp[c - 'a']++;
		}
		for (int j = 0; j < alpha.size(); j++) {
			alpha[j] = min(alpha[j], tmp[j]);
		}
	}

	string ans;
	for (int i = 0; i < alpha.size(); i++) {
		if (alpha[i] > 0) {
			ans += string(alpha[i], 'a' + i);
		}
	}

	cout << ans << endl;
	return 0;
}
