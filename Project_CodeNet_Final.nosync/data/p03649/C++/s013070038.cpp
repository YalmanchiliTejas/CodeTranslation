#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL inf=1e17;
LL a[55];



int main()
{
    int i, j;
    LL n;
    cin>>n;
    LL ma=1e17, mi=0, sum=0;
    LL ans=0;
    for(i=1; i<=n; i++)scanf("%lld", &a[i]);
    while(true)
    {
        LL x=0;
        for(i=1; i<=n; i++)x+=a[i]/n;
        ans+=x;
        for(i=1; i<=n; i++)
        {
            a[i]+=x-a[i]/n*(n+1);
        }
        bool f=true;
        for(i=1; i<=n; i++)f=f&(a[i]<n);
        if(f)break;
    }
    cout<<ans<<endl;
    
}
