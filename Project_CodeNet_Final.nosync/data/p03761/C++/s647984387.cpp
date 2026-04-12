#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	vector<int> cnt(26, 1234567);
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		vector<int> tmp(26);
		for(int i = 0; i < s.size(); i++) {
			tmp[s[i] - 'a']++;
		}
		for(int i = 0; i < 26; i++) {
			cnt[i] = min(cnt[i], tmp[i]);
		}
	}
	string ans;
		for(int i = 0; i < 26; i++) {
			cerr << cnt[i] << endl;
		}
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < cnt[i]; j++) {
			ans += 'a' + i;
		}
	}
	cout << ans << endl;
	return 0;
}