#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf=1e18;

int main(){
    int N; cin >> N;
    ll a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int M=N%2+1;
    vector<vector<ll>> dp(N+10,vector<ll>(M+1,-inf));
    dp[0][0]=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<M;j++){
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
        }
        for(int j=0;j<=M;j++){
            dp[i+2][j]=max(dp[i+2][j],dp[i][j]+a[i]);
        }
    }
    cout << dp[N+1][M] << endl;
}