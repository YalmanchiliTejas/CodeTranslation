#include<cstdio>
#include<iostream>
using namespace std;

int a, b, c, x, y;
int main() {
    int ans = 0;
    cin >> a >> b >> c >> x >> y;
    if(a + b <= c*2) {
       ans = x * a + b * y;
    }
    else {
        if(x > y) {
            ans = 2*c*y;
            if(2*c <= a) ans += 2*c*(x-y);
            else ans += (x-y)*a;
        }
        else {
            ans = 2*c*x;
            if(2*c <= b) ans += 2*c*(y-x);
            else ans += (y-x)*b;
        }
    }
    cout << ans << endl;
}