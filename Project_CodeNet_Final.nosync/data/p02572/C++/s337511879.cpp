#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define int int64_t
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"

const int maxn=2e5+5;
int ar[maxn];

void solve()
{
    int n;
    cin>>n;
    int sum=0,ans=0;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(int i=0;i<n;i++)
        sum=(sum+ar[i])%mod;
    for(int i=0;i<n-1;i++)
    {
        sum=(sum-ar[i]+mod)%mod;
        ans=(ans+(ar[i]%mod*sum))%mod;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    fio;
    int t;
    // cin>>t;
    t=1;
    while(t--)
        solve();
}