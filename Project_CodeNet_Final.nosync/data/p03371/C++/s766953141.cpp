// Header {{{
#include <bits/stdc++.h>

using namespace std;
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;
typedef unsigned long long int ull;
typedef long long int ll;
#define rep(i,a,b) for (ll i=(a); i<(b); i++)
typedef pair<ll,ll> PLL;
// }}}

ll maxll(ll x , ll y){
    return x>y?x:y;
}
signed main() {
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=a*x+b*y;
    ll z = x * 2;
    ans=min(ans,a*maxll(0,x-z/2)+b*maxll(0,y-z/2)+c*z);
    z = y * 2;
    ans=min(ans,a*maxll(0,x-z/2)+b*maxll(0,y-z/2)+c*z);
    cout<<ans<<endl;
    return 0;
}
