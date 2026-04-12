#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1ll << 50;
const int MOD = 1e9 + 7;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define vi vector<int>
#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define itn int
#define asn ans
bool dbg = false;
template <uint MD>
struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
    friend istream& operator>>(istream& is, M& r) { return is >> r.v; }
};
using Mint = ModInt<MOD>;

int N, M, S, T;
itn A[202020], B[202020];
struct edge {
    int nxt, id, dist;
};
vector<vector<edge>> G;
int d[202002];
bool use_vertex[202020];
bool use_edge[202020];
int seen[202020];
int seen2[202020];
int seen3[202020];
Mint cnt1[202020], cnt2[202020];

bool dfs1(int idx) {
    if (idx == T) {
        use_vertex[idx] = true;
        return true;
    }
    if (seen[idx])
        return use_vertex[idx];
    seen[idx] = 1;
    bool flag = false;
    for (auto& nxt : G[idx]) {
        if (d[idx] + nxt.dist == d[nxt.nxt] && dfs1(nxt.nxt)) {
            use_edge[nxt.id] = 1;
            flag = true;
        }
    }
    return (use_vertex[idx] = flag);
}

Mint dfs2(int idx) {
    if (seen2[idx]) {
        return cnt1[idx];
    }
    seen2[idx] = 1;
    for (auto nxt : G[idx]) {
        if (use_vertex[nxt.nxt] && d[idx] + nxt.dist == d[nxt.nxt]) {
            cnt1[idx] += dfs2(nxt.nxt);
        }
    }
    return cnt1[idx];
}

Mint dfs3(int idx) {
    if (seen3[idx]) {
        return cnt2[idx];
    }
    seen3[idx] = 1;
    for (auto nxt : G[idx]) {
        if (use_vertex[nxt.nxt] && d[idx] - nxt.dist == d[nxt.nxt]) {
            cnt2[idx] += dfs3(nxt.nxt);
        }
    }
    //cerr << idx + 1 << " : " << cnt2[idx] << endl;
    return cnt2[idx];
}

void solve() {

    priority_queue<P, vector<P>, greater<P>> que;
    FOR(N) {
        d[i] = INF;
    }

    d[S] = 0;
    que.push({0ll, S});
    while (!que.empty()) {
        auto cur = que.top();
        que.pop();
        int idx = cur.second;
        if (cur.first > d[idx])
            continue;
        for (auto& g : G[idx]) {
            if (d[g.nxt] > d[idx] + g.dist) {
                d[g.nxt] = d[idx] + g.dist;
                que.push({d[g.nxt], g.nxt});
            }
        }
    }

    use_vertex[S] = 1;
    use_vertex[T] = 1;


    dfs1(S);
    cnt1[T] = 1;
    dfs2(S);
    cnt2[S] = 1;
    dfs3(T);

    Mint ans = cnt1[S] * cnt1[S];
    int dist_max = d[T];
    int dist_tmp = d[T] / 2;
    if (dist_max % 2 == 0) {
        FOR(i, 0, N) {
            if (use_vertex[i])
                if (d[i] == dist_tmp) {
                    ans -= cnt1[i] * cnt2[i] * cnt1[i] * cnt2[i];
                }
        }
        FOR(i, 0, M) {
            if (use_edge[i]) {
                int MIN = min(d[A[i]], d[B[i]]);
                int MAX = max(d[A[i]], d[B[i]]);
                if (MIN < dist_tmp && MAX > dist_tmp) {
                    if (d[A[i]] < d[B[i]])
                        ans -= cnt2[A[i]] * cnt1[B[i]] * cnt2[A[i]] * cnt1[B[i]];
                    else
                        ans -= cnt2[B[i]] * cnt1[A[i]] * cnt2[B[i]] * cnt1[A[i]];
                }
            }
        }
    } else {
        FOR(i, 0, M) {
            if (use_edge[i]) {
                int MIN = min(d[A[i]], d[B[i]]);
                int MAX = max(d[A[i]], d[B[i]]);
                if (MIN <= dist_tmp && MAX > dist_tmp) {
                    if (d[A[i]] < d[B[i]])
                        ans -= cnt2[A[i]] * cnt1[B[i]] * cnt2[A[i]] * cnt1[B[i]];
                    else
                        ans -= cnt2[B[i]] * cnt1[A[i]] * cnt2[B[i]] * cnt1[A[i]];
                }
            }
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M >> S >> T;
    S--;
    T--;
    G.resize(N);
    FOR(M) {
        int a, b, d;
        cin >> A[i] >> B[i] >> d;
        A[i]--;
        B[i]--;
        a = A[i];
        b = B[i];
        G[a].pb({b, i, d});
        G[b].pb({a, i, d});
    }


    solve();
    return 0;
}
//...