#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	const int p = 26;
	vector<vector<int>> num(n, vector<int>(p, 0));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			num[i][s[j] - 'a']++;
		}
	}

	string ans = "";
	for (int j = 0; j < p; j++) {
		int tmpMin = 2147483647;
		for (int i = 0; i < n; i++) {
			tmpMin = min(tmpMin, num[i][j]);
		}
				while (tmpMin--) {
			ans += (char)(j + 'a');
		}
	}

	cout << ans << endl;
	return 0;
}