#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans=(ll)1e12;
    for(ll i=0;i<=max(x,y);i++){
        ll sum=2*i*c;
        ll xres=max(0ll,x-i);
        ll yres=max(0ll,y-i);
        sum+=xres*a+yres*b;
        ans=min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}