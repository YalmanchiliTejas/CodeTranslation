#include <bits/stdc++.h>
using namespace std;
long long dp[110][2][110];
int main(){
    string N;
    cin >> N;
    int K; cin >> K;
    int l = N.size();
    dp[0][0][0] = 1;
    for(int i=0;i<l;++i){
        int D = N[i] - '0';
        for(int j=0;j<2;++j){
            for(int k=0;k<l;++k){
                for(int d=0;d<=(j ? 9:D);++d){
                    dp[i+1][j||(d<D)][d==0 ? k:(k+1)] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[l][0][K] + dp[l][1][K] << endl;
    return 0;
}