#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string s;

bool check(string& ans) {
	for (int i = 1; i < N;i++) {
		if (s[i] == 'o') {
			if(ans[i] == 'S')ans += ans[i - 1];
			else{
				if (ans[i - 1] == 'S') ans += 'W';
				else ans += 'S';
			}
		}
		else {
			if (ans[i] == 'S') {
				if (ans[i - 1] == 'S') ans += 'W';
				else ans += 'S';
			}
			else {
				ans += ans[i - 1];
			}
		}
	}
	if (ans[0] == ans[N]) {
		if (s[0] == 'o') {
			if (ans[0] == 'S') {
				if (ans[1] == ans[N - 1]) return true;
			}
			else {
				if (ans[1] != ans[N - 1]) return true;
			}
		}
		else {
			if (ans[0] == 'S') {
				if (ans[1] != ans[N - 1]) return true;
			}
			else {
				if (ans[1] == ans[N - 1]) return true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N >> s;
	string ans;
	ans = "SS";
	if (check(ans)) { cout << ans.substr(0,N) << endl; return 0; }
	ans = "SW";
	if (check(ans)) { cout << ans.substr(0, N) << endl; return 0; }
	ans = "WW";
	if (check(ans)) { cout << ans.substr(0, N) << endl; return 0; }
	ans = "WS";
	if (check(ans)) { cout << ans.substr(0, N) << endl; return 0; }
	cout << -1 << endl;
}