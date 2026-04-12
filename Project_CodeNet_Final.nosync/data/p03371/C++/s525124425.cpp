#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(x < y){
        swap(x,y);
        swap(a,b);
    }
    int ans = 0;
    if(a+b < 2*c) ans += (a+b)*y;
    else  ans += 2*c*y;
    int z = x-y;
    if(a < 2*c) ans += a*z;
    else ans += 2*c*z;
    cout << ans << endl;
    return 0;
}
