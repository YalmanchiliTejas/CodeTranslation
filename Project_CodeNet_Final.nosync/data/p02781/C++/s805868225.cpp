#include<iostream>
#include<string>
using namespace std;

int main() {
    string S;
    int K;
    cin>>S;
    cin>>K;
    // dp[桁][未満][ゼロでない個数]
    long dp[S.size()][2][K+1];
    for(int i=0;i<S.size();++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<=K;++k){
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][1] = 1;
    for(int i=0;i<S.size();++i){
        dp[i][1][0] = 1;
    }
    dp[0][1][0] = 1;
    dp[0][1][1] = S[0] - '0' - 1;
    for(int i=1;i<S.size();++i){
        for(int k=1;k<=K;++k){
            if(S[i]=='0'){
                dp[i][0][k] = dp[i-1][0][k];
                dp[i][1][k] = dp[i-1][1][k] + dp[i-1][1][k-1]*9;
            }
            else{
                dp[i][0][k] = dp[i-1][0][k-1];
                dp[i][1][k] = dp[i-1][0][k-1]*(S[i]-'0'-1) + dp[i-1][1][k-1]*9 + dp[i-1][1][k] + dp[i-1][0][k];
            }
        }
    }
    /**
    for(int i=0;i<S.size();++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<=K;++k){
                cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
            }
        }
    }
    **/
    cout<<dp[S.size()-1][1][K]+dp[S.size()-1][0][K]<<endl;
}
