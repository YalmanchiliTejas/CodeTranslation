#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = a*x + b*y;
    chmin(ans, c*2*x + b*max(y-x, 0LL));
    chmin(ans, a*max(x-y, 0LL) + c*2*y);
    cout << ans << endl;
    return 0;
}
