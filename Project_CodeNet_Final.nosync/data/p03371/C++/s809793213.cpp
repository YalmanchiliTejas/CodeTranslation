#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a = 0, b = 0, c = 0;
    int x = 0, y = 0;
    cin >> a >> b >> c >> x >> y;

    int mxy = min(x, y);

    int res1 = a * x + b * y;
    int res2 = a * (x - mxy) + b * (y - mxy) + 2 * c * mxy;
    int res3 = 2 * c * max(x, y);

    cout << min(min(res1, res2), res3) << endl;

    return 0;
}