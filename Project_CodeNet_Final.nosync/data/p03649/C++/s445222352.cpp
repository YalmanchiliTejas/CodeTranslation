#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll a[55];
ll b[55];
ll l=1,r=1e16+1000;
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    sort(a+1,a+1+n,greater<ll>());
    while(a[1]>=n)
    {
        ll t=0;
        t+=a[1]/n;
        a[1]%=n;
        for(int i=2;i<=n;i++)
            a[i]+=t;
        ans+=t;
        sort(a+1,a+1+n,greater<ll>());
    }
    cout<<ans<<endl;
//////////////
    return 0;
}
