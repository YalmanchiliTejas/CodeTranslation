#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

ll dp[101][4][2];
string s;
int n,K;
int main(){
    cin>>s>>K;
    n=s.size();
    dp[0][0][0]=1;
    rep(i,n)rep(j,4)rep(k,2){
        int t=s[i]-'0';
        if(k==1){
            if(j<3)dp[i+1][j+1][1]+=dp[i][j][1]*9;
            dp[i+1][j][1]+=dp[i][j][1];
        }
        else{
            dp[i+1][j][t==0?0:1]+=dp[i][j][k];
            if(j<3&&t>0){
                dp[i+1][j+1][1]+=dp[i][j][k]*(t-1);
                dp[i+1][j+1][k]+=dp[i][j][k];
            }
        }
    }
    cout<<dp[n][K][0]+dp[n][K][1]<<endl;
    return 0;
}