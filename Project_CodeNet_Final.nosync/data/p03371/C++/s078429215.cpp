#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <vector>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>

int main()
{
    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;
    if (a + b <= 2 * c)
    {
        cout << a * x + b * y << endl;
    }
    else
    {
        int ans = 2 * c * min(x, y);
        if (x > y)
            ans += a * (x - y);
        else
            ans += b * (y - x);
        cout << min(ans, 2 * c * max(x, y)) << endl;
    }
}
