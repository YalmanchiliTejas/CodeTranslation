#include "bits/stdc++.h"

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> s(n);

	for (auto &x : s) {
		cin >> x;
	}

	vector<vector<int>> a(26, vector<int>(s.size()));

	for (int j = 0; j < s.size(); j++){
		for (int i = 0; i < s[j].size(); i++) {
			a[s[j][i] - 'a'][j]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < *min_element(a[i].begin(),a[i].end()); j++) {
			cout << (char)('a' + i);
		}
	}
	cout << endl;

	return 0;
}