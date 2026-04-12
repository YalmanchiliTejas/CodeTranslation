#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod ((ll)(1e9)+7)

vector<ll> v(3*(ll)(1e5),0);
vector<ll> v_inv(3*(ll)(1e5),0);

ll pmod(ll n, ll p){
	ll m=n%mod;
	if(p==0) return 1;
	ll ans=pmod((m*m)%mod, p/2)%mod;
	if(p%2==1) ans=ans*m%mod;
	return ans;
}

void factorial(ll n){
	v[0]=1;
	for(ll i=1; i<=n; i++){
		v[i]=v[i-1]*i%mod;
	}
	return;
}

void factorial_inv(ll n){
	for(ll i=0; i<=n; i++){
		v_inv[i]=pmod(v[i],mod-2);
	}
}

ll binom(ll n, ll k){
	if(n<k) return 0;
	ll tmp=v_inv[k]*v_inv[n-k]%mod;
	return v[n]*tmp%mod;
}

ll fcn(int n, int m){
	ll t=n*n%mod;
	return t*binom(m+1,3)%mod;
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	factorial(200002);
	factorial_inv(200002);

	ll t=(fcn(n,m)+fcn(m,n))%mod;
	t=t*binom(n*m-2, k-2)%mod;
	cout << t << endl;
	return 0;
}