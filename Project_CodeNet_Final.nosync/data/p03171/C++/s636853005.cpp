#include "bits/stdc++.h"
#pragma GCC optimize "03"
using namespace std;

#define int long long int
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define dbg(x) { cerr<<"> "<<#x<<": "<<x<< endl; }
#define dbg2(x,y) { cerr<<"> "<<#x<<": "<<x<<" , "<<#y<<": "<<y<<endl; }
#define dbg3(x,y,z) { cerr<<"> "<<#x<<": "<<x<<" , "<<#y<<": "<<y<<" , "<<#z<<": "<<z<<endl; }
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
const int inf = INT_MAX;
const double eps = 0.0000001;
const double PI = acos(-1.0);
const int MOD = 1e9+7;
const int N  = 3e3+5;

int a[N], dp[N][N];

int solve (int i, int j, int s) {
	if (i == j && s == 0) return a[i];
	if (i == j && s == 1) return -a[i];
	if (dp[i][j]) return dp[i][j];
	if (s == 0) dp[i][j] = max(a[j]+solve(i,j-1,!s), a[i]+solve(i+1,j,!s));
	else dp[i][j] = min(-a[j]+solve(i,j-1,!s), -a[i]+solve(i+1,j,!s));
	return dp[i][j];
}

signed main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif  
    IOS;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    cout << solve(0,n-1,0);
    return 0;
}