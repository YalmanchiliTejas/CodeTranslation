#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (x > y)
    {
        swap(x, y);
        swap(a, b);
    }
    ans = max(x, y) * min(a + b, 2 * c);
    ans = min(ans, x * min(a + b, 2 * c) + (y - x) * b);
    cout << ans << endl;
}
