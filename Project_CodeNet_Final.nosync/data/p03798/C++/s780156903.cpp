#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char getNext(char prev, char input, char testimony) {
	char res;
	if (prev == 'S' && input == 'S' && testimony == 'o') res = 'S';
	if (prev == 'S' && input == 'S' && testimony == 'x') res = 'W';
	if (prev == 'S' && input == 'W' && testimony == 'o') res = 'W';
	if (prev == 'S' && input == 'W' && testimony == 'x') res = 'S';
	if (prev == 'W' && input == 'S' && testimony == 'o') res = 'W';
	if (prev == 'W' && input == 'S' && testimony == 'x') res = 'S';
	if (prev == 'W' && input == 'W' && testimony == 'o') res = 'S';
	if (prev == 'W' && input == 'W' && testimony == 'x') res = 'W';
	return res;
}

bool check(string s, string t) {
	int n = s.size();
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (t[i] == 'S' && s[i] == 'o') {
			if (i == 0) {
				if (t[1] != t[n - 1]) ok = false;
			}
			else if (i == n - 1) {
				if (t[n - 2] != t[0]) ok = false;
			}
			else {			
				if (t[i - 1] != t[i + 1]) ok = false;
			}
		}
		if (t[i] == 'S' && s[i] == 'x') {
			if (i == 0) {
				if (t[1] == t[n - 1]) ok = false;
			}
			else if (i == n - 1) {
				if (t[n - 2] == t[0]) ok = false;
			}
			else {
				if (t[i - 1] == t[i + 1]) ok = false;
			}			
		}
		if (t[i] == 'W' && s[i] == 'o') {
			if (i == 0) {
				if (t[1] == t[n - 1]) ok = false;
			}
			else if (i == n - 1) {
				if (t[n - 2] == t[0]) ok = false;
			}
			else {
				if (t[i - 1] == t[i + 1]) ok = false;
			}
		}
		if (t[i] == 'W' && s[i] == 'x') {
			if (i == 0) {
				if (t[1] != t[n - 1]) ok = false;
			}
			else if (i == n - 1) {
				if (t[n - 2] != t[0]) ok = false;
			}
			else {
				if (t[i - 1] != t[i + 1]) ok = false;
			}
		}
	}
	return ok;
}

bool getOk(string s, string &t) {
	bool res = false;
	char prev = t[0];
	char now = t[1];
	char next;
	for (int i = 1; i < s.size()- 1; i++) {
		next = getNext(prev, now, s[i]);
		if (i <= s.size() - 2) {
			t[i + 1] = next;
		}
		prev = now;
		now = next;
	}
	return check(s, t);
}

int main() {

	int n; cin >> n;
	string s; cin >> s;
	string t;

	t.resize(n);
	t[0] = 'S';
	t[1] = 'S';
	if (getOk(s, t)) {
		cout << t << endl;
		return 0;
	}
	t.resize(n);
	t[0] = 'W';
	t[1] = 'S';
	if (getOk(s, t)) {
		cout << t << endl;
		return 0;
	}
	t.resize(n);
	t[0] = 'S';
	t[1] = 'W';
	if (getOk(s, t)) {
		cout << t << endl;
		return 0;
	}
	t.resize(n);
	t[0] = 'W';
	t[1] = 'W';
	if (getOk(s, t)) {
		cout << t << endl;
		return 0;
	}	
	cout << -1 << endl;
    return 0;
}