#include<bits/stdc++.h>
#define ll long long
#define fs first
#define sec second
#define md 1000000007
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
using namespace std;
ll power(ll x, unsigned ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p  
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  

ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T=1;
    // cin>>T;
    while(T--){
    	ll n;
        cin>>n;
        vector<ll> v(n);
        ll s=0;
        for(ll i=0;i<n;i++){
            cin>>v[i];
            s=(s+v[i])%md;
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            s=(s-v[i]+md)%md;
            ans=(ans+(s*v[i])%md)%md;
        }
        cout<<ans<<"\n";
    }
    return 0;
}