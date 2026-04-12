#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <time.h>
#define int long long
#define ll long long
#define us unsigned
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define nin(ary, n) for (int i = 0; i < (n); i++) cin >> ary[i]
#define nnin(ary, h, w) for (int i = 0; i < (h); ++i) for (int j = 0; j < (w); ++j) cin >> ary[i][j]
#define opt(conditions, a, b) cout << ((conditions) ? #a : #b) << endl
using namespace std;
const double PI = acos(-1.0);
const int MOD = 1e9 + 9;

int max_n(int ary[], int length) {
	int max = ary[0];
	for (int i = 1; i < length; i++)
		if (max < ary[i]) max = ary[i];
	return max;
}

int max_o(int ary[], int length) {
	int max;
	max = max_n(ary, length);
	for (int i = 0; i < length; i++) {
		if (ary[i] == max) return i;
	}
	return -1;
}

int min_n(int ary[], int length) {
	int min = ary[0];
	for (int i = 1; i < length; i++)
		if (min > ary[i]) min = ary[i];
	return min;
}

int min_o(int ary[], int length) {
	int min;
	min = min_n(ary, length);
	for (int i = 0; i < length; i++) {
		if (ary[i] == min) return i;
	}
	return -1;
}

int gcm(int a, int b) {
	int result = a;
	int k = 0;
	int n = b;
	do {
		k = result % n;
		result = n;
		n = k;
	} while (k != 0);
	return result;
}

int gcm_n(int ary[], int length) {
	int g = ary[0];
	for (int i = 0; i < length; i++)
		g = gcm(g, ary[i]);
	return g;
}

int lcm(int a, int b) {
	int g, n;
	g = gcm(a, b);
	n = gcm(a, g);
	a = a / n;
	b = b / (g / n);
	return a*b;
}

int lcm_n(int ary[], int length) {
	int l = ary[0];
	for (int i = 0; i < length; i++)
		l = lcm(l, ary[i]);
	return l;
}
int n, a[1000000];


signed main() {
	cin >> n;
	rep(i, n) {
		if (i % 2 == 0) {
			cin >> a[100000 - i / 2];
		}
		else
			cin >> a[100000 + (i + 1) / 2];
	}

	if (n % 2 == 0) {
		rep(i, n) {
			cout << a[100000 + n / 2 - i] << ' ';
		}
		cout << endl;
	}
	else {
		rep(i, n) {
			cout << a[100000 - (n + 1) / 2 + i + 1] << ' ';
		}
		cout << endl;
	}

	return 0;
}
