#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
signed main() {
	int n, m, a = 0, ans = 0; cin >> n;
	string s, t = ""; cin >> s;
	//羊、羊
	t += 'S'; t += 'S';
	for (int h = 1; h < n; h++) {
		if (h == n - 1) {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'S') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'W') { a = 1; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'W') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'S') { a = 1; }
			}

		}
		else {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'S'; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'W'; }
			}
		}
	}
	if (s[0] == 'o' && t[1] != t[n - 1]) { a = 0; }
	if (s[0] == 'x' && t[1] == t[n - 1]) { a = 0; }
	if (a == 1) { cout << t << endl; return 0; }
	t = ""; a = 0;
	//羊、狼
	t += 'S'; t += 'W';
	for (int h = 1; h < n; h++) {
		if (h == n - 1) {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'S') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'W') { a = 1; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'W') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'S') { a = 1; }
			}

		}
		else {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'S'; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'W'; }
			}
		}
	}
	if (s[0] == 'o' && t[1] != t[n - 1]) { a = 0; }
	if (s[0] == 'x' && t[1] == t[n - 1]) { a = 0; }
	if (a == 1) { cout << t << endl; return 0; }
	t = ""; a = 0;
	//狼、羊
	t += 'W'; t += 'S';
	for (int h = 1; h < n; h++) {
		if (h == n - 1) {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'W') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'S') { a = 1; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'S') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'W') { a = 1; }
			}

		}
		else {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'S'; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'W'; }
			}
		}
	}
	if (s[0] == 'o' && t[1] == t[n - 1]) { a = 0; }
	if (s[0] == 'x' && t[1] != t[n - 1]) { a = 0; }
	if (a == 1) { cout << t << endl; return 0; }
	t = ""; a = 0;
	//狼、狼
	t += 'W'; t += 'W';
	for (int h = 1; h < n; h++) {
		if (h == n - 1) {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'W') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'S') { a = 1; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'S') { a = 1; }
				if (s[h] == 'x' && t[h - 1] == 'W') { a = 1; }
			}

		}
		else {
			if (t[h] == 'S') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'S'; }
			}
			if (t[h] == 'W') {
				if (s[h] == 'o' && t[h - 1] == 'S') { t += 'W'; }
				if (s[h] == 'o' && t[h - 1] == 'W') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'S') { t += 'S'; }
				if (s[h] == 'x' && t[h - 1] == 'W') { t += 'W'; }
			}
		}
	}
	if (s[0] == 'o' && t[1] == t[n - 1]) { a = 0; }
	if (s[0] == 'x' && t[1] != t[n - 1]) { a = 0; }
	if (a == 1) { cout << t << endl; return 0; }
	cout << -1 << endl;
	return 0;
}