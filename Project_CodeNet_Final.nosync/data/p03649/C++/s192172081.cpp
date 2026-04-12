#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define RFOR(i, l, r) for (int i = (int)(r); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vll a(n);
    REP(i, n) cin >> a[i];

    ll ans = 0;
    while (true) {
        ll s = 0;
        REP(i, n) {
            s += a[i] / n;
        }
        if (s == 0) break;
        REP(i, n) {
            ll x = s - a[i] / n;
            a[i] %= n;
            a[i] += x;
        }
        ans += s;
    }

    cout << ans << endl;

    return 0;
}