#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 100005;
string s;
int d;
ll dp[10005][2][100];
ll dfs(int now, int lim, int m) {
	if (now == -1) {
		return m == 0;
	}
	if (~dp[now][lim][m]) {
		return dp[now][lim][m];
	}
	int up = lim ?  s[now] - '0' : 9;
	ll ans = 0;
	for (int i = 0 ; i <= up ; i++) {
		ans += dfs(now - 1, lim && (i == up), (m + i) % d);
		ans %= mod;
	}
	return dp[now][lim][m] = ans;
}
void go() {
	cin >> s >> d;
	reverse(all(s));
	memset(dp, -1, sizeof(dp));
	cout << (dfs(s.size() - 1, 1, 0) + mod - 1) % mod << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}