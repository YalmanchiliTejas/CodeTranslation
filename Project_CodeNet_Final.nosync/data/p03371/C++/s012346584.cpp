#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;

int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = LLINF;
    for (ll i = 0; i < max(x,y)+1; i++)
    {
        
        ll temp = i*c*2;
        if(x > i) temp += (x-i)*a;
        if(y > i) temp += (y-i)*b;

        ans = min(ans,temp);
    }

    cout << ans << endl;

    return 0;
     
}