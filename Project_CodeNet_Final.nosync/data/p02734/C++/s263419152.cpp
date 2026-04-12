#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = 998244353ll;

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

ll dp[3333][3333];
int a[3333];

int main(void){
	int n,s,i,j;
	ll ans = 0ll;
	cin >> n >> s;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	dp[0][a[0]] = 1ll;
	for(i=1; i<n; ++i){
		for(j=0; j<=s; ++j){
			add_mod(dp[i][j],dp[i-1][j]);
			if(j+a[i]<=s){
				add_mod(dp[i][j+a[i]],dp[i-1][j]);
			}
		}
		add_mod(dp[i][a[i]],i+1);
	}
	for(i=0; i<n; ++i){
		add_mod(ans,dp[i][s]);
	}
	cout << ans << endl;
	return 0;
}
