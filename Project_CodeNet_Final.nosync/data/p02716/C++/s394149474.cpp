#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n)
    {
        cin >> a[i];
    }
    if (n % 2 == 0) {
        vector<vector<ll>> memo(2, vector<ll>(n / 2, 0));
        REP(i, n / 2)
        {
            if (i == 0) {
                memo[0][i] = a[i];
                memo[1][i] = a[i + 1];
            } else {
                memo[0][i] = memo[0][i - 1] + a[i * 2];
                memo[1][i] = max(memo[0][i - 1] + a[i * 2 + 1], memo[1][i - 1] + a[i * 2 + 1]);
            }
        }
        cout << max(memo[0][n / 2 - 1], memo[1][n / 2 - 1]);
    } else {
        vector<vector<ll>> memo(3, vector<ll>(n / 2, 0));
        REP(i, n / 2)
        {
            if (i == 0) {
                memo[0][i] = a[i];
                memo[1][i] = a[i + 1];
                memo[2][i] = a[i + 2];
            } else {
                memo[0][i] = memo[0][i - 1] + a[i * 2];
                memo[1][i] = max(memo[0][i - 1] + a[i * 2 + 1], memo[1][i - 1] + a[i * 2 + 1]);
                memo[2][i] = max(memo[0][i - 1] + a[i * 2 + 2], memo[1][i - 1] + a[i * 2 + 2]);
                memo[2][i] = max(memo[2][i], memo[2][i - 1] + a[i * 2 + 2]);
            }
        }
        ll ans = max(memo[0][n / 2 - 1], memo[1][n / 2 - 1]);
        ans = max(ans, memo[2][n / 2 - 1]);
        cout << ans << endl;
    }
}