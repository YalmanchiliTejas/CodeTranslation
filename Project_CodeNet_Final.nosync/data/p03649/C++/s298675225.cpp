#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf (1e18 + 7)
using namespace std;

long long num[55], n;

long long get()
{
    long long res = 0;
    while(1)
    {
        long long mx = -inf, id;
        for(int i = 1;i <= n;i++)
        {
            if(mx < num[i])
                mx = num[i], id = i;
        }
        if(mx <= n - 1)
            break;
        long long cnt = (mx - n + 1) / n;
        if((mx - n + 1) % n)
            cnt++;
        num[id] -= cnt * n;
        for(int i = 1;i <= n;i++)
        {
            if(i == id)
                continue;
            num[i] += cnt;
        }
        res += cnt;
    }
    return res;
}

int main()
{
    scanf("%lld", &n);
    for(int i = 1;i <= n;i++)
        scanf("%lld", &num[i]);
    printf("%lld\n", get());
    return 0;
}

