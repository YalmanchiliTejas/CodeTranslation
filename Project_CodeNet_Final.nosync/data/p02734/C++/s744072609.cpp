#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





typedef long long ll;
const ll mod = 998244353;
const int maxn = 3030;

int n; ll s;
ll a[maxn];
ll dp[maxn][maxn][5];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    cin>>s;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }


    dp[0][0][0] = 1;
    //dp[i][j][k] = using first i elem, # ways to achieve sum j
    //k=0: interval didn't start
    //k=1: interval in progress
    //k=2: interval closed

    for (int i=0; i<n; i++) {
	for (int j=0; j<=s; j++) {

	    //don't start the interval
	    dp[i+1][j][0] += dp[i][j][0];
	    dp[i+1][j][0] %= mod;

	    //continue the interval, or start it now
	    dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
	    dp[i+1][j][1] %= mod;

	    //end the interval
	    dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
	    dp[i+1][j][2] %= mod;

	    //using element a[i]
	    if (j+a[i]<=s) {
		dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1];
		dp[i+1][j+a[i]][1] %= mod;

		dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1];
		dp[i+1][j+a[i]][2] %= mod;
	    }
	    
	}
    }
    
   
    ll ans = dp[n][s][2];
    ans %= mod;
    ans += mod;
    ans %= mod;

    out(ans);

    return 0;
}
