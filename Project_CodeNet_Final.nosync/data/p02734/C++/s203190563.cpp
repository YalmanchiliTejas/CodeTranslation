#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MOD = 998244353, S = 3005;

int dp[S][S][2], a[S];

inline int add(int x, int y){
	int res = x + y;	
	while(res >= MOD)res-=MOD;
	return res;
}

inline int mul(int x,int y){
	return (1LL * x * y) % MOD;
}

int modpow(int x,int p){
	int res = 1;
	while(p){
		if(p&1)gmul(res,x);
		gmul(x,x);
		p/=2;
	}
	return res;
}

inline int invert(int x){
	return modpow(x,MOD - 2);
}


int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,s;
	cin >> n >> s;
	rep(i,0,n)cin >> a[i];
	rep(i,0,n){
		// forward
		rep(j,0,s+1){
			gadd(dp[i+1][j][0],add(dp[i][j][0], j == 0));
			gadd(dp[i+1][j][1],add(add(dp[i][j][0], j == 0), dp[i][j][1]));
			if(j + a[i] <= s){ // in
				gadd(dp[i+1][j+a[i]][0],add(dp[i][j][0], j == 0));
				gadd(dp[i+1][j+a[i]][1],add(dp[i][j][0], j == 0));
			}
		}
	}
	cout << dp[n][s][1] << '\n';
}
