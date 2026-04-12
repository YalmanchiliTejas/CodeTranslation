//============================================================================
// Name        : s
// Date        : Tue Mar  5 16:14:07 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define ford(i, a, b) for (int i = a; i > b; --i)
#define output(v) cout << (v) << '\n'
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef __has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = (int) 1e5 + 7;
const int mod = (int) 1e9 + 7;

// Digit dp problem

// dp[i][sum][0]: have not see a smaller digit from leftmost(0) till i
// dp[i][sum][1]: already see a smaller digit till i
int dp[maxn][127][2];

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void solve() {
    string k; int d;
    cin >> k >> d;

    int n = sz(k);
    dp[0][0][0] = 1;
    fori (i, 1, n + 1) {
        fori (sum, 0, d + 1) {
            for (bool sm_already : {false, true}) {
                for (int digit = 0; digit < 10; ++digit) {
                    if (digit > k[i - 1] - '0' && !sm_already) {
                        break;
                    }
                    add(dp[i][(sum + digit) % d][sm_already || (digit < k[i-1]-'0')], dp[i-1][sum][sm_already]);
                }
            }
        }
    }
    int ret = (dp[n][0][0] + dp[n][0][1]) % mod;
    --ret;
    if (ret == -1) {
        ret = mod - 1;
    }
    output(ret);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

