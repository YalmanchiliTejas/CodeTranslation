#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
#include <set>
using namespace std;
typedef unsigned long long ll;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

ll ans=0;
int a[maxn];
ll sum[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=(sum[i-1]+a[i])%MOD;
    }
    ll ans=0;
    for(int i=n;i>1;i--)
    {
        ans=(ans+sum[i-1]*a[i])%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
