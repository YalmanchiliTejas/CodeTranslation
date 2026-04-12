#include <iostream>
using namespace std;
int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (a+b >= 2*c) {
        int m = min(x, y);
        ans += 2*c*m;
        x -= m;
        y -= m;
        if (x) {
            if (a <= 2*c) {
                ans += x*a;
            }
            else
            {
                ans += x*2*c;
            }
        }
        if (y) {
            if (b <= 2*c) {
                ans += y*b;
            }
            else
            {
                ans += y*2*c;
            }
        }
    }
    else
    {
        ans = a*x + b*y;
    }
    cout << ans << endl;
}