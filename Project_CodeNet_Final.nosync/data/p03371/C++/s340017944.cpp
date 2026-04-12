#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}
 
int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int n = min(x, y);
    int ans = 0;
    if (a + b < 2 * c)
    {
        ans += n * (a + b);
    }
    else
    {
        ans += n * c * 2;
    }
    if (a < 2 * c)
    {
        ans += a * (x - n);
    }
    else
    {
        ans += 2 * c * (x - n);
    }
    if (b < 2 * c)
    {
        ans += b * (y - n);
    }
    else
    {
        ans += 2 * c * (y - n);
    }
    cout << ans << endl;
 
    return 0;
}