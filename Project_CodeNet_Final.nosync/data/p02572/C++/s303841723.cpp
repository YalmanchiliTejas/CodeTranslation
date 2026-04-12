#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
#define inf 1e18
#define mod 1000000007

void testCase()
{
    //ll t; cin>>t; while(t--)
    {
     ll n;
     cin>>n;
     ll ar[n+5];
     for(int i=1;i<=n;i++)
     cin>>ar[i];
     ll sum=ar[n];
     ll ans=0;
     for(int i=n-1;i>=1;i--)
     {
         ans=(ans+(ar[i]*sum)%mod)%mod;
         sum=(sum+ar[i])%mod;
     }
     cout<<ans;




    } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    testCase();
    return 0;
}