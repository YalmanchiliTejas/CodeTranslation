#include<bits/stdc++.h>
using namespace std;

#define fast_input() {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }
#define For(i, l, r) for(int (i) = (l); (i) <= (r); ++(i))
#define For1(i, l, r) for(int (i) = (r); (i) >= (l); --(i))

/*
MIKUNO - 15/02/1999
*/
//	priority_queue <ll, vector<ll>, greater<ll> > q;
#define INF 1e9+5
using ll = long long;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
void add_self(int& a, int b) {
	a += b;
	if (a > mod)
		a -= mod;
}

int main() {
	fast_input();
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<ll>>dp(n + 1, vector<ll> (n + 1));
	vector<vector<bool>>player(n + 1, vector<bool>(n + 1)); // 0 is first player
	// 1 is second player
	
	for (int l = n - 1; l >= 0; --l) {
		for (int r = l; r < n; ++r) {
			if (l == r) dp[l][r] = a[l];
			else
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	}
	cout << dp[0][n - 1];
}

