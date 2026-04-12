#include <iostream>
#include <algorithm>
using namespace std ;
using ll = long long ;

int main(){
    ll a,b,c,x,y ;
    cin >> a >> b >> c >> x >> y ;
    ll ans = 0 ;
    if(a>2*c) a = 2*c ;
    if(b>2*c) b = 2*c ;
    if(a+b>2*c){
        ll z = min(x,y) ;
        ans += 2*c*z ;
        x -= z ;
        y -= z ;
    }
    ans += x*a ;
    ans += y*b ;
    cout << ans << endl ;
}
