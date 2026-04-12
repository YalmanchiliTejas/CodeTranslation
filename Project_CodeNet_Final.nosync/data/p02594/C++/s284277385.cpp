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

// #define INF LLONG_MAX
// #define MINF LLONG_MIN
#define INF 1e18
#define MINF -INF

void solve() {
    ll n;
    cin >> n;
    if (n >= 30) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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
    //cin.rdbuf()->in_avail()
    return 0;
}
