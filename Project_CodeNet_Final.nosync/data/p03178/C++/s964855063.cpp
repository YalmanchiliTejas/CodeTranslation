#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " +
           to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);

    debug_out(T...);
}
#define LOCAL 1
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

typedef vector<int> VI;
typedef pair<char, char> PII;

#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)

typedef long long LL;
#define si(x) int(x.size())
#define eps 1e-9
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
#define FOR(i, j, k) for (int i = j; i <= k; i++)

#define cls(x) memset(x, 0, sizeof x)
#define inf(x) memset(x, 0x3f, sizeof x)
#define neg(x) memset(x, -1, sizeof x)
#define ninf(x) memset(x, 0xc0, sizeof x)

#define MAXM (int)1e5 + 10
#define MAX 1e4 + 10

#define INF 0x3f3f3f3f
using namespace std;
constexpr int maxn = 200000;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

LL A[maxn + 1];
struct Node {
    LL ans, sum, size;
    Node operator+(const Node &node) const {
        Node res;
        res.size = size + node.size;

        if (size & 1)
            res.sum = sum - node.sum;
        else
            res.sum = sum + node.sum;

        if (size & 1)
            res.ans = ans - node.ans - size * node.sum;
        else
            res.ans = ans + node.ans + size * node.sum;

        return res;
    }
} T[maxn << 2];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        T[v].size = 1;
        T[v].ans = T[v].sum = A[tm];
    } else {
        build(ls, tl, tm);
        build(rs, tm + 1, tr);
        T[v] = T[ls] + T[rs];
    }
}

void update(int v, int tl, int tr, int x, int V) {
    if (tl == tr) {
        T[v].ans = T[v].sum = V;
    } else {
        if (x <= tm)
            update(ls, tl, tm, x, V);
        else
            update(rs, tm + 1, tr, x, V);
        T[v] = T[ls] + T[rs];
    }
}

Node query(int v, int tl, int tr, int l, int r) {

    if (l <= tl and tr <= r)
        return T[v];
    if (r <= tm)
        return query(ls, tl, tm, l, r);
    if (l > tm)
        return query(rs, tm + 1, tr, l, r);
    return query(ls, tl, tm, l, r) + query(rs, tm + 1, tr, l, r);
}

int d = 0;
int dp[maxn][101];
int mod = 1e9 + 7;
LL dfs(int pos, int limit, int pre, vector<int> &v) {

    if (pos == v.size()) {

        return (pre % d) == 0 ? 1 : 0;
    }
    vector<int> key = {pos, pre};
    if (!limit and dp[pos][pre] != -1)
        return dp[pos][pre];

    int up = limit ? v[pos] : 9;

    LL res = 0;
    for (int i = 0; i <= up; ++i) {

        res = (res + dfs(pos + 1, limit and (i == up), (pre + i) % d, v)) % mod;
    }

    if (!limit)
        return dp[pos][pre] = res;

    return res;
}
void solve() {
    int k;
    string s;
    cin >> s;
    cin >> d;
    memset(dp, -1, sizeof dp);
    vector<int> v;

    for (int i = 0; i < s.size(); ++i) {
        v.push_back(s[i] - '0');
    }
    // debug(v);
    cout << (dfs(0, 1, 0, v) - 1 + mod) % mod << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    // cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
