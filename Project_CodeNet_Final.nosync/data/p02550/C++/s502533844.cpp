#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

#define REP(k, n) for (ll k = 0; k < (ll)(n); ++k)
#define REPREV(k, n) for (ll k = (ll)(n)-1; k >= 0; --k)
#define FOR(k, a, b) for (ll k = (ll)(a); k < (ll)(b); ++k)
#define FORREV(k, a, b) for (ll k = (ll)(b)-1; k >= (ll)(a); --k)
#define FOREACH(e, v) for (auto& e : v)

#define TGET(t, i) get<i>(t)
#define TSET(t, i, a) get<i>(t) = a
// MinHeap - priority_queue<ll, vll, greater<ll>> pq;

#define EVEN(n) ((n)&1) == 0
#define ODD(n) ((n)&1) == 1

#define SORT(v) sort(v.begin(), v.end())
#define SORTREV(v) sort(v.rbegin(), v.rend())
#define SHUFFLE(v) random_shuffle(v.begin(), v.end())
//srand(unsigned(time(0)));

#define REMOVEAT(v, i) v.erase(v.begin() + i)
#define REVERSE(v) reverse(v.begin(), v.end())
#define UNIQUE(v) \
    SORT(v);      \
    v.resize(distance(v.begin(), unique(v.begin(), v.end())))

ostream& operator<<(ostream& str, const pll& p) {
    str << p.first << " " << p.second;
    return str;
}

template <typename T>
void join(T& arr, string sep) {
    bool first = true;
    for (auto t : arr) {
        if (first) {
            first = false;
            cout << t;
        } else {
            cout << sep << t;
        }
    }
    cout << "\n";
}

const ll md = 1e9 + 7;
ll MOD(ll x) {
    ll r = x % md;
    if (r < 0) {
        r += md;
    }
    return r;
}

#define POS "POSSIBLE"
#define IMPOS "IMPOSSIBLE"

// #define INF DBL_MAX
// #define INF LLONG_MAX
// #define MINF LLONG_MIN
#define INF 1e18
#define MINF -INF

void solve() {
    ll n, x, m;
    cin >> n >> x >> m;
    if (n == 1) {
        cout << x << endl;
        return;
    }
    unordered_map<ll, ll> rem2idx;
    vll pref(m + 1);

    ll sm = x;
    ll prv = x;
    rem2idx[x] = 0;
    pref[1] = x;
    bool done = true;
    ll l, r;
    ll left = n - 1;
    FOR(i, 1, n) {
        ll nxt = (prv * prv) % m;
        if (rem2idx.count(nxt)) {
            done = false;
            l = rem2idx[nxt];
            r = i;
            break;
        }
        left--;
        rem2idx[nxt] = i;
        pref[i + 1] = pref[i] + nxt;
        prv = nxt;
        sm += nxt;
    }

    if (done) {
        cout << sm << endl;
        return;
    }

    ll extra = pref[r] - pref[l];
    ll sz = r - l;
    sm += extra * (left / sz);
    ll rem = left % sz;
    sm += pref[l + rem] - pref[l];

    cout << sm << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    // #ifdef DEBUG
    //     for (int t = 1; t <= tt || cin.rdbuf()->in_avail(); t++) {
    //         // cout << "Case #" << t << ": ";
    //         solve();
    //     }
    // #else
    //     for (int t = 1; t <= tt; t++) {
    //         // cout << "Case #" << t << ": ";
    //         solve();
    //     }
    // #endif

    return 0;
}