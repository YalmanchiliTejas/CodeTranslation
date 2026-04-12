#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll inf=1000000007;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

ll a[200005], sum[200005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+a[i]*((sum[n]-sum[i])%inf)%inf)%inf;
    }
    cout << ans << endl;
    return 0;
}
