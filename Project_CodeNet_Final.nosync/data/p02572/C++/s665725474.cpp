#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

// ll power(ll x,ll y)
// {
//     ll ml=1;
//     while(y>0)
//     {
//         if(y&1)
//         {
//             ml=(ml*x)%mod;
//         }
//         x=(x*x)%mod;
//         y/=2;
//     }
//     return ml;
// }

// ll inverse(ll x)
// {
//     return power(x,mod-2);
// }
int main() 
{
    ll n;
    ll i,j,x;

    ll sm=0;
    ll smsq=0;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        sm=(sm+x)%mod;
        smsq=(smsq+x*x)%mod;
    }
    sm=(sm*sm)%mod;
    
    sm=(sm-smsq+mod)%mod;
    
    cout<<(sm*500000004)%mod;
    
    
}