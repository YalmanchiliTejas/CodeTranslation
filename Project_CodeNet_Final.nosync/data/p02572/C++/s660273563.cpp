#include<bits/stdc++.h>

#define ll long long
#define rep(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

#define fi first
#define se second
#define all(A) A.begin(),A.end()

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)

ll N;
ll A[202020];

ll i, j, k;

int main(){
    scanf("%lld", &N);
    rep(i,0,N){
        scanf("%lld", &A[i]);
    }
    ll ans = 0;
    j = 0;
    rep(i,0,N){
        ans += A[i] * j;
        ans %= MOD;
        j += A[i];
        j %= MOD;
    }

    printf("%lld\n", ans);
    return 0;
}