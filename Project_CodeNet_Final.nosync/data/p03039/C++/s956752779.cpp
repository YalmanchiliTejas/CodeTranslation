#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,A,B;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int MOD = (1e+9) + 7,MAX_N = (2e+5)+10;
vec nCm(MAX_N+1,0);
vec fact(MAX_N+1,0),fact_inv(MAX_N+1,0);

ll fastpow(ll a, ll pw) {
	ll res = 1;
	while (pw) {
		if (pw & 1) res = res * a % MOD;
		a = a * a % MOD;
		pw >>= 1;
	}
	return res;
}
void makefact(ll n){//MODは素数かつnより大きい
    ll ans = 1;
    fact.at(0) = ans;
    fact_inv.at(0) = ans;
    reps(i,1,n+1){
        (ans *= i)%=MOD;
        fact.at(i) = ans;
        fact_inv.at(i) = fastpow(ans,MOD-2);
    }
    return;
}
void makenCm(ll n){
    rep(i,n+1){
        ll ans = fact.at(n);
        (((ans*=fact_inv.at(n-i))%=MOD)*=fact_inv.at(i))%=MOD;
        nCm.at(i) = ans;
    }
    return;
}

int main() {
    cin>>N>>M>>K;
    makefact(N*M-2);
    makenCm(N*M-2);
    ll ans = 0;
    ll M2 = (M*M) % MOD, N2 = (N*N) % MOD;
    reps(d,1,N){
        ll temp = nCm.at(K-2);
        (temp*=N-d)%=MOD;
        (temp*=M2)%=MOD;
        (temp*=d)%=MOD;
        (ans += temp)%=MOD;
    }
    //cout<<ans<<endl;
    reps(d,1,M){
        ll temp = nCm.at(K-2);
        (temp*=M-d)%=MOD;
        (temp*=N2)%=MOD;
        (temp*=d)%=MOD;
        (ans += temp)%=MOD;
    }
   /*rep(i,11){
        cout<<i<<"fact"<<fact.at(i)<<endl;
        cout<<i<<"fact_inv"<<fact_inv.at(i)<<endl;
    }*/
    cout<<ans<<endl;
}