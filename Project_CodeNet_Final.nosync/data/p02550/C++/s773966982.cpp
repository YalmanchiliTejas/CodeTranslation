#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200009
#define mx 10000000000008
#define mod 1000000007
ll n,t,arr[sz],brr[sz],crr[sz],x,m;
vector<ll>v;
int main()
{
    scanf("%lld %lld %lld",&n,&x,&m);
    t=x;
    arr[x]=1;
    brr[1]=x;
    for(int i=2;i<=n;i++)
    {
        ll val=(x*x)%m;
        brr[i]=brr[i-1]+val;
        if(arr[val])
        {
            ll num=i-arr[val];
            ll sum=brr[i]-brr[arr[val]];
            ll rem=n-i;
            ll jog=(rem/num)*sum;
            ll ans=brr[i]+jog;
            ll bak=rem%num;
            for(int i=1;i<=bak;i++)
            {
                val=(val*val)%m;
                ans+=val;
            }
            printf("%lld\n",ans);
            return 0;
        }
        x=val;
        arr[val]=i;
    }
    printf("%lld\n",brr[n]);
    return 0;
}
