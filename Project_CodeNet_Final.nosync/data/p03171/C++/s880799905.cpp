#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1e10;
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
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define P pair<int, int>
#define V vector<int>
//#define S set<int>
#define itn int
bool dbg = false;

int N, a[3030];
int dp[3030][3030];
bool check[3030][3030];

int f(int x, int y, bool flag) {
    if (check[x][y])
        return dp[x][y];
    check[x][y] = true;
    if (x > y)
        return 0;
    int ret;
    if (flag) {
        ret = max(f(x + 1, y, false) + a[x], f(x, y - 1, false) + a[y]);
    } else {
        ret = min(f(x + 1, y, true) - a[x], f(x, y - 1, true) - a[y]);
    }
    return dp[x][y] = ret;
}


void solve() {
    cout << f(0, N - 1, true) << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    FOR(N)
    cin >> a[i];


    solve();
    return 0;
}
