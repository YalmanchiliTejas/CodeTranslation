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
#include<functional>
//#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int aa[12345678], bb[1234][1234], cc[123][123][123];
int res[123456], uio[1234][1234];
signed main() {
	int n, m, a, b, x = 0, y = 0, ans = 0; cin >> n >> a >> b;
	if (a != b) { x = n / (a - b); }
	x *= 2; x = max(x - 20, (long long)0);
	y = (a - b) * x / 2;
	if (a <= b && n > a) { cout << -1 << endl; return 0; }
	while (true) {
		y += a; x++; if (y >= n) { cout << x << endl; return 0; }
		y -= b; x++;
	}
	return 0;
}