#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define INF 1e18
ll N,K;
ll A[202020];
ll dp[202020][5];
ll i, j, k,ans;

int main(){
    scanf("%lld", &N);
    fornum(i,0,N){
        scanf("%lld", &A[i]);
    }
    fornum(i,0,N+8){
        fornum(j,0,4){
            dp[i][j] = -INF;
        }
    }
    if(N%2==0){
        dp[0][1] = 0;
    }else{
        dp[0][2] = 0;
    }
    fornum(i,0,N){
        fornum(j,0,3){
            dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + A[i]);
            if(j>0){
                dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
            }
        }
    }
    printf("%lld\n", max(dp[N - 1][2], max(dp[N][1], dp[N + 1][0])));

    return 0;
}