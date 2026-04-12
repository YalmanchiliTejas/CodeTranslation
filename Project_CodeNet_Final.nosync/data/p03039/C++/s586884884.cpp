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

ll N,M,K;
ll X[200010],Y[200010];

int main(){
    cin >> N >> M >> K;
    ll ans = 0;
    for(ll i=1;i<=N-1;i++){
        ll num = N-i;
        (ans += num*i%inf*M%inf*M%inf)%=inf;
    }
    for(ll i=1;i<=M-1;i++){
        ll num = M-i;
        (ans += num*i%inf*N%inf*N%inf)%=inf;
    }
    for(ll i=1;i<=K-2;i++){
        (ans *= (M*N-2)-(i-1))%=inf;
        (ans *= mult(i,inf-2))%=inf;
    }
    cout << ans << endl;
}