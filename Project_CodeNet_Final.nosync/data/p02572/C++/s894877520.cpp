#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
typedef long long ll;
using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll cum[n];
    ll sum=0;
    ll mod=1000000007;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        cum[i]=sum;
    }

    ll temp=cum[n-1];
    ll ans=0;
    ll x;
    for(int i=0;i<n;i++)
    {

        x=((a[i]%mod)*((temp-cum[i])%mod))%mod;
        ans=((ans%mod)+(x%mod))%mod;
    }

    cout<<ans<<endl;

 return 0;
}
