#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(x > y)
    {
        cout << min(min(c * 2 * max(x,y),a * x + b * y),(c * 2 * y + a * (x - y)));
    }
    else
    {
        cout << min(min(c * 2 * max(x,y),a * x + b * y),(c * 2 * x + b * (y - x)));
    }
    
    return 0;
}