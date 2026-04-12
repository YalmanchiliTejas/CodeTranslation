#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, x, y, ans, mini;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

    if((a+b) <= 2*c) ans = a*x + b*y;
    else {
        mini = min(x,y);
        ans = c*2*mini;
        int dif;
        if(x > y)

            ans += min(a, 2*c)*(x - mini);
        else
            ans += min(b, 2*c)*(y - mini);
    }

    printf("%d", ans);
    return 0;
}