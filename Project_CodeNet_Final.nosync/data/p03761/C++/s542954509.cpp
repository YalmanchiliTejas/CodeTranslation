#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<string> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	const int p = 26;
	vector<vector<int>> num(n, vector<int>(p, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < c[i].size(); j++) {
			num[i][c[i][j] - 'a']++;
		}
	}
	vector<bool> use(p, true);
	for (int j = 0; j < p; j++) {
		for (int i = 0; i < n; i++) {
			if (num[i][j] == 0) {
				use[j] = false;
			}
		}
	}
	vector<int> extraction(p, 10000);
	for (int j = 0; j < p; j++) {
		if (!use[j]) continue;
		for (int i = 0; i < n; i++) {
			extraction[j] = min(extraction[j], num[i][j]);
		}
	}
	string ans = "";
	for (int j = 0; j < p; j++) {
		int cnt = extraction[j];
		if (cnt == 10000) continue;
		while (cnt--) {
			ans += (char)('a' + j);
		}
	}
	cout << ans << endl;
    return 0;
}