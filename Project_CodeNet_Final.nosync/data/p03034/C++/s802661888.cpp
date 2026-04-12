#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define mp make_pair
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    for (ll c = 1; c < n; ++c) {
        ll score = 0;
        set<ll> s; // 同じ座標踏めない
        rep(x, n) {
            if (x * c >= n || n - 1 - x * c < 0) break;
            // b = a - c > 0
            ll A = n - 1 - x * c;
            if (A <= c) break;
            score += a[x * c];
            if (s.find(x * c) != s.end()) break;
            s.insert(x * c);
            score += a[n - 1 - x * c];
            if (s.find(n - 1 - x * c) != s.end()) break;
            s.insert(n - 1 - x * c);
            chmax(ans, score);
        }
    }
    cout << ans << endl;
}
