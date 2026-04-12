#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N, M, K;
const ll mod = 1e9 + 7;
ll kai[300010];
ll F[300010];
ll ans;

ll fer(ll x, ll y){
    ll add=(kai[x]*F[y])%mod;
    add*=F[x - y];
    add%=mod;
    return add;
}

ll fermat(ll x, int y) {
	if (y == 0)return 1;
	if (y == 1)return x;
	ll F = fermat(x, y / 2);
	F *= F;
	F %= mod;
	if (y % 2)return(F*x) % mod;
	else return F;
}

void init(int n){
    kai[0] = 0;
    kai[1]=1;
    for(int i=2;i<=n;i++){
        kai[i]=kai[i-1]*i%mod;
    }
    F[n]=fermat(kai[n],mod-2);
    for(int i=n;i>0;i--){
        F[i-1]=(F[i]*i)%mod;
    }
    F[0] = 1;
}

int main(){
    cin >> N >> M >> K;
    ll ok = 0;
    init(N * M);
    ll sum = 0;
    for(ll i = 1; i <= N; i++){
        sum += i * (i - 1) * M * M / 2;
        sum %= mod;
    }
    for(ll i = 1; i <= M; i++){
        sum += i * (i - 1) * N * N / 2;
        sum %= mod;
    }
    sum *= fer(N * M - 2, K - 2);
    sum %= mod;
    cout << sum << endl;
    return 0;
}