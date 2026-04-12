#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    ll ans = 0;

    while(x>0 && y>0 && (2*c) < a+b){
        ans += 2*c;
        x--;
        y--;
    }

    while(x > 0){
        ans += min(2*c,a);
        x--;
    }

    while(y > 0){
        ans += min(2*c,b);
        y--;
    }

    cout<<ans<<endl;

    return 0;
}