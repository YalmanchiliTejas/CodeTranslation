/*May The Force Be With Me*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define mll map<long long,long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define pb push_back
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000
#define rep(i,v,n) for(ll i = v; i < n; i++)
//Snippets: delta, sieve, fastexp, dfs, bfs, dijkstra, floodfill

using namespace std;

ll n;

void Input() {
	cin >> n;
}

void Solve() {
	vll a(n + 1);
	for (ll i = 1; i <= n; i++) cin >> a[i];
	ll dp[n + 1][n + 1];
	for (ll l = n; l >= 1; l--) {
		for (ll r = l; r <= n; r++) {
			if (l == r)dp[l][r] = a[l];
			else dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	}
	cout << dp[1][n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll T = 1;
	//cin >> T;
	//ll t = 1;
	while (T--) {
		Input();
		//cout << "Case " << t << ": ";
		Solve();
		//t++;
	}
	return 0;
}