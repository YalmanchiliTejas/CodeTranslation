#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD ((ll)1e9+7)

ll N,M,K,fa[202020];
ll i, j, k,l;

ll moddiv(ll a,ll b){
    for(ll m=MOD-2;m>0;m/=2){
        if(m&1){
            a=a*b%MOD;
        }
        b=b*b%MOD;
    }
    return a;
}


int main(){
    scanf("%lld%lld%lld", &N,&M,&K);
    fa[0] = 1;
    fornum(i,0,N*M){
        fa[i + 1] = fa[i] * (i + 1)%MOD;
    }
    ll n = moddiv(((N * (N + 1) % MOD * (2 * N + 1) % MOD) + MOD - (3 * N * (N + 1) % MOD)) % MOD, 12) * M%MOD*M % MOD;
    ll m = moddiv(((M * (M + 1) % MOD * (2 * M + 1) % MOD) + MOD - (3 * M * (M + 1) % MOD)) % MOD, 12) * N%MOD*N % MOD;
    //printf("%lld %lld ", n, m);
    printf("%lld", (n + m) % MOD * moddiv(fa[N * M - 2], fa[K - 2] * fa[N * M - K] % MOD) % MOD);
    return 0;
}
