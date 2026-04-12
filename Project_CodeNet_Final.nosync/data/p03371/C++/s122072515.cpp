#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll ans = INF;
    rep(i, 200001) {
        ll can = c * i;
        if(x > i/2) can += a * (x - i/2);
        if(y > i/2) can += b * (y - i/2);
        chmin(ans, can);
    }
    cout << ans << endl;
}