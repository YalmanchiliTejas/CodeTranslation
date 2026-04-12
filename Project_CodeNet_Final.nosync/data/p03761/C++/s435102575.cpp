#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<string>s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	string abc = "abcdefghijklmnopqrstuvwxyz";
	string ans;
	for (int i = 0; i < 26; i++) {
		int cnt = (int)1e9;
		for (int j = 0; j < s.size(); j++) {
			int tmp = count(s[j].begin(), s[j].end(), abc[i]);
			cnt = min(cnt, tmp);
		}
		for (int j = 0; j < cnt; j++) {
			ans += abc[i];
		}
	}
	cout << ans << endl;

	return 0;
}