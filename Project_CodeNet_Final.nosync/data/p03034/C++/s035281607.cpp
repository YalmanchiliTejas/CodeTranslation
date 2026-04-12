#if 1

#include <bits/stdc++.h>
using namespace std;
int a[200005],n;

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long cnt,ans = 0;
    for(int i = 1;i < n;i++)
    {
        int l = 1,r = n;
        cnt = 0;
        while(l < n-i)
        {
            if(l == r||l-i == r) break;
            cnt += a[l];
            cnt += a[r];
            ans = max(ans,cnt);
            l += i;
            r -= i;
        }
    }
    printf("%lld",ans);
}

#endif // 1++