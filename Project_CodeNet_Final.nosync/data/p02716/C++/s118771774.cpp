#include <iostream>
#include <algorithm>

using ll = long long int;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll a[225816],dp[225816][2][2];

int main(void){
	int n,i,m,j,k;
	ll ans = -INFLL;
	std::fill(dp[0][0],dp[225816][0],-INFLL);
	std::cin >> n;
	for(i=0; i<n; ++i){
		std::cin >> a[i];
	}
	a[n] = -INFLL;
	dp[0][0][i%2] = 0ll;
	for(i=0; i<n; ++i){
		for(k=0; k<2; ++k){
			for(j=0; j<2; ++j){
				dp[i+2][j][k] = std::max(dp[i+2][j][k],dp[i][j][k]+a[i+j]);
			}
			dp[i+2][1][k] = std::max(dp[i+2][1][k],dp[i][0][k]+a[i+1]);
			dp[i+1][k][0] = std::max(dp[i+1][k][0],dp[i][k][1]);
		}	
	}
	for(k=0; k<2; ++k){
		for(j=0; j<2; ++j){
			ans = std::max(ans,dp[n][j][k]);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
