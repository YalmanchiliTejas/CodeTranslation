#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll c_max = max(x, y) * 2;
    ll ans = 1LL<<60;
    rep(i, c_max+1) {
        ll price = max(a * (x - i/2), 0LL) + max(b * (y - i/2), 0LL) + c * i;
        chmin(ans, price);
    }
    cout << ans << endl;
}