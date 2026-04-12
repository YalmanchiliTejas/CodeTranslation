#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n, d[300000], mx = 0, mi;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &d[i]);
        
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (mx >= i)
        {
            mx = max(mx, i + d[i] / 10);
        }
    }
    if (mx < n - 1)
    {
        printf("no\n");
        return 0;
    }
    mi = n - 1;
    for (int i = n - 1; i > 0; --i)
    {
        if (mi <= i)
        {
            mi = min(mi, i - d[i] / 10);
        }
    }
    if (mi <= 0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}

