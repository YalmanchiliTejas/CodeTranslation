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
	int x,y,z,i,j,n;
	ll b = 0ll, ans=0ll;
	std::fill(dp[0],dp[2222],-INFLL);
	std::fill(calc,calc+2222,-INFLL);
	std::cin >> n;
	std::cin >> x >> y;
	dp[x][y] = 0ll; calc[x] = 0ll; calc[y] = 0ll;
	for(i=1; i<n; ++i){
		std::cin >> x >> y >> z;
		if(x == y && y == z && z == x){
			++b;
			continue;
		}
		for(j=1; j<=n; ++j){
			sp[j][x] = -INFLL;
			sp[j][y] = -INFLL;
			sp[j][z] = -INFLL;
		}
		// x を残す
		for(j=1; j<=n; ++j){
			sp[j][x] = std::max(sp[j][x],calc[j]);
			if(y == z){
				sp[j][x] = std::max(sp[j][x],dp[y][j]+1);
				sp[j][x] = std::max(sp[j][x],dp[j][y]+1);
			}
		}
		// y を残す
		for(j=1; j<=n; ++j){
			sp[j][y] = std::max(sp[j][y],calc[j]);
			if(x == z){
				sp[j][y] = std::max(sp[j][y],dp[x][j]+1);
				sp[j][y] = std::max(sp[j][y],dp[j][x]+1);
			}
		}
		// z を残す
		for(j=1; j<=n; ++j){
			sp[j][z] = std::max(sp[j][z],calc[j]);
			if(x == y){
				sp[j][z] = std::max(sp[j][z],dp[x][j]+1);
				sp[j][z] = std::max(sp[j][z],dp[j][x]+1);
			}
		}
		// x,y を残す
		sp[x][y] = std::max(sp[x][y],ans);
		sp[x][y] = std::max(sp[x][y],dp[z][z]+1);
		// y,z を残す
		sp[y][z] = std::max(sp[y][z],ans);
		sp[y][z] = std::max(sp[y][z],dp[x][x]+1);
		// x,z を残す
		sp[x][z] = std::max(sp[x][z],ans);
		sp[x][z] = std::max(sp[x][z],dp[y][y]+1);
		for(j=1; j<=n; ++j){
			dp[j][x] = std::max(dp[j][x],sp[j][x]);
			dp[j][y] = std::max(dp[j][y],sp[j][y]);
			dp[j][z] = std::max(dp[j][z],sp[j][z]);
			calc[x] = std::max(calc[x],sp[j][x]);
			calc[y] = std::max(calc[y],sp[j][y]);
			calc[z] = std::max(calc[z],sp[j][z]);
			calc[j] = std::max(calc[j],sp[j][x]);
			calc[j] = std::max(calc[j],sp[j][y]);
			calc[j] = std::max(calc[j],sp[j][z]);
			ans = std::max(ans,sp[j][x]);
			ans = std::max(ans,sp[j][y]);
			ans = std::max(ans,sp[j][z]);
		}
	}
	std::cin >> z;
	ans = std::max(ans,dp[z][z]+1);
	ans += b;
	std::cout << ans << std::endl;
	return 0;
}
