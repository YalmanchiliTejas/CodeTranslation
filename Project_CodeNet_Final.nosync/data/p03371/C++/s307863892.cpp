#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = a*x+b*y;
    if(x>y){
        ans = min(ans,c*y*2+a*(x-y));
        ans = min(ans,c*2*x);
    }
    else {
        ans = min(ans,c*x*2+b*(y-x));
        ans = min(ans,c*2*y);
    }
    cout << ans << endl;
}