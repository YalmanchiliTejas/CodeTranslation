#include<bits/stdc++.h>
#define REP(i,x) for(int i=0,i##_len=(x);i<i##_len;++i)
#define rep(i,a,b) for(int i=(a),i##_len(b);i<i##_len;++i)
#define All(x) begin(x),end(x)
#define rAll(x) rbegin(x),rend(x)
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    vector<ll> A(N);
    REP(i,N) cin>>A[i];
    const ll inf = 1e18;
    vector<vector<ll>> dp(N/2+2,vector<ll>(2,-inf));
    dp[0][0]=0;
    REP(i,N) for(int j=i/2+1;j>=max(i/2-3,0);--j){
        dp[j][0]=max(dp[j][0],dp[j][1]);
        if(j>0) dp[j][1]=max(dp[j][1],dp[j-1][0]+A[i]);
        //cerr<<i<<" "<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
    }
    cout<<max(dp[N/2][0],dp[N/2][1])<<endl;
}