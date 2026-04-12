#include <iostream>
using namespace std;

typedef long long ll;

ll inf = 1e9+7;
ll fact[200010] = {0};
ll inv[200010] = {0};

ll mult(ll n, ll m){
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

ll hcomb(ll n,ll k){
	if(n==0 && k==0) return 1;
	return comb(n+k-1,k);
}

int N,M,K;
ll X[200010],Y[200010];

int main(){
    cin >> N >> M >> K;
    factorial(N+M);
    ll ans = 0;
    for(ll i=1;i<=N-1;i++){
        ll num = N-i;
        (ans += num*i%inf*M%inf*M%inf)%=inf;
    }
//    (ans1 *= comb(N,K-2))%=inf;
//    (ans1 *= M*M%inf*comb(M,K-2))%=inf;
    for(ll i=1;i<=M-1;i++){
        ll num = M-i;
        (ans += num*i%inf*N%inf*N%inf)%=inf;
    }
//    (ans2 *= comb(M,K-2))%=inf;
//    (ans2 *= N*N%inf*comb(N,K-2)%inf)%=inf;
    for(ll i=1;i<=K-2;i++){
        (ans *= (M*N-2)-(i-1))%=inf;
        (ans *= mult(i,inf-2))%=inf;
    }
    cout << ans << endl;
}