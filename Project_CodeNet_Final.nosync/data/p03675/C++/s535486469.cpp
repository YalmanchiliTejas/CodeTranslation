#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf (1e9 + 7)
#define eps 0.000001
using namespace std;

int n, num[500005], l, r;

int main()
{
    l = 250001;
    r = 250000;
    scanf("%d", &n);
    for(int i = 1, a;i <= n;i++)
    {
        scanf("%d", &a);
        if(i % 2)
            l--, num[l] = a;
        else
            r++, num[r] = a;
    }
    if(n % 2)
    {
        for(int i = l;i <= r;i++)
        {
            if(i == l)
                printf("%d", num[i]);
            else
                printf(" %d", num[i]);
        }
        puts("");
    }
    else
    {
        for(int i = r;i >= l;i--)
        {
            if(i == r)
                printf("%d", num[i]);
            else
                printf(" %d", num[i]);
        }
        puts("");
    }
    return 0;
}
