#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i= 0; i< (int)(e); i++)
#define reps(i,s,e) for(int i = s; i < (int)(e); i++)
#define repr(i,s,e) for(int i = s; i > (int)(e); i--)
#define pb push_back
typedef long long ll;
const ll INF = 1LL << 60;



int main()
{
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if(x>=y){
        ans = 2*y*c+(x-y)*a;
    }
    else{
        ans = 2*x*c+(y-x)*b;
    }
    ans = min(ans,a*x+b*y);
    ans = min(ans,2*c*max(x,y));
    cout << ans;
}
