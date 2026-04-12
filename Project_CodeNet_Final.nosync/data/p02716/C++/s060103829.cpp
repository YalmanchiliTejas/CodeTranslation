#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N);
    for (int i=0;i<N;++i) cin >> A[i];
    vector<vector<ll>> dp(N+1,vector<ll>(4,-INF));
    dp[0][(N&1?0:2)]=0;
    for (int i=0;i<N;++i){
        dp[i+1][1]=max(dp[i+1][1],dp[i][0]);
        dp[(min(N,i+2))][0]=max(dp[(min(N,i+2))][0],dp[i][0]+A[i]);
        dp[(min(N,i+2))][2]=max(dp[(min(N,i+2))][2],dp[i][1]+A[i]);
        dp[(min(N,i+2))][2]=max(dp[(min(N,i+2))][2],dp[i][2]+A[i]);
        dp[(min(N,i+2))][3]=max(dp[(min(N,i+2))][3],dp[i][1]+A[i+1]);
        dp[(min(N,i+2))][3]=max(dp[(min(N,i+2))][3],dp[i][2]+A[i+1]);
        dp[(min(N,i+2))][3]=max(dp[(min(N,i+2))][3],dp[i][3]+A[i+1]);
    }
    cout << max({dp[N][1],dp[N][2],dp[N][3]}) << '\n';
}