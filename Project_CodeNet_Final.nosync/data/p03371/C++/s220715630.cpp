#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

    int ans = 0;
    if (a + b > c * 2)
    {
        int cup = min(x, y);
        ans = cup * c * 2;
        x -= cup;
        y -= cup;
        if (a > c * 2)
        {
            ans += x * c * 2;
        }
        else
        {
            ans += x * a;
        }
        if (b > c * 2)
        {
            ans += y * c * 2;
        }
        else
        {
            ans += y * b;
        }
    }
    else
    {
        ans = a * x + b * y;
    }

    printf("%d\n", ans);
    return 0;
}