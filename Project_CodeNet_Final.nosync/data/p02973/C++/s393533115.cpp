#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
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

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vi a(n);
//     rep(i, n) cin >> a[i];
//     deque<int> d;
//     rep(i, n) {
//         int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
//         if (p == 0) d.push_front(a[i]);
//         else d[p-1] = a[i];
//     }
//     cout << sz(d) << endl;
// }

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    reverse(a.begin(), a.end());
    // aの最長広義単調増加列の長さ
    vi dp(n, INF);
    rep(i, n) {
        int p = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[p] = a[i];
    }
    int ans = -1;
    rep(i, n) {
        if (dp[i] == INF) {
            ans = i;
            break;
        }
    }
    if (ans == -1) ans = n;
    cout << ans << endl;
}