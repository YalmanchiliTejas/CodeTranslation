#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define fst first
#define sc second
#define snd second
#define sz(X) (int)(X).size()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define all(X) X.begin(), X.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef vector<int> vi;

const int N = 1e5;
const int LOG = 61;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLMOD = 998244353;
const ll LLINF = 1e18;

unordered_map<int, int> t;

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) t[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(2 * v, tl, tm, pos, val);
        else update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return t[v];
    else {
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    vi dp(n);
    int ans = 0;
    forn(i, n) {
        dp[i] = get(1, 0, INF, a[i], INF) + 1;
        update(1, 0, INF, a[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
