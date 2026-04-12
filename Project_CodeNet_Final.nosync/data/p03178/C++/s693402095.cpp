#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll dp[10010][2][105];

int main(){
    string k;
    cin >> k;
    ll ks = k.size(), i, j;
    ll d;
    cin >> d;
    dp[0][0][0] = 1;
    for(i = 0; i < ks; i++) { //i文字目
        for(j = 0; j < d; j++) { // Kと一致している時
            //dp[i + 1][0][j] = (dp[i + 1][0][j] + dp[i][0][j]) % MOD;
            dp[i + 1][0][(j + (k[i] - '0')) % d] = (dp[i + 1][0][(j + k[i] - '0') % d] + dp[i][0][j]) % MOD;
        }
        for(j = 0; j < d;j++){
            for(int x = 0; x < k[i] - '0';x++){
                dp[i + 1][1][(j + x) % d] = (dp[i + 1][1][(j + x) % d] + dp[i][0][j]) % MOD;
            }
            for(int x = 0; x < 10;x++){
                dp[i + 1][1][(j + x) % d] = (dp[i + 1][1][(j + x) % d] + dp[i][1][j]) % MOD;
            }
        }
    }
    cout << (dp[ks][0][0] + dp[ks][1][0] - 1 + MOD) % MOD << endl;
    return 0;
}