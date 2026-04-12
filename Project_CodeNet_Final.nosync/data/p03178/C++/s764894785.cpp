#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long dp[10001][100][2];
int main()
{
    string K; cin >> K;
    vector<int> N;
    for (char c : K) N.push_back(c-'0');
    reverse(begin(N), end(N));
    int D; cin >> D;
    for (int i = 0; i < 10; i++) dp[0][i%D][0]++;
    for (int i = 0; i <= N[0]; i++) dp[0][i%D][1]++;
    for (int i = 1; i < N.size(); i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < D; k++) {
                (dp[i][(k+j)%D][0] += dp[i-1][k][0]) %= MOD;
            }
        }
        for (int j = 0; j <= N[i]; j++) {
            for (int k = 0; k < D; k++) {
                (dp[i][(k+j)%D][1] += dp[i-1][k][j==N[i]]) %= MOD;
            }
        }
    }
    cout << (dp[K.size()-1][0][1] + MOD - 1) % MOD << endl;
    return 0;
}