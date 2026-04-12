#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep (i, n) cin >> a[i];
    sort (a, a + n);
    ll ans = 0;
    if (n % 2 == 0) {
        rep (i, n) {
            if (i < n / 2 - 1) ans -= a[i] * 2;
            else if (i == n / 2 - 1)
                ans -= a[i];
            else if (i == n / 2 && n % 2 == 0)
                ans += a[i];
            else if (i == n / 2 && n % 2 == 1)
                ans -= a[i];
            else
                ans += 2 * a[i];
        }
    } else {
        ll sum1 = 0, sum2 = 0;
        rep (i, n) {
            if (i < n / 2 - 1) ans -= a[i] * 2;
            else if (i == n / 2 - 1) {
                sum1 -= a[i];
                sum2 -= 2 * a[i];
            } else if (i == n / 2) {
                sum1 -= a[i];
                sum2 += a[i];
            } else if (i == n / 2 + 1) {
                sum1 += 2 * a[i];
                sum2 += a[i];
            } else
                ans += 2 * a[i];
        }
        ans += max (sum1, sum2);
    }
    cout << ans << "\n";
}