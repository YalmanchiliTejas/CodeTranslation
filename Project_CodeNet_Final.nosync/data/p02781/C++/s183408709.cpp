#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int N=s.size();
    int K; cin >> K;
    long long dp[N+1][2][101]={};
    dp[0][1][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            int d=s[i]-'0';
            dp[i+1][0][j+1]+=dp[i][0][j]*9;
            dp[i+1][0][j]+=dp[i][0][j];
            if(d==0){
                dp[i+1][1][j]+=dp[i][1][j];
            }else{
                dp[i+1][1][j+1]+=dp[i][1][j];
                dp[i+1][0][j+1]+=dp[i][1][j]*(d-1);
                dp[i+1][0][j]+=dp[i][1][j];
            }
        }
    }
    cout << dp[N][0][K]+dp[N][1][K] << endl;
}