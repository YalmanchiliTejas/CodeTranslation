#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define loop(i, n) for(int i = 0 ; i < n ; ++i)
#define LOOP(i, a, b) for(int i = a ; i < b ; ++i)
#define max3(a, b, c) max(a, max(b,c))
#define max4(a, b, c, d) max3(a, b, max(c, d))
#define ff first
#define ss second
#define mkp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define nmbr(c) (int)(c-'0')
#define ltr(c) (int)(c-'a')
#define INF 1e18
#define inf 1e9
#define MOD 1000000007 //check
#define _69e27 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n, v[3002];
ll dp[3002][3002][2];
ll val(int l, int r, int i)
{
	if(l == r) return pow(-1, i)*v[r];
	ll &ans = dp[l][r][i];
	if(ans != -1) return ans;
	if(i == 0) ans = max(v[l]+val(l+1, r, i^1), v[r]+val(l, r-1, i^1));
	else ans = min(-v[l]+val(l+1, r, i^1), -v[r]+val(l, r-1, i^1));
	return ans;
}
int main() {
	_69e27;
	cin >> n;
	loop(i, n) cin >> v[i];
	memset(dp, -1, sizeof(dp));
	cout << val(0, n-1, 0);
	return 0;
}