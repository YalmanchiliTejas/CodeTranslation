#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main()
{
    int X, Y, Z;
    if (scanf("%d%d%d", &X, &Y, &Z) < 3) return 0;

    int ans = 0;
    for (int i = 1; i < 100000; i++)
    {
        // i * Y + (i - 1) * Z + 2 * Z > X
        if (i * Y + (i + 1) * Z > X) break;
        ans = i;
    }

    printf("%d\n", ans);
    return 0;
}
