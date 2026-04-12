#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    long long mx = max(x, y) * 2 * c;

    long long mn = min(x, y)*2*c;
    if(x > y)
    {
        mx = min(mx, mn + (x-y)*a);
    }

    else
    {
        mx = min(mx, mn + (y - x) * b);
    }

    mx = min(mx, a * x + b * y);

    cout << mx << endl;
    

}