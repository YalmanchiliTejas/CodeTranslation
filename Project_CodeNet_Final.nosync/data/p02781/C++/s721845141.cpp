#include <bits/stdc++.h>

using namespace std;

const int N = 105;

string n;
int k;

long long dp[N][2][5];

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dp[0][1][0] = 1;
    for (int pos = 0; pos < n.length(); pos++) {
        for (int high = 0; high < 2; high++) {
            for (int num = 0; num <= k; num++) {
                int lim = 9;
                if (high) lim = n[pos] - '0';
                for (int dig = 0; dig <= lim; dig++) {
                    int nhigh = 0;
                    if (high && dig == n[pos] - '0') nhigh = 1;
                    dp[pos + 1][nhigh][num + (dig != 0)] += dp[pos][high][num];
                }
            }
        }
    }
    
    cout << dp[(int)n.length()][0][k] + dp[(int)n.length()][1][k];
    return 0;
}