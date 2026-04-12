#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }



int dp[5003][5003];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(all(v));
    
    set<int> s;
    rep(i, n) s.insert(v[i]);
    
    map<int, int> mp;
    rep(i, n) mp[v[i]] = i; // v[i]は1通り
    
    
    fill_n(*dp, 5003 * 5003, 2);
    int ans = 2;
    
    rep(j, n) rep3(i, j + 1, n) {
        if (s.find(2 * v[i] - v[j]) != s.end()) {
            int k = mp[2 * v[i] - v[j]];
            chmax(dp[k][i], dp[i][j] + 1);
            chmax(ans, dp[k][i]);
        }
    }
    cout << ans << endl;
}

