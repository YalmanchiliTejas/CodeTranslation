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
const int mod = 1e9+7;
const int maxn = 100005;
ll dp[3005][3005];
vector<int>v;
ll solve(int l ,int r) {
	if (~dp[l][r]) {
		return dp[l][r];
	}
	if (l > r) {
		return dp[l][r] = 0;
	}
	dp[l][r] = max(v[r] - solve(l, r - 1), v[l] - solve(l + 1, r));
	return dp[l][r];
}
void go() {
	int n, k;
	cin >> n;
	v.pb(0);
	f(n) {
		int x;
		cin >> x;
		v.pb(x);
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, n) << '\n';
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