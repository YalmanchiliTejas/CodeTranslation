#include <iostream>

using namespace std;

int main()
{
    int a, b, c, x, y;
    long long ans(0);
    cin >> a >> b >> c >> x >> y;
    if(2 * c < a + b)
    {
        ans += 2 * c * min(x, y);
        //cout << ans << " ";
        if(x > y)
        {
            if(2 * c < a)
                ans += 2 * c * (x - y);
            else
                ans += a * (x - y);
        }
        else
        {
            if(2 * c < b)
                ans += 2 * c * (y - x);
            else
                ans += b * (y - x);
        }
    }
    else
    {
        ans += a * x + b * y;
    }
    cout << ans;
}