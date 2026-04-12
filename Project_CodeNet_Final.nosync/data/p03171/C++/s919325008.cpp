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
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int N;
vector<ll> a;
ll dp[3010][3010];
bool f[3010][3010] = {false};

// turnが0なら先手、1なら後手
ll dfs(int l, int r, int turn) {
    if(f[l][r]) {
        return dp[l][r];
    }
    f[l][r] = true;
    if(l + 1 >= r) {
        return dp[l][r] = (turn ? -1 : 1) * a[l];
    }
    if(turn) {
        return dp[l][r] = min(dfs(l + 1, r, 1 - turn) - a[l],
                              dfs(l, r - 1, 1 - turn) - a[r - 1]);
    } else {
        return dp[l][r] = max(dfs(l + 1, r, 1 - turn) + a[l],
                              dfs(l, r - 1, 1 - turn) + a[r - 1]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << dfs(0, N, 0) << endl;
}