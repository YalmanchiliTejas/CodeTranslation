#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    ll a, b, c, x, y;
    cin>>a>>b>>c>>x>>y;
    ll ans;
    if(a+b<=2*c){
        ans = a*x+b*y;
    }
    else{
        if(x>=y){
            ans = y*2*c;
            ans += (x-y)*min(2*c, a);
        }
        else{
            ans = x*2*c;
            ans += (y-x)*min(2*c, b);
        }
    }
    cout<<ans<<endl;
    return 0;
}