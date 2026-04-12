#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans1 = 2*c*max(x,y);
    ll tmp;
    if(x > y) tmp = a;
    else tmp = b;
    ll ans2 = 2*c*min(x,y)+abs(x-y)*tmp;
    ll ans3 = a*x+b*y;
    cout << min(ans1,min(ans2,ans3)) << endl;
    return 0;
}