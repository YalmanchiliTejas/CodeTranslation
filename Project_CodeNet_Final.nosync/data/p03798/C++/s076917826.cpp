#include <bits/stdc++.h>
using namespace std;

int n;
string s;
char ans[100005];

void check() {
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			if (ans[i] == 'S') {
				if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'S') {
					ans[(i-1 + n) % n] = 'S';
				}
				else if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'W') {
					ans[(i-1 + n) % n] = 'W';
				}
				else if (ans[(i-1 + n) % n] == 'S' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'S';
				}
				else if (ans[(i-1 + n) % n] == 'W' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'W';
				}
			}
			else {
				if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'S') {
					ans[(i-1 + n) % n] = 'W';
				}
				else if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'W') {
					ans[(i-1 + n) % n] = 'S';
				}
				else if (ans[(i-1 + n) % n] == 'S' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'W';
				}
				else if (ans[(i-1 + n) % n] == 'W' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'S';
				}
			}
		}
		else {
			if (ans[i] == 'S') {
				if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'S') {
					ans[(i-1 + n) % n] = 'W';
				}
				else if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'W') {
					ans[(i-1 + n) % n] = 'S';
				}
				else if (ans[(i-1 + n) % n] == 'S' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'W';
				}
				else if (ans[(i-1 + n) % n] == 'W' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'S';
				}
			}
			else {
				if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'S') {
					ans[(i-1 + n) % n] = 'S';
				}
				else if (ans[(i-1 + n) % n] == '-' && ans[(i+1) % n] == 'W') {
					ans[(i-1 + n) % n] = 'W';
				}
				else if (ans[(i-1 + n) % n] == 'S' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'S';
				}
				else if (ans[(i-1 + n) % n] == 'W' && ans[(i+1) % n] == '-') {
					ans[(i+1) % n] = 'W';
				}
			}
		}
	}

	bool valid = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			if (ans[i] == 'S' && ans[(i-1 + n) % n] != ans[(i+1) % n]) {
				valid = 0;
			}
			else if (ans[i] == 'W' && ans[(i-1 + n) % n] == ans[(i+1) % n]) {
				valid = 0;
			}
		}
		else if (s[i] == 'x') {
			if (ans[i] == 'S' && ans[(i-1 + n) % n] == ans[(i+1) % n]) {
				valid = 0;
			}
			else if (ans[i] == 'W' && ans[(i-1 + n) % n] != ans[(i+1) % n]) {
				valid = 0;
			}
		}
	}

	if (valid) {
		for (int i = 0; i < n; i++) {
			cout << ans[i];
		}
		cout << '\n';
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'S';
	ans[1] = 'S';
	ans[n-1] = 'S';
	check();

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'S';
	ans[1] = 'W';
	ans[n-1] = 'S';
	check();

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'S';
	ans[1] = 'S';
	ans[n-1] = 'W';
	check();

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'S';
	ans[1] = 'W';
	ans[n-1] = 'W';
	check();

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'W';
	ans[1] = 'W';
	ans[n-1] = 'W';
	check();

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'W';
	ans[1] = 'S';
	ans[n-1] = 'W';
	check();

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'W';
	ans[1] = 'W';
	ans[n-1] = 'S';
	check();

	for (int i = 0; i < n; i++) {
		ans[i] = '-';
	}

	ans[0] = 'W';
	ans[1] = 'S';
	ans[n-1] = 'S';
	check();

	cout << "-1\n";
	
	return 0;
}