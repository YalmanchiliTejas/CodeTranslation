#include<iostream>

using namespace std;

int n;
bool a[100002]{ true },r[100002];

bool solve(int k) {
	a[k+1] = !(!(a[k - 1] ^ r[k])^a[k]);
	if (k == n) {
		if (a[0] == a[n] && a[1] == a[n + 1])
			return true;
		else
			return false;
	}
	else
		return solve(k + 1);
}

int main() {
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o')
			r[i+1] = true;
		else
			r[i+1] = false;
	}
	a[0] = true; a[1] = true;
	if (solve(1)) {
		for (int i = 1; i <= n; i++) {
			if (a[i])cout << "S";
			else cout << "W";
		}
		cout << endl;
		return 0;
	}
	a[0] = true; a[1] = false;
	if (solve(1)) {
		for (int i = 1; i <= n; i++) {
			if (a[i])cout << "S";
			else cout << "W";
		}
		cout << endl;
		return 0;
	}
	a[0] = false; a[1] = true;
	if (solve(1)) {
		for (int i = 1; i <= n; i++) {
			if (a[i])cout << "S";
			else cout << "W";
		}
		cout << endl;
		return 0;
	}
	a[0] = false; a[1] = false;
	if (solve(1)) {
		for (int i = 1; i <= n; i++) {
			if (a[i])cout << "S";
			else cout << "W";
		}
		cout << endl;
		return 0;
	}
	else
		cout << -1 << endl;
	return 0;
}