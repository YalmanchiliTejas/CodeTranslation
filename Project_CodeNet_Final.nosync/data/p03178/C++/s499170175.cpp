#include <iostream>
#include <cstring>
using namespace std;

const int maxN = 1e5+1;
const int maxMod = 101;
const long long MOD = 1e9+7;

int n,d;
char str[maxN];

long long dp[maxN][maxMod][2];

int main(){
    cin >> (str+1) >> d;
    n = strlen(str+1);
    
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        int digit = str[i+1] - '0';
        for(int j = 0; j < d; j++){
            for(int dig = 0; dig < 10; dig++){
                dp[i+1][(j+dig) % d][1] = (dp[i+1][(j+dig) % d][1] + dp[i][j][1]) % MOD;
            }
            for(int dig = 0; dig < digit; dig++){
                dp[i+1][(j+dig) % d][1] = (dp[i+1][(j+dig) % d][1] + dp[i][j][0]) % MOD;
            }

            dp[i+1][(j+digit) % d][0] = (dp[i+1][(j+digit) % d][0] + dp[i][j][0]) % MOD;
        }
    }

    cout<<(dp[n][0][0] + dp[n][0][1] + MOD - 1) % MOD;

    return 0;
}