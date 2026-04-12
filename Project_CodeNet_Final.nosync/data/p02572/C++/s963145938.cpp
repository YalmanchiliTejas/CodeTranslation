#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision; 

using namespace std;

//#Rohitpratap311
//#Keep Calm And Stay Happy

typedef long long ll;
typedef long double ld;

bool ifprime(ll n)
{
    if(n==2||n==3) { return true ; }
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) { return false; }
    }
    return true;
}

ll gcd(ll a,ll b)
{
    if(b==0) { return a; }
    return gcd(b,a%b);
}
 
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll mod=1000000007;
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) { cin>>arr[i]; }
        vector<ll> sum(n);
        sum[0]=arr[0];
        for(ll i=1;i<n;++i)
        {
            sum[i]=(sum[i-1]%mod+arr[i]%mod)%mod;
        }
        ll ans=0;
        for(ll i=1;i<n;++i)
        {
            ans=(ans+((arr[i]%mod)*(sum[i-1]%mod))%mod)%mod;
        }
        cout<<ans;


    }
    return 0;
}