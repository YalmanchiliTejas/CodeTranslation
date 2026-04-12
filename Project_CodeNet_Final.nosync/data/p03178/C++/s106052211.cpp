#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll dp[10002][2][100];

int main() {
    string s;
    int d, n;
    cin >> s >> d;
    int sn = s.length();

    dp[0][1][0] = 1;
    for(int i=0;i<sn;++i) {
        n = s[i] - '0';
        for(int j=0;j<d;++j) {
            if(dp[i][0][j]) {
                for(int k=0;k<10;++k) {
                    dp[i+1][0][(j+k)%d] += dp[i][0][j];
                    dp[i+1][0][(j+k)%d] %= MOD;
                }
            }
            if(dp[i][1][j]) {
                for(int k=0;k<n;++k) {
                    dp[i+1][0][(j+k)%d] += dp[i][1][j];
                    dp[i+1][0][(j+k)%d] %= MOD;
                }
                dp[i+1][1][(j+n)%d] += dp[i][1][j];
                dp[i+1][1][(j+n)%d] %= MOD;
            }
        }
    }

    cout << (dp[sn][0][0] + dp[sn][1][0] + MOD - 1) % MOD << "\n";
}