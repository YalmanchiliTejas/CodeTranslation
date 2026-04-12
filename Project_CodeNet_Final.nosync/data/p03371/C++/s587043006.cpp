#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, b, c, x, y, sum = 0;
    cin >> a >> b >> c >> x >> y;
    if(a + b >= 2 * c)
    {
        if(x >= y)
        {
            sum += y * 2 * c;
            sum += (x - y) * min(a, 2 * c);
        }
        else
        {
            sum += x * 2 * c;
            sum += (y - x) * min(b, 2 * c);
        }
    }
    else
    {
        sum += x * a + y * b;
    }
    cout << sum << endl;
    return 0;
}
