#include <iostream>
using namespace std;
typedef long long ll;
ll inf = 1e9+7;
ll fact[1010] = {0};
ll inv[1010] = {0};

ll mult(ll n, ll m){
    if(m==0) return 1;
	if(m==1) return n%inf;
	else if(m%2==0){
		ll t = mult(n,m/2);
		return (t*t)%inf;
	}else{
		ll t = mult(n,m-1);
		return (t*n)%inf;
	}
}

void factorial(ll N){
	for(ll i=0;i<=N;i++){
		if(i==0){
			fact[i] = 1;
			inv[i] = 1;
		}
		else{
			fact[i] = (i*fact[i-1])%inf;
			inv[i] = mult(fact[i],inf-2);
		}
	}
}

ll comb(ll n,ll k){
	if(n<k) return 0;
	if(n<0 || k<0) return 0;
	else return (((fact[n]*inv[k])%inf)*inv[n-k])%inf;
}

ll permutation(ll n,ll k){
    return (comb(n,k)*fact[k])%inf;
}

int N,A,B,C,D;
ll dp[1010][1010] = {};

int main(){
    cin >> N >> A >> B >> C >> D;
    factorial(N);
    for(int i=0;i<=B;i++) dp[i][0] = 1;
    ll ans = 0;
    for(int i=A;i<=B;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<=D;k++){
                if(j-i*k<0) break;
                if(0<k && k<C) continue;
                ll v = (mult(inv[i],k)*inv[k])%inf;
                ll r = (permutation(N-j+i*k,i*k)*v)%inf;
                (dp[i][j] += (dp[i-1][j-i*k]*r)%inf)%=inf;
            }
        }
    }
    cout << dp[B][N] << endl;
}