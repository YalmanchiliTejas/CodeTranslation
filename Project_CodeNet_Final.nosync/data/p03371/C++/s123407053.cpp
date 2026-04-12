#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int a,b,c;
    cin >> a >> b >>c;
    int x,y;
    cin >> x >> y;
    ll ans = 0;
    if(a+b >= c*2){
        ans += min(x,y)*2*c;
        if(x >= y && a >= 2*c) ans += (x-y)*2*c;
        else if(x >= y) ans += (x-y)*a;
        else if(x < y && b >= 2*c) ans += (y-x)*2*c;
        else if(x < y) ans += (y-x)*b;
    }
    else ans += a*x+b*y;
    cout << ans << endl;
}