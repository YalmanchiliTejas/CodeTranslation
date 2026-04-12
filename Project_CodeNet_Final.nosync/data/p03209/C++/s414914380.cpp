#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (a); i > (b); --i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define mp make_pair
#define bitcnt __builtin_popcount
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
#define CINT(...)                                                              \
    int __VA_ARGS__;                                                           \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"

typedef long long ll;
typedef vector<int> V;
typedef vector<ll> VL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef priority_queue<int> PQ;
typedef priority_queue<int, V, greater<int>> PQG;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

ll N, X;
VL p, d;
map<ll, ll> pnum;

ll pcnt(ll eat, ll lev) {
    if(lev == 0) {
        if(eat <= 0) return 0;
        return 1;
    } else if(eat <= 1 + d[lev - 1]) {
        return pcnt(eat - 1, lev - 1);
    } else {
        return p[lev - 1] + 1 + pcnt(eat - d[lev - 1] - 2, lev - 1);
    }
}

int main() {
    cin >> N >> X;
    d.resize(N + 1);
    p.resize(N + 1);
    d[0] = 1;
    p[0] = 1;
    REP(i, N) {
        d[i + 1] = 2 * d[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }
    cout << pcnt(X, N) << "\n";
    return 0;
}
