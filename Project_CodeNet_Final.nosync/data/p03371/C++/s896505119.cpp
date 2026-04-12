#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long count = 0;
    int xxx=min(x,y);
    if (a + b >= c + c)
    {
        count += (c + c) * xxx;
        x -= xxx;
        y -= xxx;
    }
    else
    {
        count += (a + b) * xxx;
        x -= xxx;
        y -= xxx;
    }

    if (x > 0)
    {
        count += min(c + c, a) * x;
    }
    if (y > 0)
    {
        count += min(c + c, b) * y;
    }
    cout << count << endl;
}
