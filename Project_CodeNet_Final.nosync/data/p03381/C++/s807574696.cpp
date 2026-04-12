#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

//#include<bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define _USE_MATH_DEFINES
#define ll long long
#define ins Not Needed Thing
#define ull unsigned long long
#define ld long double
#define Accepted 0
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define SORRY FUL Accepted 
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0)
#define Toktama Kazakhstan 

using namespace std;

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 2e5 + 123;                                          
const int PRI = 555557;
const int pri = 997;

int tests = 1;
int t[N * 4];
int b[N];
int a[N];
int n;

void upd (int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] += x;
		return ;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm) upd (pos, x, (v << 1), tl, tm);
	else upd (pos, x, (v << 1) | 1, tm + 1, tr);

	t[v] = t[(v << 1)] + t[(v << 1) | 1];
}

int get (int kth, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) return tl;
	int tm = (tl + tr) >> 1;
	if (t[(v << 1)] >= kth) return get(kth, (v << 1), tl, tm);
	else return get(kth - t[(v << 1)], (v << 1) | 1, tm + 1, tr);
}

inline void Solve () {
	//easy
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[i] = a[i];
	}	

	sort(b + 1, b + 1 + n);

	for (int i = 1; i <= n; i ++) {
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
		upd (a[i], 1);
	}

	for (int i = 1; i <= n; i ++) {
		upd(a[i], -1);
		int kth = n - (n / 2);
		cout << b[get(kth)] << '\n';
		upd(a[i], 1);
	}
}

int main () {
	SpeedForce;
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);	
	// cin >> tests;
	while(tests --) {
		Solve ();
		// Ee Zadrot
	}

	return Accepted; 
}