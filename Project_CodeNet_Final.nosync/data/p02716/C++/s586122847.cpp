#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <math.h>
#include <map>
#include <bitset>
#include <queue>
#include <list>1
#include <utility>
 
//#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using p = pair<int, int>;
using Graph = vector<vector<char>>;
#define rep(i,n)  for(int i = 0; i < n ; i++)
#define chmax(x,y) x = max(x,y);
int dx[4]{ -1,0,1,0 };
int dy[4]{ 0,1,0,-1 };
const ll INF = 1e18;
ll dp[200005][4]; // i番目までの個数でj個余分な×を選んだ際の和の最大値
 
//  ABC F 162
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	int k = 1 + n % 2;
	rep(i, n + 1) {
		rep(j, k + 1) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, k + 1)
		{
			chmax(dp[i + 1][j + 1], dp[i][j]);
			ll now = dp[i][j];
			if ((i + j) % 2 == 0) { now += a[i]; }
			chmax(dp[i + 1][j], now);
		}
	}
	ll ans = dp[n][k];
	cout << ans << endl;
}