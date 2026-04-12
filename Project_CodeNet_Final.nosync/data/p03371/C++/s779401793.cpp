#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 100;

int main()
{
    int a, b, c;
    int x, y;
    cin >> a >> b >>c;
    cin >> x >> y;
    int ans1, ans2, ans;
    if(c * 2 < a + b)
    {
        if(x > y)
        {
            ans1 = y * 2 * c;
            ans2 = (x - y) * min(a, c * 2);
            //cout << y * 2 * c + (x - y) * a << endl;
        }
        else
        {
            ans1 = x * 2 * c;
            ans2 = (y - x) * min(b, c * 2);
            //cout << x * 2 * c + (y - x) * b << endl;
        }
        cout << ans1 + ans2 << endl;
    }
    else
    {
        cout << a * x + b * y << endl;
    }
    return 0;
}
