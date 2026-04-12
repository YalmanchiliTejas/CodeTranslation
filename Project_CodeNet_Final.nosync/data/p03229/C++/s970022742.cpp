#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    int l=1,r=n-1,tl=0,tr=0;
    ll ans=0;
    int flag=1;
    while(l<=r)
    {
        long long k1=abs(a[tl]-a[l]),k2=abs(a[tl]-a[r]),k3=abs(a[tr]-a[l]),k4=abs(a[tr]-a[r]);
        if(k1>=k2&&k1>=k3&&k1>=k4)
        {
            ans+=k1;
            tl=l;l++;
        }
        else if(k2>=k1&&k2>=k3&&k2>=k4)
        {
            ans+=k2;
            tl=r;r--;
        }
        else if(k3>=k1&&k3>=k2&&k3>=k4)
        {
            ans+=k3;
            tr=l;l++;
        }
        else if(k4>=k1&&k4>=k2&&k4>=k3)
        {
            ans+=k4;
            tr=r;r--;
        }
    }
    printf("%lld\n",ans);
}
