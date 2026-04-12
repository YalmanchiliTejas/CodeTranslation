#include <bits/stdc++.h>
using namespace std;
using LL  = long long;
using VI  = vector<LL>;
using VVI = vector<VI>;
using VB  = vector<bool>;
using VS  = vector<string>;
using PII = pair<LL, LL>;
using VP  = vector<PII>;
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first < y.first;});
#define FRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first > y.first;});
#define SSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second < y.second;});
#define SRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second > y.second;});
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define $(x) {cout << #x << " = " << (x) << endl;}


int main() {
    LL N;
    cin >> N;
    VI a(N);
    REP(i, N) cin >> a[i];

    VVI dp(N + 1, VI(N + 1));
    FOR(len, 1, N + 1) {
        for (LL i = 0; i + len < N + 1; ++i) {
            LL j = i + len;
            if ((N - len) % 2 == 0) {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
            } else {
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
            }
        }
    }
    cout << dp[0][N] << endl;
	
    return 0;
}
