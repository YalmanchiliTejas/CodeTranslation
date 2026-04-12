#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll a[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    ll ans=0;
    if(n%2==0)
    {
        for(int i=0;i<n/2;i++)
        {
           if(i!=n/2-1)
           {
               ans=ans+2*(a[n-1-i]-a[i]);
           }
           else
           {
              ans=ans+(a[n-1-i]-a[i]);
           }
        }
    }
    else
    {
        int k=0;
        ll anss=0;
        for(int i=n/2;i>=0;i--)
        {
            if(k<=1)
            {
                ans-=a[i];
                k++;
            }
            else
            {
                ans-=2*a[i];
            }
        }
        for(int i=n/2+1;i<n;i++)
        {
            ans+=2*a[i];
        }
        for(int i=0;i<=n/2-1;i++)
        {
            anss-=2*a[i];
        }
        k=0;
        for(int i=n/2;i<n;i++)
        {
            if(k<=1)
            {
                anss+=a[i];
                k++;
            }
            else
            {
                anss+=2*a[i];
            }
        }
        ans=max(ans,anss);
    }
    cout<<ans<<endl;
    return 0;
}
