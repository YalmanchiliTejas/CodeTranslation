//Educational DP Contest S-Digit Sum
#include<bits/stdc++.h>
#include<cstring>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int D;
string K;
ll dp[10005][2][105];

int main(){
    cin >> K >> D;
    int l = K.size();

    dp[0][0][0] = 1;

    for(int i = 0; i < l; i++){
        int ni = K[i] - '0';
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < D; k++){
                for(int x = 0; x <= ( j ? 9 : ni ); x++){
                    dp[i+1][j || ( x < ni )][ (x + k) % D ] += dp[i][j][k];
                    dp[i+1][j || ( x < ni )][ (x + k) % D ] %= MOD;
                }
            }
        }
    }
    
    ll ans = dp[l][0][0] + dp[l][1][0] - 1;
    cout << ( ans<0 ? ans+MOD : ans ) <<endl;
    
    return 0;
}