#include <bits/stdc++.h>
using namespace std;

const int maxn = 22;
int main()
{
    int T;
    int H[maxn];
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d", &H[i]);
    }
    int high = 0;
    int ans = 0;
    for (int i = 0; i < T; ++i)
    {
        high = max(high, H[i]);
        if (H[i] >= high)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}