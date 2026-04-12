#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=1e9+7;
signed main(){
    int dp[102][2][4]={};
    dp[0][0][0]=1;
    string n;
    int K;
    cin>>n>>K;
    for(int i=0;i<n.size();i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<4;k++)
                for(int x=0;x<=(j?9:n[i]-'0');x++)
                    if(k!=3||x==0)
                        dp[i+1][j||x<n[i]-'0'][k+(x!=0)]+=dp[i][j][k];
    cout<<dp[n.size()][0][K]+dp[n.size()][1][K]<<endl;
}
