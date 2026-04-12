#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Printv(v)                                                              \
    {                                                                          \
        REP(x, v.size()) { cout << v[x] << (x == v.size() - 1 ? "\n" : " "); } \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}
template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<ll, ll> PL;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const double PI = atan(1.0) * 4.0;
const ll LINF = 1e18;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

void cinfast() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

ll N, K;
ll dp[3000][3000];
ll a[3000];
ll Tarodp(ll), Jirodp(ll);

ll calcdp(ll l, ll r) {
    if(l > r) return 0;
    if(dp[l][r] != LINF) return dp[l][r];
    ll &res = dp[l][r];
    if((N - (r - l + 1)) % 2)
        res = min(calcdp(l, r - 1) - a[r], calcdp(l + 1, r) - a[l]);
    else {
        res = max(calcdp(l, r - 1) + a[r], calcdp(l + 1, r) + a[l]);
    }
    return res;
}

signed main() {
    cin >> N;
    REP(i, N) cin >> a[i];
    Fill(dp, LINF);
    cout << calcdp(0, N - 1) << "\n";
}
