
// Problem : A - Air Conditioner
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")  // disable
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define lll __int128
#define lp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define vec(v, type, sz) vector<type> v(sz)
#define in(v) \
    for (auto &i : v) cin >> i
#define all(v) v.begin(), v.end()
#define prv(v)                         \
    for (auto i : v) cout << i << " "; \
    cout << "\n"
#define MOD 1000000007
#define INF 1000000000
#define INFL 1000000000000000000ll
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vl vector<ll>
#define vii(v, n, m, val) vector<vector<int>> v(n, vector<int>(m, val))
#define viii(v, i, j, k, val)        \
    vector<vector<vector<int>>> v(i, \
                                  vector<vector<int>>(j, vector<int>(k, val)))
#define pii pair<int, int>
#define pb push_back
#define tos(x) string(1,x)
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
#define debug(...) \
    debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//#define int ll

signed main() {
	fast_io;
	int x; cin>>x;
	cout<<(x>=30?"Yes":"No");
}
// code!=think
// least efficient code to get ac
