#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)

typedef long long ll;
const int maxn=1e5+10;
ll a[maxn];

int main()
{
    ll n,sum,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    if(n%2)
    {
        ans=0;
        sum=0;
        int m=n/2+1;
        for(int i=1;i<=m-2;i++)
            sum-=2*a[i];
        sum-=(a[m-1]+a[m]);
        for(int i=m+1;i<=n;i++)
            sum+=2*a[i];
        ans=max(ans,sum);
        sum=0;
        for(int i=m+2;i<=n;i++)
            sum+=2*a[i];
        sum+=a[m]+a[m+1];
        for(int i=m-1;i>=1;i--)
            sum-=2*a[i];
        ans=max(sum,ans);
        cout << ans << endl;
    }
    else
    {
        ans=0;
        int m=n/2;
        int l=1,r=n;
        for(int i=1;i<m;i++)
        {
            ans+=a[r]*2;
            ans-=a[l]*2;
            r--,l++;
        }
        cout << ans+a[r]-a[l] << endl;
    }
    return 0;
}
