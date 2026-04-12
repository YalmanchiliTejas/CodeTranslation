/*
Author : Xinyuan
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef long long int ll;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

const int nax = 10123;
char k[nax];
void add_self(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int main() {
    scanf("%s", k);
    int D = nxt();
    int len = strlen(k);
    VVI dp(D, VI(2));
    dp[0][0] = 1;
    for (int where = 0; where < len; where++) {
        VVI new_dp(D, VI(2));
        for (int sum = 0; sum < D; sum++) {
            for (bool sm_already : {false, true}) {
                for (int digit = 0; digit < 10; digit++) {
                    if (digit > k[where] - '0' && !sm_already) break;
                    add_self(new_dp[(sum + digit) % D][sm_already || (digit < k[where] - '0')],
                             dp[sum][sm_already]);
                }
            }
        }
        dp = new_dp;
    }
    int answer = (dp[0][false] + dp[0][true]) % mod;
    answer--;
    if (answer == -1) answer = mod - 1;
    printf("%d\n", answer);
    return 0;
}