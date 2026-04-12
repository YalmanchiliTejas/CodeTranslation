#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    int diff = max(x,y) - min(x,y);
    int minxy = min(x,y);
    ll ans = 0;
    if((ll)(minxy*(a+b)) > (ll)(2*c)*minxy){
         ans  = (2*c)*minxy;
        if(x>y) ans += min((ll)diff*a,(ll)diff*(2*c));
        if(x<y) ans += min((ll)diff*b,(ll)diff*(2*c));
        cout<<ans;
    }
    else {
       ans = minxy*(a+b);
      if(x>y) ans += min((ll)diff*a,(ll)diff*(2*c));
      if(x<y) ans += min((ll)diff*b,(ll)diff*(2*c));
      cout<<ans;
    }
    
}



