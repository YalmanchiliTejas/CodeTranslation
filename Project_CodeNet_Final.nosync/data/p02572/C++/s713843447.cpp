#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 200100;

int n;
ll a[N],cum[N],mod=1e9+7,ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);

    cum[n] = a[n];
    for(int i=n-1;i>=1;i--)
        cum[i] = ( cum[i+1] + a[i] ) %mod;

    for(int i=1;i<=n;i++)
        ans = ( ans + cum[i+1]*a[i]%mod )%mod;

    printf("%lld\n",ans);
}
