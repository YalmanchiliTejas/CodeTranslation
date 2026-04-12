#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
    ll n;cin>>n;
   ll ar[n];
   ll sum = 0,ans=0;
    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
        ans += (ar[i]%MOD*sum);
        sum += ar[i]%MOD;
        sum%= MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
   return 0;
}
