#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forlr(i, l, r) for (int i = int(l); i < int(r); i++)
#define repeat(n) for (int hjfjke = 0; hjfjke < int(n); hjfjke++)
#define all(c) c.begin(), c.end()
#define ll long long

long long dp[3050][3050];
int a[3050];

int32_t main() {
    std::iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int n, k;
    cin >> n;
    forn(i, n) cin >> a[i];

    for (int i = 0; i < n; i++)
        dp[i][i] = (n % 2 == 1 ? 1 : -1) * a[i];

    forlr(l, 2, n + 1) {
        forn (i, n) {
            int j = i + l - 1;
            if (j >= n)
                continue;

            int who = ((n + l) % 2 == 0 ? 1 : -1);

            if (who == 1)
                dp[i][j] = max(dp[i][j - 1] + a[j], dp[i + 1][j] + a[i]);
            else
                dp[i][j] = min(dp[i][j - 1] - a[j], dp[i + 1][j] - a[i]);
        }
    }
    cout << dp[0][n - 1];

    return 0;
}