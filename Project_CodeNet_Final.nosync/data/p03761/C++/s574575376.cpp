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
	vector<int> ans(p, 1000);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < n; j++) {
			ans[i] = min(ans[i], num[j][i]);
		}
	}
	string res = "";
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < ans[i]; j++) {
			string tmp{ (char)(i + 'a') };
			res += tmp;
		}		
	}
	cout << res << endl;
	return 0;
}