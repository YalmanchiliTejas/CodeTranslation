#include<iostream>
using namespace std;
int main(){
    string N;int K;
    cin>>N>>K;
    int dp[N.size()+1][2][K+1];
    for(int i=0;i<=N.size();i++)for(int j=0;j<=1;j++)for(int k=0;k<=K;k++)dp[i][j][k]=0;
    dp[0][0][0]=1;
    for(int i=1;i<=N.size();i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=K;k++){
                for(int d=0;d<=(j?9:N[i-1]-'0');d++){
                    if(k==K&&d!=0)continue;
                    dp[i][j||d<N[i-1]-'0'][k+(!!d)]+=dp[i-1][j][k];
                }
            }
        }
    }
    cout<<dp[N.size()][0][K]+dp[N.size()][1][K]<<endl;
    return 0;
}