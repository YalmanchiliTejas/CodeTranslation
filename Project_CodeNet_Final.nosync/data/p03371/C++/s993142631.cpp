#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
 
const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = a*x + b*y;

    ans = min(ans, 2*c*x + b*max((ll)0, y-x));
    ans = min(ans, a*max((ll)0, x-y) + 2*c*y);

    cout << ans << endl;
}