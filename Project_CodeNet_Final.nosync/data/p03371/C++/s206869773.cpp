#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define N 1005
const int INF = 0x3f3f3f3f;

int a, b, c, x, y;

int main()
{
    cin >> a >> b >> c >> x >> y;
    int res1 = a * x + b * y;
    int res2 = min(x, y) * 2 * c;
    if (x > y)
    {
        res2 += (x - y) * a;
    }
    else
    {
        res2 += (y - x) * b;
    }
    int res3 = max(x,y)*2*c;
    cout<<min(res1,min(res2,res3))<<endl;
}