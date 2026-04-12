//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define sz(s) ((int) s.size ())
#define all(s) s.begin (), s.end ()

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 5;
const int mod = (int) 1e9 + 7;

ll ans, x;
int n, q[N];
pair<int, int> a[N], m, f, b[N + N];

inline void solve () {
        scanf ("%d", &n);
        m = f = mp (0, mod);
        for (int i = 1; i <= n; i++) {
                scanf ("%d%d", &a[i].f, &a[i].s);
                if (a[i].f > a[i].s) {
                        swap (a[i].f, a[i].s);
                }
                m.f = max (m.f, a[i].s);
                m.s = min (m.s, a[i].f);
                f.f = max (f.f, a[i].f);
                f.s = min (f.s, a[i].s);
                b[i] = mp (a[i].f, i);
                b[n + i] = mp (a[i].s, i);
        }
        ans = (f.f - m.s) * 1LL * (m.f - f.s);
        x = max (f.f, m.f) - min (f.s, m.s);
        sort (b + 1, b + n + n + 1);
        for (int i = 1, r = 0, cr = 0; i <= n + n; i++) {
                while (r < n + n && cr < n) {
                        q[b[++r].s]++;
                        if (q[b[r].s] == 1) {
                                cr++;
                        }
                }
                if (cr < n) {
                        break;
                }
                ans = min (ans, x * (b[r].f - b[i].f));
                q[b[i].s]--;
                if (q[b[i].s] == 0) {
                        cr--;
                }
        }
        printf ("%lld\n", ans);
}

int tests = 1;

int main () {
//        freopen (".in", "r", stdin);
//        freopen (".out", "w", stdout);
//        scanf ("%d", &tests);
        while (tests--) {
                solve ();
        }
        return 0;
}
