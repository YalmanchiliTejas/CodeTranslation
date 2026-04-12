#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int main() {
    #ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
    #else
    #endif
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    vector<bool> can(n, false);
    can[0] = true;
    can[1] = true;
    iota(p.begin(), p.end(), 0);

    int x = 0;
    forn (i, q) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a == x || b == x)
            x ^= a ^ b;
        swap(p[a], p[b]);
        assert(p[x] == 0);

        if (x > 0)
            can[p[x - 1]] = true;
        if (x + 1 < n)
            can[p[x + 1]] = true;
    }
    int res = accumulate(can.begin(), can.end(), 0);
    cout << res << '\n';
}
