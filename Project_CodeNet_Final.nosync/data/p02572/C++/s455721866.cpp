#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
const int MOD=1e9+7;
#define pb push_back
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define ci cout<<"impossible\n"
typedef unsigned long long int ull;
typedef long long int ll;

ll a[500005];
const int M=1e4;
ll cnt[M];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    ll val=0;
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        val+=a[i-1];
        ans=(ans+(val%MOD*a[i]%MOD))%MOD;
    }
    cout<<ans<<endl;
}


