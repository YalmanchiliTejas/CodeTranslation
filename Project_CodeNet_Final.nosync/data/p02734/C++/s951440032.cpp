#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
const int maxn=1e6+10;
const int mod=998244353;

ll dp[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        dp[0]=i;
        for(int j=k; j>=a; j--)
            dp[j]=(dp[j]+dp[j-a])%mod;
        ans=(ans+dp[k])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
