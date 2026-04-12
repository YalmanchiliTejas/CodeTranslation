#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    string N;
    int K;
    cin>>N>>K;
    int n=N.size();
    ll dp[101][2][4]={};
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        int a=N[i]-'0';
        for(int j=0;j<=K;j++){
            for(int x=0;x<=9;x++){
                if(x==0){
                    dp[i+1][1][j]+=dp[i][1][j];
                    if(x==a){
                        dp[i+1][0][j]+=dp[i][0][j];
                    }
                    else if(x<a){
                        dp[i+1][1][j]+=dp[i][0][j];
                    }
                }
                else{
                    if(j==K) continue;
                    dp[i+1][1][j+1]+=dp[i][1][j];
                    if(x==a){
                        dp[i+1][0][j+1]+=dp[i][0][j];
                    }
                    else if(x<a){
                        dp[i+1][1][j+1]+=dp[i][0][j];
                    }
                }
            }
        }
    }
    cout<<dp[n][0][K]+dp[n][1][K]<<endl;
}