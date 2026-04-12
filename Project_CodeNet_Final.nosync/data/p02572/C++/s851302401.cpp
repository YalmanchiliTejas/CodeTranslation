#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MOD 1000000007
#define print(A,n) for(ll i=0;i<n;++i)cout<<A[i]<<' ';cout<<endl;
#define take(A,n) for(ll i=0;i<n;++i)cin>>A[i];
//    for(auto& it : m)
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
ll int power(ll int x, ll int y, ll int p)  
{  
   ll int res = 1;     // Initialize result  
 
    x = x % p; // Update x if it is more than or  
                // equal to p
   
    if (x == 0) return 0; // In case x is divisible by p;
 
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
 


int main()
{
 
  fastio();

ll int T=1;

while(T--)
{
    ll int n,i;
    cin>>n;
    ll int a[n];
    ll int sum=0,ans=0;
    for(i=0;i<n;i++)
        {cin>>a[i];sum+=a[i];sum%=MOD;}
    for(i=0;i<n;i++)
    {
        sum-=a[i];
        sum+=MOD;
        sum%=MOD;
        ans+=a[i]*sum;
        ans%=MOD;
    }
    cout<<ans<<endl;
}



return 0;}