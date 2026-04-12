#include <bits/stdc++.h>
using  namespace std;
#define    ll  long long int
ll fre[11];
int main( )
{
    ll N, i,k, mx = -1,sum=0, a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    ll s = a * x + b * y;

    ll t;
    if (x < y)
    {
        t = 2 * c * x + b * (y-x);
        if (t < s) s = t;

        t = 2 * c * y;
        if (t < s) s = t;
    }
    else
    {
        t = 2 * c * y + a *(x-y);
        if (t < s) s = t;

        t = 2 * c * x;
        if (t < s) s = t;
    }

    cout << s << endl;

    return 0;
}


