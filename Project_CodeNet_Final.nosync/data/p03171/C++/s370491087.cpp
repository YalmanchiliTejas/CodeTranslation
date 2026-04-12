#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int n;
vector<int> a;
vector<vector<long long>> dp;
const long long INF = 1LL<<60;


long long rec(int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != INF) return dp[i][j];
    long long res = 0;
    int k = i + (n-j);
    if (k % 2 == 0) {
        res = max(rec(i+1, j) + a[i], rec(i, j-1) + a[j-1]);
    } else {
        res = min(rec(i+1, j) - a[i], rec(i, j-1) - a[j-1]);
    }
    return dp[i][j] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    dp.resize(n+1, vector<long long>(n+1, INF));
    cout << rec(0, n) << endl;
}
