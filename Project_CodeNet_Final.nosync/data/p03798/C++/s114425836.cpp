#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int n;
string s, t;

string f(string t) {
	int a = 0;
	for (int i = 1; i < n - 1; i++) {
		if (t[i] == 'S') {
			if (s[i] == 'o') {
				t += t[i - 1];
			} else if (t[i - 1] == 'S') {
				t += 'W';
			} else {
				t += 'S';
			}
		} else {
			if (s[i] == 'x') {
				t += t[i - 1];
			} else if (t[i - 1] == 'W') {
				t += 'S';
			} else {
				t += 'W';
			}
		}
	}
	if (t[0] == 'S') {
		if (s[0] == 'o' && t[1] == t[n - 1]) {
			a = 1;
		} else if (s[0] == 'x' && t[1] != t[n - 1]) {
			a = 1;
		} else {
			t = "X";
			return t;
		}
	}
	if (t[0] == 'W') {
		if (s[0] == 'x' && t[1] == t[n - 1]) {
			a = 1;
		} else if (s[0] == 'o' && t[1] != t[n - 1]) {
			a = 1;
		} else {
			t = "X";
			return t;
		}
	}
	if (a==1 && t[n-1] == 'S') {
		if (s[n-1] == 'o' && t[n-2] == t[0]) {
			return t;
		} else if (s[n-1] == 'x' && t[n-2] != t[0]) {
			return t;
		} else {
			t = "X";
			return t;
		}
	}
	if (a==1 && t[n-1] == 'W') {
		if (s[n-1] == 'x' && t[n-2] == t[0]) {
			return t;
		} else if (s[n-1] == 'o' && t[n-2] != t[0]) {
			return t;
		} else {
			t = "X";
			return t;
		}
	}
}

int main() {
	cin >> n >> s;
	string ans;
	ans = f("SS");
	if (ans != "X") {
		cout << ans << endl;
		return 0;
	}
	ans = f("SW");
	if (ans != "X") {
		cout << ans << endl;
		return 0;
	}
	ans = f("WW");
	if (ans != "X") {
		cout << ans << endl;
		return 0;
	}
	ans = f("WS");
	if (ans != "X") {
		cout << ans << endl;
		return 0;
	}
	if (ans == "X") {
		cout << -1 << endl;
	}
	return 0;
}