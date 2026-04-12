#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<string>s(n); for (auto&& x : s)cin >> x;
	string ans, abc = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i <abc.size(); i++) {
		int cnt = 1e9;
		for (int j = 0; j < s.size(); j++) {
			int tmp = count(s[j].begin(), s[j].end(), abc[i]);
			cnt = min(cnt, tmp);
		}
		for (int j = 0; j < cnt; j++)ans += abc[i];
	}
	cout << ans << endl;

	return 0;
}