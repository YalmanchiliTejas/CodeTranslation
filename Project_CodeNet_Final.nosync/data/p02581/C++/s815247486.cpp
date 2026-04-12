#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

ll dp[2222][2222],sp[2222][2222],calc[2222];

int main(void){
	int x[3],i,j,k,n,t[3][2]={{1,2},{0,2},{0,1}};
	ll b = 0ll, ans=0ll;
	std::fill(dp[0],dp[2222],-INFLL);
	std::fill(calc,calc+2222,-INFLL);
	std::cin >> n;
	std::cin >> x[0] >> x[1];
	dp[x[0]][x[1]] = 0ll;
	for(k=0; k<2; ++k){
		calc[x[k]] = 0ll;
	}
	for(i=1; i<n; ++i){
		std::cin >> x[0] >> x[1] >> x[2];
		std::sort(x,x+3);
		if(x[0]==x[2]){
			++b; continue;
		}
		for(j=1; j<=n; ++j){
			for(k=0; k<3; ++k){
				sp[j][x[k]] = -INFLL;
			}
		}
		// 1つだけ残す
		for(k=0; k<3; ++k){
			for(j=1; j<=n; ++j){
				sp[j][x[k]] = std::max(sp[j][x[k]],calc[j]);
				if(x[t[k][0]] == x[t[k][1]]){
					sp[j][x[k]] = std::max(sp[j][x[k]],dp[x[t[k][0]]][j]+1);
					sp[j][x[k]] = std::max(sp[j][x[k]],dp[j][x[t[k][0]]]+1);
				}
			}
		}
		// 2つ残す
		for(k=0; k<3; ++k){
			sp[x[t[k][0]]][x[t[k][1]]] = std::max(sp[x[t[k][0]]][x[t[k][1]]],ans);
			sp[x[t[k][0]]][x[t[k][1]]] = std::max(sp[x[t[k][0]]][x[t[k][1]]],dp[x[k]][x[k]]+1);
		}
		for(j=1; j<=n; ++j){
			for(k=0; k<3; ++k){
				dp[j][x[k]] = std::max(dp[j][x[k]],sp[j][x[k]]);
				calc[x[k]] = std::max(calc[x[k]],sp[j][x[k]]);
				calc[j] = std::max(calc[j],sp[j][x[k]]);
				ans = std::max(ans,sp[j][x[k]]);
			}
		}
	}
	std::cin >> x[2];
	ans = std::max(ans,dp[x[2]][x[2]]+1);
	ans += b;
	std::cout << ans << std::endl;
	return 0;
}
