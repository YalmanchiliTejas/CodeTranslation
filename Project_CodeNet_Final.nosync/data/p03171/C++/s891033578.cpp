#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = (1 << 30);
constexpr ll L_INF = (1ll << 62);

//==================================

ll dp[3010][3010] = {};
bool checked[3010][3010] = {};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    Vl a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            bool f_Taro = ((N - (j - i)) & 1) == 1;
            if (f_Taro) {
                dp[i][j] = L_INF;
            }
            else {
                dp[i][j] = -L_INF;
            }
        }
    }

    queue<Pii> q;
    for (int i = 0; i <= N; ++i) {
        dp[i][i] = 0;
        checked[i][i] = true;
        q.emplace(i, i);
    }
    while (!q.empty()) {
        int l, r;
        tie(l, r) = q.front();
        q.pop();

        bool f_Taro = ((N - (r - l)) & 1) == 1;

        int nl, nr;
        if (f_Taro) {
            nl = l - 1;
            nr = r;
            if (nl >= 0) {
                dp[nl][nr] = max(dp[nl][nr], dp[l][r] + a[nl]);
                if (!checked[nl][nr]) {
                    checked[nl][nr] = true;
                    q.emplace(nl, nr);
                }
            }

            nl = l;
            nr = r + 1;
            if (nr <= N) {
                dp[nl][nr] = max(dp[nl][nr], dp[l][r] + a[nr - 1]);
                if (!checked[nl][nr]) {
                    checked[nl][nr] = true;
                    q.emplace(nl, nr);
                }
            }
        }
        else {
            nl = l - 1;
            nr = r;
            if (nl >= 0) {
                dp[nl][nr] = min(dp[nl][nr], dp[l][r] - a[nl]);
                if (!checked[nl][nr]) {
                    checked[nl][nr] = true;
                    q.emplace(nl, nr);
                }
            }

            nl = l;
            nr = r + 1;
            if (nr <= N) {
                dp[nl][nr] = min(dp[nl][nr], dp[l][r] - a[nr - 1]);
                if (!checked[nl][nr]) {
                    checked[nl][nr] = true;
                    q.emplace(nl, nr);
                }
            }
        }
    }

    cout << dp[0][N] << endl;

    return 0;
}