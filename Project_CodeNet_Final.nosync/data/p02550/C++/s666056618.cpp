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

ll a[100100];
bool used[100100];

int main(void){
	ll t,s=0ll,ans=0ll,n=0ll,m,i,p=0ll;
	std::cin >> t >> a[0] >> m;
	while(true){
		used[a[n]] = true;
		a[n+1] = (a[n]*a[n])%m;
		++n;
		if(used[a[n]]){
			break;
		}
	}
	while(a[p]!=a[n]){
		ans += a[p];
		--t; ++p;
	}
	for(i=p; i<n; ++i){
		s += a[i];
	}
	ans += s*(t/(n-p));
	t %= (n-p);
	for(i=0; i<t; ++i){
		ans += a[p+i];
	}
	std::cout << ans << std::endl;
	return 0;
}
