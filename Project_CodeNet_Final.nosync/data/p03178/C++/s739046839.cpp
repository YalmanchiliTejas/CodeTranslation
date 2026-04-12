#include <iostream>
#include <fstream>
#include <map>

#define MOD 1000000007
#define f cin


using namespace std;

//ifstream f("date.in");
string k;
long long int d;

long long int dp[10010][110][3];

int main() {

    f >> k >> d;
    long long int n = k.size();
    for (long long int i = 0; i < k[0] - '0'; ++i) {
        dp[1][i % d][0] ++;
    }
    dp[1][(k[0] - '0') % d][1] ++;
    for (long long int i = 2; i <= n; ++i) {
        for (long long int j = 0; j < d; ++j) {
            for (long long int k1 = 0; k1 < 10; ++k1) {
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][(j + 10 * d - k1) % d][0]) % MOD;
            }
            //cout << dp[1][0][0] << "\n";
            for (long long int k1 = 0; k1 < (k[i - 1] - '0'); ++k1) {
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][(j + 10 * d - k1) % d][1]) % MOD;
            }
            long long int curr_digit = k[i - 1] - '0';
            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][(j + 10 * d - curr_digit) % d][1]) % MOD;
        }
    }

    long long int ans = (dp[n][0][0] + dp[n][0][1]) % MOD;
    // int ans = (dp[n][0][0]) % MOD;

    /*for (long long int i = 1; i <= n; ++i) {
        for (long long int j = 0; j < d; ++j) {
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }*/
    //cout << dp[n - 1][0][0] << "\n";

    ans = (ans + MOD - 1) % MOD;
    cout << ans << " ";
	return 0;
}
