#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int n;
bool b[100010];
char s[100010];
bool ans;

void dfs(int pos, bool ani) {
	if (pos == n + 1) {
		bool ans1, ans2;
		if (s[n] == 'o') {
			if (b[n]) {
				if (b[n - 1] == b[1]) {
					ans1 = true;
				}
				else {
					ans1 = false;
				}
			}
			else {
				if (b[n - 1] == b[1]) {
					ans1 = false;
				}
				else {
					ans1 = true;
				}
			}
		}
		else {
			if (b[n]) {
				if (b[n - 1] == b[1]) {
					ans1 = false;
				}
				else {
					ans1 = true;
				}
			}
			else {
				if (b[n - 1] == b[1]) {
					ans1 = true;
				}
				else {
					ans1 = false;
				}
			}
		}
		if (s[1] == 'o') {
			if (b[1]) {
				if (b[n] == b[2]) {
					ans2 = true;
				}
				else {
					ans2 = false;
				}
			}
			else {
				if (b[n] == b[2]) {
					ans2 = false;
				}
				else {
					ans2 = true;
				}
			}
		}
		else {
			if (b[1]) {
				if (b[n] == b[2]) {
					ans2 = false;
				}
				else {
					ans2 = true;
				}
			}
			else {
				if (b[n] == b[2]) {
					ans2 = true;
				}
				else {
					ans2 = false;
				}
			}
		}
		if (ans1 && ans2) {
			for (int i = 1; i <= n; ++i) {
				cout << (b[i] ? 'S' : 'W');
			}
			cout << endl;
			exit(0);
		}
		else {
			return;
		}
	}

	b[pos] = ani;

	if (pos == 1) {
		dfs(pos + 1, false);
		dfs(pos + 1, true);
	}

	if (ani) {
		if (s[pos] == 'o') {
			dfs(pos + 1, b[pos - 1]);
		}
		else {
			dfs(pos + 1, !b[pos - 1]);
		}
	}
	else {
		if (s[pos] == 'o') {
			dfs(pos + 1, !b[pos - 1]);
		}
		else {
			dfs(pos + 1, b[pos - 1]);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < 2; ++i) {
		fill(b, b + n + 10, false);
		dfs(1, i);
	}
	cout << -1 << endl;

	return 0;
}