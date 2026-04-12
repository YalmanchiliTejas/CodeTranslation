#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>

int main()
{
    int N, H[20];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &H[i]);
    int ans = 1;
    int highest = H[0];
    for (int i = 1; i < N; ++i)
    {
        if (H[i] >= highest)
        {
            ++ans;
            highest = H[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}