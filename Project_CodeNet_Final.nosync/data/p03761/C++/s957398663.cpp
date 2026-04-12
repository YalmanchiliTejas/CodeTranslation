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
	vector<int> minCnt(p, 0);
	for (int j = 0; j < p; j++) {
		int tmp = 2147483647;
		for (int i = 0; i < n; i++) {
			tmp = min(tmp, num[i][j]);
		}
		minCnt[j] = tmp;
	}
	string ans = "";
	for (int i = 0; i < p; i++) {
		int cnt = minCnt[i];
		while (cnt--) {
			ans += 'a' + i;
		}
	}	
	cout << ans << endl;
	return 0;
}