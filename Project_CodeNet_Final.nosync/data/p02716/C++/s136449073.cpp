#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long

signed main(){
    int N;
    cin >>N;
    int vec[N+1];
  	vec[0]=0;
    REP(i,N){
        cin>>vec[i+1];
    }
    vector<vector<int>>dp(N+1,vector<int>(2,0));
    dp[1][1]=vec[1];
    dp[2][1]=max(vec[1],vec[2]);
    for(int i=3;i<=N;i++){
        if(i%2==1){
            dp[i][0]=max(dp[i-2][0]+vec[i],dp[i-1][1]);
            dp[i][1]=dp[i-2][1]+vec[i];
        }
        else{
            dp[i][0]=max(dp[i-2][0]+vec[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-2][1]+vec[i],dp[i-1][1]);
        }
    }
	cout<<dp[N][(N+1)%2]<<endl;
}
