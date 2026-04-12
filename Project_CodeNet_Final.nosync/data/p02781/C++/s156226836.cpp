#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    string N;cin>>N;
    int K;cin>>K;
    vector<vector<vector<ll>>> dp(N.size(),vector<vector<ll>>(K+1,vector<ll>(2,0)));
    dp[0][0][0]=1;
    dp[0][1][0]=N[0]-'0'-1;
    dp[0][1][1]=1;
    rep(i,1,N.size()){
        REP(j,K+1){
            dp[i][j][0]+=dp[i-1][j][0];
            if(N[i]!='0'){
                dp[i][j][0]+=dp[i-1][j][1];
                if(j>0){
                    dp[i][j][0]+=(N[i]-'0'-1)*dp[i-1][j-1][1];
                    dp[i][j][1]+=dp[i-1][j-1][1];
                }
            }
            else dp[i][j][1]+=dp[i-1][j][1];
            if(j>0) dp[i][j][0]+=9*dp[i-1][j-1][0];
            // cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
    }
    cout<<dp[N.size()-1][K][0]+dp[N.size()-1][K][1]<<endl;
}