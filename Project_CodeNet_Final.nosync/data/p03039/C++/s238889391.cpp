#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

const int MAX = 200100;
ll fact[MAX], fact_inv[MAX];

ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

ll comb(ll n, ll r){
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}

int main(){
	ll n, m, k;
	cin >> n >> m >> k;
	fact[0]=1;
	for( int i = 0; i < m*n+100; ++i ){
		fact[i+1]=fact[i]*(i+1)%MOD;
	}
	fact_inv[m*n+100]=power(fact[m*n+100], MOD-2);
	for( int i = m*n+99; i >= 0; --i ){
		fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
	}
	ll sum = 0;
	for( ll	d = 1; d < m; ++d ){
		sum += d*(n*n)*(m-d);
		sum %= MOD;
	}
	for( ll d = 1; d < n; ++d ){
		sum += d*(m*m)*(n-d);
		sum %= MOD;
	}
	cout << ( sum * comb(m*n-2, k-2) ) % MOD << endl; 
    return 0;
}