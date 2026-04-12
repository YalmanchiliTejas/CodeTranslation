#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = long long int;
using P = std::pair<ll, int>;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);

#define l_ength size

ll MOD;

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

ll memo[3030][3030],dp[3030][3030];
bool done[3030][3030];

ll rwpw(ll a, ll p, ll m = MOD){
	ll ret = 1ll;
	while(p){
		if(p%2){
			ret *= a; ret %= m;
		}
		a *= a; a %= m;
		p /= 2;
	}
	return ret;
}

ll ramen(int a){
	return rwpw(2ll,rwpw(2ll,a,MOD-1));
}

ll c(int n, int k){
	if(done[n][k]){
		return memo[n][k];
	}
	done[n][k] = true;
	if(k==n || k==0){
		return memo[n][k] = 1ll;
	}
	memo[n][k] = c(n-1,k-1);
	add_mod(memo[n][k],c(n-1,k));
	return memo[n][k];
}

int main(void){
	int n,i,j;
	ll tmp,ans=0ll;
	std::cin >> n >> MOD;
	dp[0][0] = 1ll;
	for(i=0; i<n; ++i){
		for(j=0; j<=n; ++j){
			add_mod(dp[i+1][j],dp[i][j]);
			add_mod(dp[i+1][j+1],dp[i][j]);
			add_mod(dp[i+1][j],dp[i][j]*j%MOD);
		}
	}
	for(i=0; i<=n; ++i){
		for(j=0; j<=n; ++j){
			mul_mod(dp[i][j],rwpw(rwpw(2ll,n-i),j));
		}
		for(j=0; j<n; ++j){
			add_mod(dp[i][j+1],dp[i][j]);
		}
	}
	for(i=0; i<=n; ++i){
		tmp = dp[i][n];
		mul_mod(tmp,ramen(n-i));
		mul_mod(tmp,c(n,i));
		// std::cout << tmp << std::endl;
		add_mod(ans,((i%2)?(MOD-tmp):tmp));
	}
	std::cout << ans << std::endl;
	return 0;
}
