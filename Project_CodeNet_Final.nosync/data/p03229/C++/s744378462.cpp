#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

template <typename T> ll sum(const T first, const T last) {
    ll t = 0;
    for (auto it = first; it != last; it++) {
        t += *it;
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(ALL(a));

    ll t;
    ll t1 = 0;
    ll t2 = 0;
    if (n % 2 == 1) {
        for (int i = 0; i < n / 2; i++) {
            t1 += a[i];
        }
        for (int i = n / 2 + 1; i < n; i++) {
            t2 += a[i];
        }
        t = max({
            (t1 * 2 + a[n / 2] * 2 - (a[n / 2] + a[n / 2 - 1])) - (t2 * 2),
            (t2 * 2) - (t1 * 2 + a[n / 2] * 2 - (a[n / 2] + a[n / 2 - 1])),
            (t2 * 2 + a[n / 2] * 2 - (a[n / 2] + a[n / 2 + 1])) - (t1 * 2),
            (t1 * 2) - (t2 * 2 + a[n / 2] * 2 - (a[n / 2] + a[n / 2 + 1]))
        });

    } else {
        for (int i = 0; i < n / 2; i++) {
            t1 += a[i];
        }
        for (int i = n / 2; i < n; i++) {
            t2 += a[i];
        }
        t = max({
            t1 * 2 - t2 * 2 - a[n / 2 - 1] + a[n / 2],
            t2 * 2 - t1 * 2 - a[n / 2] + a[n / 2 - 1]
        });
    }
 
    cout << t << endl;
}
