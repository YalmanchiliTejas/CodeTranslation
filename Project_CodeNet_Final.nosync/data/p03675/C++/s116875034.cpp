#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;
//#define int long long

signed main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	deque <int> q;
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		int cur;
		cin >> cur;
		if (!p) {
			q.push_back(cur);
		}
		else {
			q.push_front(cur);
		}
		p ^= 1;
	}
	if (!p) {
		while (q.size()) {
			cout << q.front() << ' ';
			q.pop_front();
		}
	}
	else {
		while (q.size()) {
			cout << q.back() << ' ';
			q.pop_back();
		}
	}
}