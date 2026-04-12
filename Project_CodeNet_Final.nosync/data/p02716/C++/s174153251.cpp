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
#define FOREACH(e, v) for (auto e : v)

#define TGET(t, i) get<i>(t)
#define TSET(t, i, a) get<i>(t) = a
// MinHeap - priority_queue<ll, vll, greater<ll>> pq;

#define EVEN(n) ((n)&1) == 0
#define ODD(n) ((n)&1) == 1
#define MOD(x, m) ((x) % (m) + (m)) % (m)

#define SORT(v) sort(v.begin(), v.end())
#define SORTREV(v) sort(v.rbegin(), v.rend())
#define SHUFFLE(v) random_shuffle(v.begin(), v.end())
//srand(unsigned(time(0)));

#define REMOVEAT(v, i) v.erase(v.begin() + i)
#define REVERSE(v) reverse(v.begin(), v.end())

template <typename T>
void join(vector<T>& arr, string sep) {
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

#define POS "POSSIBLE"
#define IMPOS "IMPOSSIBLE"

// #define INF LLONG_MAX
// #define MINF LLONG_MIN
#define INF 9e18
#define MINF -INF

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    REP(i, n) {
        cin >> a[i];
    }
    ll k = n / 2;

    const ll impos = -9e18;
    map<pair<ll, ll>, ll> dp;
    function<ll(ll, ll)> helper = [&](ll i, ll k) {
        auto it = dp.find({i, k});
        if (it != dp.end())
            return it->second;
        if (k == 0) {
            dp[{i, k}] = 0;
            return 0ll;
        }
        if (i >= n) {
            dp[{i, k}] = impos;
            return impos;
        }
        if ((n-i) % 2 == 0) {
            if (k > (n-i)/2) {
                dp[{i, k}] = impos;
                return impos;
            }
        } else {
            if (k > (n-i)/2+1) {
                dp[{i, k}] = impos;
                return impos;
            }
        }
        ll res1 = helper(i+1, k);
        ll res2 = helper(i+2, k-1);
        if (res2 != impos) {
            res2+=a[i];
        }

        ll res = max(res1, res2);
        dp[{i, k}] = res;
        return res;
    };

    ll res = helper(0, k);
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}