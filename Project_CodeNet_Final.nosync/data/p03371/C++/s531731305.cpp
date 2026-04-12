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
    if(a + b <= 2*c) {
        cout << a*x + b*y << endl;
        return 0;
    }
    ll ans = min(x, y) * 2 * c;
    if(x > y) ans += (x - y) * min(a, 2*c);
    else ans += (y - x) * min(b, 2*c);
    cout << ans << endl; 
}