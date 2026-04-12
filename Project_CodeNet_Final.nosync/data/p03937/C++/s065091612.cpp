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
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
char maze[12][12];
signed main() {
	ll n, m, a, ans = 0; cin >> n >> m;
	for (int h = 0; h < 10; h++) {
		for (int i = 0; i < 10; i++) {
			maze[h][i] = '.';
		}
	}
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= m; i++) {
			cin >> maze[h][i];
			if (maze[h][i] == '#') { ans++; }
		}
	}
	ll x = 1, y = 1;
	for (int i = 1; i < ans; i++) {
		if (maze[x][y + 1] == '#') { y++; continue; }
		if (maze[x + 1][y] == '#') { x++; continue; }
		cout << "Impossible" << endl; return 0;
	}
	cout << "Possible" << endl;
	return 0;
}