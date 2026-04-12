#include <iostream>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define SIZE 1000000001

void all_search(int a, int b, int c, int x, int y, int *ans)
{
    REP(i, x + 1)
    { //aピザの枚数
        REP(j, y + 1)
        { //bピザの枚数
            if (a * i + b * j + c * 2 * max(x - i, y - j) <= *ans)
                *ans = a * i + b * j + c * 2 * max(x - i, y - j);
        }
    }
}

void all_search_revised(int a, int b, int c, int x, int y, int *ans)
{
    if (a + b >= 2 * c)
    {
        *ans = 2 * c * min(x, y);

        if (x >= y)
        {
            if (a > 2 * c)
                *ans += (x - y) * 2 * c;
            else
                *ans += (x - y) * a;
        }
        else
        {
            if (b > 2 * c)
                *ans += (y - x) * 2 * c;
            else
                *ans += (y - x) * b;
        }
    }
    else
    {
        *ans = x * min(2 * c, a) + y * min(2 * c, b);
    }
}

int main(void)
{
    int a, b, c, x, y, ans = SIZE;
    //scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    cin >> a >> b >> c >> x >> y;

    all_search_revised(a, b, c, x, y, &ans);

    //printf("%d\n",&ans);
    cout << ans << endl;
    return 0;
}