#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 998244353;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    vector<vector<ll>> dp(N + 1, vector<ll>(S + 1));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        for (int j = 0; j <= S; ++j) {
            dp[i + 1][j] += dp[i][j];
            if (j >= A)
                dp[i + 1][j] += dp[i][j - A];
            dp[i + 1][j] %= MOD;
        }
        dp[i + 1][0]++;
    }

    ll ans = 0;
    for (int i = 0; i <= N; ++i)
        ans += dp[i][S];
    cout << ans % MOD << endl;

    return 0;
}
