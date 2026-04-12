#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[105];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    ll ans = 0;
    while(1)
    {
        ll maxx = a[0];
        int index = 0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>maxx)
            {
                maxx = a[i];
                index = i;
            }
        }
        if(maxx<n)
            break;
        for(int i=0;i<n;i++)
        {
            if(i==index)
                a[i] = maxx%n;
            else
                a[i]+= maxx/n;

        }

        ans+=maxx/n;
    }
    printf("%lld",ans);
    return 0;
}
