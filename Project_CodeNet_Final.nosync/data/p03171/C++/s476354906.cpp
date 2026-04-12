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
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }



ll dp[3001][3001];

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    // 局面の残り石の個数でループ
    rep3(len, 1, n + 1) for (int i = 0; i + len <= n; ++i) {
        // len = j - i
        int j = len + i;
        
        if ((n - len) % 2 == 0) {
            dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
        } else {
            dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
        }
    }
    
    cout << dp[0][n] << endl;
}
 

