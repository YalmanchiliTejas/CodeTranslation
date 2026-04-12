#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;

ll min(ll a, ll b) {
    ll c=(a<b)?a:b;
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);

    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if (x>y) {
        swap(x,y);
        swap(a,b);
    }
    ll ans1=a*x+b*y;
    ll ans2=c*2*x+b*(y-x);
    ll ans3=c*2*y;
    ll ans=min(ans1,min(ans2,ans3));
    cout << ans << endl;

    return 0;   
}
