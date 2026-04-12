#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long int
#define sd(x) scanf("%lld",&x)
#define inf 1e18
#define pll pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define bits(x) __builtin_popcountll(x)
#define ld long double
#define test() ll test; cin>>test; while(test--)
#define fi first
#define se second

ll dp[3005][3005];
ll S,N;
ll A[3005];
const ll MOD = 998244353;

void clear() {
	for(ll i=0;i<3005;i++) {
		for(ll j=0;j<3005;j++) {
			dp[i][j]=0;
		}
	}
}

// ll solve(ll indx, ll sum) {
// 	// if(sum==S && len==0) return 1;

// 	// if(len<=0 && sum<S) return 0;
// 	if(sum==S) return 1;
// 	if(indx>N) return 0;

// 	if(dp[indx][sum]!=-1) return dp[indx][sum];

// 	ll ans = 0;
// 	if(sum+A[indx]<=S) {
// 		ans = (solve(indx+1,sum+A[indx]))%MOD;
// 		// ans = (ans+solve(indx+1,sum+A[indx])+solve(indx+1,sum))%MOD;
// 		ans = (ans+(2*solve(indx+1,sum))%MOD)%MOD;
// 	} else {
// 		ans = (2*solve(indx+1,sum))%MOD;
// 	}

// 	return dp[indx][sum] = ans;
// }

inline ll mul(ll x, ll y, ll mod) {
	x %= mod;
	y %= mod;
	ll res = ((x*y)%mod+mod)%mod;
	return res;
}


ll power(ll x, ll n, ll mod) {
    ll res = 1;
    x %= mod;
    while(n) {
        if(n&1) {
            res = ((res*x)%mod+mod)%mod;
        }
        x = ((x*x)%mod+mod)%mod;
        n>>=1;
    }

    return res;
}


int main() {
	fastio;
	cin>>N>>S;

	clear();

	for(ll i=1;i<=N;i++) {
		cin>>A[i];
	}

	dp[0][0]=1;
	for(ll i=1;i<=N;i++) dp[0][i]=1;
	ll ans = 0;
	for(ll i=1;i<=S;i++) {
		for(ll j=1;j<=N;j++) {
			if(i>A[j]) {
				dp[i][j] = (dp[i][j-1] + dp[i-A[j]][j-1])%MOD;
			} else if(i==A[j]) {
				dp[i][j] = (j+dp[i][j-1])%MOD;
			} else {
				dp[i][j] = dp[i][j-1]%MOD;
			}
		}
	}

	for(ll i=1;i<=N;i++) {
		ans = (ans + dp[S][i])%MOD;
	}
	cout<<ans<<endl;
	// for(ll i=0;i<=S;i++) {
	// 	for(ll j=0;j<=N;j++) {
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<dp[S][N]<<endl;
	
}