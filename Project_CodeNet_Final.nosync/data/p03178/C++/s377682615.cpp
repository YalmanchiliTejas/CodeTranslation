#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7; 

int num(char a) {
    return a - '0';
}

int main() {
    string k;
    int d, n;
    cin >> k >> d;
    n = k.length();

    vector <vector <vector <int> > > dp(n, vector <vector <int> > (d, vector <int> (2, 0)));

    dp[0][num(k[0]) % d][1] = 1;
    for (int i = num(k[0]) - 1; i >= 0; i--) {
            dp[0][i % d][0]++;
    }

    int rrem, critical_digit;
    for (int i = 0; i < n - 1; i++) {
        critical_digit = num(k[i + 1]);
        for (int rem = 0; rem < d; rem++) {
            for (int dig = 0; dig < 10; dig++) {
                rrem = (rem + dig) % d;
                dp[i + 1][rrem][0] = (dp[i + 1][rrem][0] + dp[i][rem][0]) % MOD;
                if (dig < critical_digit)
                    dp[i + 1][rrem][0] = (dp[i + 1][rrem][0] + dp[i][rem][1]) % MOD;
            }
            rrem = (rem + critical_digit) % d;
            dp[i + 1][rrem][1] = (dp[i + 1][rrem][1] + dp[i][rem][1]) % MOD;
        }
    }

    if (dp[n - 1][0][0] + dp[n - 1][0][1] == 0)
        cout << MOD - 1 << '\n';
    else
        cout << dp[n - 1][0][0] + dp[n - 1][0][1] - 1 << '\n';
    return 0;
}