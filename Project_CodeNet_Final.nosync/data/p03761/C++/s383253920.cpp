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
// template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }


int main() {
    
    map<char, int> ans;
    int n;
    cin >> n;
    rep(i, n) {
        map<char, int> mp;
        string s;
        cin >> s;
        rep(j, sz(s)) {
            mp[s[j]]++;
        }
        if (i == 0) ans = mp;
        else {
            for (auto e : ans) {
                ans[e.F] = min(e.S, mp[e.F]);
            }
        }
    }
    
    for (auto e : ans) {
        rep(j, e.S) cout << e.F;
    }
    cout << endl;
}
