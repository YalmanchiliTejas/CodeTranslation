
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("avx,avx2,fma")
// //#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")  // disable
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define lll __int128;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define PQ priority_queue
#define Q queue
#define isin(mp, key) ((mp).find(key) != (mp).end())
#define pb push_back
#define fi first
#define se second
#define tos(x) string(1, x)
#define lp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define vec(v, type, sz) vector<type> v(sz)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define INF 2000000003
#define INFL 2000000000000000003ll
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vii(v, n, m, val) vector<vector<int>> v(n, vector<int>(m, val))
#define viii(v, i, j, k, val)        \
    vector<vector<vector<int>>> v(i, \
                                  vector<vector<int>>(j, vector<int>(k, val)))
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define testc   \
    int tcc;    \
    cin >> tcc; \
    for (int tc = 1; tc <= tcc; tc++)
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while (!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef DB
#define db(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define db(...) 42
#endif
#define rd_macro(_1, _2, _3, _4, NAME, ...) NAME
#define rd(...) rd_macro(__VA_ARGS__, rd4, rd3, rd2, rd1)(__VA_ARGS__)
#define rd1(x) \
    int x;     \
    cin >> x;
#define rd2(x, y) \
    int x, y;     \
    cin >> x >> y;
#define rd3(x, y, z) \
    int x, y, z;     \
    cin >> x >> y >> z;
#define rd4(w, x, y, z) \
    int w, x, y, z;     \
    cin >> w >> x >> y >> z;
template <typename... Args>
void pr(Args... args) {
    (std::cout << ... << args);
}
template <typename... Args>
void in(Args&&... args) {
    (std::cin >> ... >> args);
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        os << v[i];
        if (i != (int)v.size() - 1) os << " ";
    }
    return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
    os << "[";
    for (auto it : v) {
        os << it;
        if (it != *v.rbegin()) os << ", ";
    }
    os << "]\n";
    return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
    for (auto it : v) os << it.first << " : " << it.second << "\n";

    return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
    os << "(";
    os << v.first << ", " << v.second << ")";
    return os;
}
template <typename T, typename S>
istream& operator>>(istream& is, pair<T, S>& v) {
    is >> v.first >> v.second;
    return is;
}

signed main() {
    fast_io;
    rd(n, x, m);
    if (n == 1) {
        pr(x);
        return 0;
    }
    if (n <= 1e5) {
        int cur = x;
        int ans = x;
        lp(i, 2, n + 1) cur = (cur * cur) % m, ans += cur;
        pr(ans);
        return 0;
    }
    vi when(1e5 + 5, -1);
    vi sum(1e5 + 5, 0);
    sum[1] = x;
    int run = x;
    when[x] = 1;
    int cur = x;
    int en = -1;
    lp(i, 2, 1e5 + 2) {
        cur = (cur * cur) % m;
        run += cur;
        sum[i] = run;
        if (when[cur] != -1) {
            en = i;
            break;
        }
        when[cur] = i;
    }
    assert(en != -1);
    int len = en - when[cur];
    // at len moves it will be rep again
    int add = sum[en] - sum[when[cur]];
    n -= when[cur];
    int ans = sum[when[cur]] + add * (n / len);
    n %= len;
    while (n--) {
        cur = (cur * cur) % m;
        ans += cur;
    }
    pr(ans);
}