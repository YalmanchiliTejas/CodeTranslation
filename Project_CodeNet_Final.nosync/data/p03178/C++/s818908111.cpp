#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

constexpr ll MOD = 1e9 + 7;

int main() {
    string k;
    int d;
    cin >> k >> d;

    vector<vector<ll>> dp(d, vector<ll>(2));
    dp[0][true] = 1;
    for (int i = 0; i < k.size(); i++) {
        int here = k[i] - '0';

        vector<vector<ll>> after(d, vector<ll>(2));
        for (int prevmod = 0; prevmod < d; prevmod++) {
            for (int now = 0; now <= 9; now++) {
                int nowmod = (prevmod + now) % d;
                if (now < here) {
                    after[nowmod][false] += dp[prevmod][true], after[nowmod][false] %= MOD;
                } else if (now == here) {
                    after[nowmod][true] += dp[prevmod][true], after[nowmod][true] %= MOD;
                }
                after[nowmod][false] += dp[prevmod][false], after[nowmod][false] %= MOD;
            }
        }
        dp = after;
    }

    cout << (dp[0][true] + dp[0][false] - 1 + MOD) % MOD << endl;
    return 0;
}