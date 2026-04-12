#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mod, factr[i]=factr[i-1]*inv[i]%mod;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mod*factr[N_-C_]%mod;
}

int main(){
	ll n,m,k;cin>>n>>m>>k;
    ll ans = 1;
    ans = comb(m*n-2,k-2);
    ll num = 0;
    rep(i,1,n){
        num = (num+i*(n-i)%mod*m%mod*m%mod)%mod;
    }
    rep(i,1,m){
        num = (num+i*(m-i)%mod*n%mod*n%mod)%mod;
    }
    cout<<(ans*num%mod)%mod<<endl;
}