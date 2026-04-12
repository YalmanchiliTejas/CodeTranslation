#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

int main( )
{
    ll s = 0, a, b, c, x, y, mn;
    cin >> a >> b >> c >> x >> y;
    mn = min(x, y);
    if (2 * c <= (a + b)) {
        s += ((2 * c) * mn);
        x -= mn;
        y -= mn;
    }
    s += min(a * x + b * y, 2 * c * x + 2 * c * y);
    cout << s << '\n';
    return 0;
}