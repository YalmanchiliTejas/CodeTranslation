#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define DEBUG
#ifdef DEBUG
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) {
            os << ',';
        }
        os << v[i];
    }
    os << '}';
    return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &... args) {
    cerr << " " << x;
    debugg(args...);
}
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debugg(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __Setup;

using ll = long long;
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    ll now = X;
    ll nxt;
    vector<ll> v;
    set<ll> se;
    {
        v.emplace_back(X);
        se.insert(X);
    }
    while(1) {
        nxt = (now * now) % M;
        if(se.count(nxt)) {
            break;
        }
        now = nxt;
        v.emplace_back(now);
        se.insert(now);
    }
    if(se.count(0)) {
        cout << accumulate(ALL(v), 0LL) << endl;
        return 0;
    }
    ll sz = (ll)v.size();
    ll start;
    for(ll i = 0; i < sz; i++) {
        if(v[i] == nxt) {
            start = i;
            break;
        }
    }
    ll loopsz = sz - start;
    ll loopsum = 0;
    for(ll i = start; i < sz; i++) {
        loopsum += v[i];
    }
    debug(start, loopsz, loopsum, sz);
    debug(v);
    if(N <= sz) {
        ll ans = 0;
        for(int i = 0; i < N; i++) {
            ans += v[i];
        }
        cout << ans << endl;
        return 0;
    }
    ll ans = accumulate(ALL(v), 0LL) + loopsum * (max(N - sz, 0LL) / loopsz);
    N -= (sz + loopsz * (max(0LL, N - sz) / loopsz));
    for(ll i = 0; i < N; i++) {
        assert(start <= i + start && i + start < sz);
        ans += v[i + start];
    }
    cout << ans << endl;
}
