#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll a, b, c, x, y, ans = pow(10, 9)+1;
    cin >> a >> b >> c >> x >> y;
    for (int i=0; i<=2*max(x,y); i+=2){
        ans = min(ans, a*max(0, (int)(x-(i/2))) + b*max(0, (int)(y-(i/2))) + c*i);
    }
    cout << ans << endl;
    return 0;
}