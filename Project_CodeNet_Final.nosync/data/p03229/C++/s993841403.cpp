#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
long long a;
long long d[500005];
int main()
{
    scanf("%lld",&a);
    long long ans=0;
    long long mi;
    int f=0;
    for(int i=0;i<a;i++)
        scanf("%lld",&d[i]);
    sort(d,d+a);
    long long q=0,r=a-1;
    long long t;
    for(int i=0;i<a;i++)
    {
        //cout<<d[q]<<" "<<d[r]<<endl;
        if(i%2==0)
        {
            if(d[r]>=d[q])
                t=d[r]-d[q++];
            else
                t=d[q++]-d[r];
            if(t<mi||f==0)
            {
                mi=t;
                f=1;
            }
            ans+=t;
        }
        else
        {
            if(d[r]>=d[q])
                t=d[r--]-d[q];
            else
                t=d[q]-d[r--];
            if(t<mi||f==0)
            {
                mi=t;
                f=1;
            }
            ans+=t;
        }
        if(q==r)
        {
            r=0;
        }
    }
    long long ans1=ans-mi;
    ans=0;
    f=0;
    sort(d,d+a,greater<long long>());
    q=0,r=a-1;
    for(int i=0;i<a;i++)
    {
        //cout<<d[q]<<" "<<d[r]<<endl;
        if(i%2==0)
        {
            if(d[r]>=d[q])
                t=d[r]-d[q++];
            else
                t=d[q++]-d[r];
            if(t<mi||f==0)
            {
                mi=t;
                f=1;
            }
            ans+=t;
        }
        else
        {
            if(d[r]>=d[q])
                t=d[r--]-d[q];
            else
                t=d[q]-d[r--];
            if(t<mi||f==0)
            {
                mi=t;
                f=1;
            }
            ans+=t;
        }
        if(q==r)
        {
            q=0;
        }
    }
    long long ans2=ans-mi;
    if(ans2<ans1)
        ans=ans1;
    else
        ans=ans2;
    printf("%lld\n",ans);
    return 0;
}
