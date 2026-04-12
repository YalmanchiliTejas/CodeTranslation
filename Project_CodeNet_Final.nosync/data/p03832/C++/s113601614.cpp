#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
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

int a,b,c,d;
ll comb[1024][1024],memo[1024][1024];
bool done[1024][1024];

ll rwpw(ll a, ll p = MOD-2){
	ll ret = 1ll;
	while(p){
		if(p%2){
			mul_mod(ret,a);
		}
		mul_mod(a,a);
		p /= 2;
	}
	return ret;
}

ll solve(int n, int g){
	int i;
	ll k=1ll;
	if(!n){
		return 1ll;
	}else if(g>b){
		return 0ll;
	}
	if(done[n][g]){
		return memo[n][g];
	}
	done[n][g] = true;
	memo[n][g] = solve(n,g+1);
	for(i=1; i<=d; ++i){
		if(i*g>n){
			break;
		}
		mul_mod(k,comb[n-(i-1)*g][g]);
		mul_mod(k,rwpw(i));
		if(i>=c){
			add_mod(memo[n][g],(solve(n-i*g,g+1)*k)%MOD);
		}
	}
	// cout << n << " " << g << " " << memo[n][g] << endl; 
	return memo[n][g];
}

int main(void){
	int n,i,j;
	cin >> n >> a >> b >> c >> d;
	for(i=0; i<=n; ++i){
		comb[i][0] = 1ll;
		comb[i][i] = 1ll;
		for(j=1; j<i; ++j){
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%MOD;
		}	
	}
	cout << solve(n,a) << endl;
	return 0;
}
