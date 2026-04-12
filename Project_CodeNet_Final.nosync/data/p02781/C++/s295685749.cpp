#include <bits/stdc++.h>
using namespace std;
using  ll = long long;

int main(){
    string n;
    int k;
    cin >> n >> k;

    ll dp[101][5][2] = {}; // dp[i桁目][0以外の個数(4以上はカウント不要)][strict]
    dp[0][0][1] = 1;
    for(int i=1;i<=n.size();i++){
        int x = n[i-1] - '0';
        for(int j=0;j<=9;j++){
            for(int p = 0;p<4;p++){
                // strict
                if(j == x){
                    dp[i][(j == 0?p:p+1)][1] += dp[i-1][p][1];
                }else if(j < x){
                    dp[i][(j == 0?p:p+1)][0] += dp[i-1][p][1];
                }
                // not strict
                dp[i][(j == 0?p:p+1)][0] += dp[i-1][p][0];
            }
        }
    }
    cout << dp[n.size()][k][0] + dp[n.size()][k][1] << endl;
}