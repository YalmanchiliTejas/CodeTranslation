#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long; 
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
//constexpr long long MOD = 998244353LL;
template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true;} return false; }
template<class T, class U> inline bool chmin(T &a, U b) { if (a > b) { a = b; return true;} return false; }
const ll INF = (ll)1e18 + 1;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int h[n];
    rep(i,n) cin >> h[i];

    int ans = 0;
    int mx = 0;
    
    rep(i,n){
        if(mx <= h[i]){
            mx = h[i];
            ans++;
        }
    }
    
    cout << ans << ln;
    return 0;
}