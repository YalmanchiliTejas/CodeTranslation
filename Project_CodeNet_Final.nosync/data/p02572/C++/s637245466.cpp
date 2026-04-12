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

int main(void){
	int i,n;
	ll a,x=0ll,y=0ll;
	std::cin >> n;
	for(i=0; i<n; ++i){
		std::cin >> a;
		add_mod(x,a);
		add_mod(y,a*a%MOD);
	}
	mul_mod(x,x);
	add_mod(x,MOD-y);
	mul_mod(x,(MOD+1)/2);
	std::cout << x << std::endl;
	return 0;
}
