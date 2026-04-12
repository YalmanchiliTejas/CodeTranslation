// https://atcoder.jp/contests/abc115/tasks/abc115_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define EPS (1e-9)
#define INF (1e9)
#define INFL (1e18)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define BIT(n) (1LL << (n))
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

ll blen[51], plen[51];
ll rec(ll n, ll x) {
    ll len = blen[n - 1];
    ll num = plen[n - 1];
    if (n == 0)
        return 1;
    if (x == 1)
        return 0;
    else if (x <= len + 1)
        return rec(n - 1, x - 1);
    else if (x == len + 2)
        return num + 1;
    else if (x <= (len + 1) * 2)
        return num + 1 + rec(n - 1, x - len - 2);
    else
        return num * 2 + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    blen[0] = 1;
    plen[0] = 1;
    REP(i, 50) {
        blen[i + 1] = blen[i] * 2 + 3;
        plen[i + 1] = plen[i] * 2 + 1;
    }
    cout << rec(n, x) << endl;

    return 0;
}
