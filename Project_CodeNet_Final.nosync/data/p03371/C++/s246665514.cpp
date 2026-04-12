#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int a, b, c, x, y;
    int x1,y1,c1,cmax,total,tmin;

    cin >> a  >> b >> c >> x >> y;

    if (x >= y)
        cmax = 2 * x;
    else
        cmax = 2 * y;

    tmin = INT_MAX;
    for (c1 = 0;c1 <= cmax;c1+=2) {
        x1 = x - c1 / 2;    if (x1 < 0)  x1 = 0;
        y1 = y - c1 / 2;    if (y1 < 0)  y1 = 0;
        total = c1 * c + a * x1 + b * y1;
        if (total < tmin)
            tmin = total;
    }

    cout << tmin << endl;
}
