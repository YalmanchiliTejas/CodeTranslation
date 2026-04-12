#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD 998244353

ll N,S;
ll A[3030];
ll dp[3030][3030];

ll i, j, k;
int main(){
    scanf("%lld%lld", &N,&S);
    fornum(i,0,N){
        scanf("%lld", &A[i]);
    }
    ll ans=0;
    dp[0][0] = 1;
    fornum(i,0,N){
        dp[i + 1][0] = 1;
        fornum(j,0,S){
            if(j+A[i]<S){
                dp[i + 1][j + A[i]] += dp[i][j];
                dp[i + 1][j + A[i]] %= MOD;
            }
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
        if(S<A[i])
            continue;
        ans += dp[i][S - A[i]] * (N - i) % MOD;
        ans %= MOD;
    }
    printf("%lld", ans);

    return 0;
}