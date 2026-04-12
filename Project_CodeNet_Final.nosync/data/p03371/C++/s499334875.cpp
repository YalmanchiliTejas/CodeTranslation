#include<iostream>
using namespace std;
int main () {
    int a, b, c, x, y, mn, ans = 0;
    cin >> a >> b >> c >> x >> y;
    mn = min(x, y);
    if(a > 2 * c)
        a = 2 * c;
    if(b > 2 * c)
        b = 2 * c;
    if(a + b > 2 * c)
        ans = mn * 2 * c, x -= mn, y -= mn;
    ans = ans + x * a + y * b;
    cout << ans << endl;
    return 0;
}
