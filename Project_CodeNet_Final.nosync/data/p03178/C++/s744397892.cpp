#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    string s;
    int d;
    cin>>s>>d;
    int n=s.size();
    ll dp[n+1][2][d];
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        int num=s[i]-'0';
        for(int j=0;j<2;j++){
            for(int k=0;k<d;k++){
                for(int l=0;l<=(j?9:num);l++){
                    dp[i+1][j||l<num][(k+l)%d]+=dp[i][j][k];
                    dp[i+1][j||l<num][(k+l)%d]%=MOD;
                }
            }
        }
    }
    cout<<(dp[n][0][0]+dp[n][1][0]+MOD-1)%MOD<<endl;
}