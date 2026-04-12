// https://atcoder.jp/contests/abc095/tasks/arc096_a
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long ans = LONG_MAX;
    long temp = 0;
    for (int i = 0; i <= max(x, y) * 2; i += 2)
    {
        int numA = ((x - i / 2) >= 0 ? (x - i / 2) : 0);
        int numB = ((y - i / 2) >= 0 ? (y - i / 2) : 0);
        temp = a * numA + b * numB + c * (i);
        ans = min(ans, temp);
    }
    cout << ans << endl;
}