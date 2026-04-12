#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
const int mod=1e9+7;
#define ll long long

int a[maxn],sum[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=((ll)a[i]+sum[i-1])%mod;
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        int res=((ll)a[i]*sum[i-1])%mod;
        ans=(ans+res)%mod;
    }
    cout<<ans;
    return 0;
}