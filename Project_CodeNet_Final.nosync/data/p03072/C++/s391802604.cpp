#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template <class c
#define ris return *this
#define dor > debug& operator<<
#define eni(x)                                                                 \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(   \
              c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef LOCAL
    ~debug() { cerr << endl; }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d) {
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c&) { ris; }
#endif
}
;
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mem(a, s) memset(a, s, sizeof(a))
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)

typedef vector<int> vi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

int _x[] = {0, 0, -1, 1, -1, 1, -1, 1};
int _y[] = {-1, 1, 0, 0, 1, -1, -1, 1};

const int mod = 1e6 + 7;

void solve();
void pre();

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t = 1;
    // cin >> t;
    rep(i, 1, t) {
        // cout << "Case # " << i << ": ";
        solve();
    }
    return 0;
}

void pre() {}

void solve() {
    int n;
    cin >> n;
    vi v(n), pre(n);
    rep(i, 0, n - 1) {
        cin >> v[i];
        if (i == 0)
            pre[i] = v[i];
        else
            pre[i] = max(pre[i - 1], v[i]);
    }
    int ans = 0;
    rep(i, 0, n - 1) {
        if (v[i] >= pre[i])
            ans++;
    }
    cout << ans << "\n";
}
