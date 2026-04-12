#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define lmin LONG_MIN
#define lmax LONG_MAX
#define imin ll_MIN
#define imax ll_MAX
#define ffor(i,a,b) for(i=a;i<b;i++)
#define bfor(i,a,b) for(i=a-1;i>=b;i--)
#define mset(f,a) memset(f,a,sizeof(f))
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAXN   10000009


ll mod = 1e9 +7;



int main() 
{
    ll t=1,temp;
    //cin>>t;
    ffor(temp,0,t)
    {
        fastio;
        ll n;
        cin>>n;
        ll arr[n];
        ll i;
        ffor(i,0,n)
            cin>>arr[i];
        
        ll sum=0;
        ffor(i,0,n)
            sum=(sum+arr[i]);
        ll s[n];
        ffor(i,0,n)
        {
            s[i]=sum-arr[i];
            sum=sum-arr[i];
        }
        ll ans=0;
        ffor(i,0,n)
        {
            ans=(ans+((arr[i]%mod)*(s[i]%mod))%mod)%mod;
        }
        cout<<ans<<endl;
    }
      
    
}
