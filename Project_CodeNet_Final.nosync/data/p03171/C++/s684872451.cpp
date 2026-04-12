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
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    for (int i = 0; i <= N; ++i)
        dp[i][i] = 0;
    for (int w = 1; w <= N; ++w) {
        for (int l = 0; l + w <= N; ++l) {
            int r = l + w;
            int cnt = N - w;
            if (cnt & 1)
                dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
            else
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
        }
    }

    cout << dp[0][N] << endl;

    return 0;
}
