#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y, ans=0;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=2*c) ans=a*x+b*y;
    else if(a+b>2*c){
        if(x>y) {
            if(a>2*c) ans=2*c*x;
            else ans=y*2*c+(x-y)*a;
        }
        else {
            if(b>2*c) ans=2*c*y;
            else ans=x*2*c+(y-x)*b;
        }
    }
    cout << ans << endl;
}