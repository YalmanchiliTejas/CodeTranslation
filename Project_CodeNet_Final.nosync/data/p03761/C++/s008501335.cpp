#include <bits/stdc++.h>

using namespace std;

int f[55][26];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int m = (int)str.size();
		for (int j = 0; j < m; j++) {
			f[i][str[j] - 'a']++;
		}	
	}
	string ans = "";	
	for (int i = 0; i < 26; i++) {
		int cur = f[0][i];
		for (int j = 1; j < n; j++) {
			cur = min(cur, f[j][i]);
		}

		while (cur > 0) {
			ans += (char)('a' + i);
			cur--;
		}
	}
	cout << ans << endl;
	return 0;
}