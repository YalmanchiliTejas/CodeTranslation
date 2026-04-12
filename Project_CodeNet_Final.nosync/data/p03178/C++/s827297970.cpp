#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;

int main(){
    string K;
    int D;
    cin >> K;
    cin >> D;

    ll dp[K.size()+1][D][2] = {};
    dp[0][0][0] = 1;
    // cerr << "start" << endl;
    for(int i=0;i<K.size();i++){
        // cerr << "i = " << i << endl;
        int t = K[i] -'0';
        for(int j=0;j<D;j++){
            // cerr <<"j=" << j <<endl;
            dp[i+1][(j+t)%D][0] += dp[i][j][0]; 
            dp[i+1][(j+t)%D][0] %= MOD;
            for(int d=0;d<10;d++){
                if(d <t){
                    dp[i+1][(j+d)%D][1] += dp[i][j][0];
                    dp[i+1][(j+d)%D][1] %= MOD;
                }
                dp[i+1][(j+d)%D][1] += dp[i][j][1];
                dp[i+1][(j+d)%D][1] %= MOD;
                // cerr <<"d= " << d << "val = " << dp[i+1][(j+d)%D][1] << endl;
            }
            // cerr << "i="  <<i << ", 0val =" << dp[i+1][0][0] << endl;
            // cerr << "i="  <<i << ", 1val =" << dp[i+1][0][1] << endl;
        }
    }
    cout << (dp[K.size()][0][1] +  dp[K.size()][0][0]-1 + MOD) % MOD << endl;
    return 0;
}
