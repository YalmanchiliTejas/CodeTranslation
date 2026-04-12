#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define mod 1000000007
int main()
{
    ll n;
    cin>>n;
    
    ll v[n];
    ll sum[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    
   ll ans = 0;
   sum[0] = v[0];
   for (int i = 1; i < n; i++)
   {
      sum[i] = (sum[i - 1] + v[i]);
   }
   ll sm = sum[n - 1];
   for(int i=0;i<n;i++)
   {
      ans = (ans + mod + (((sm - sum[i]) % mod) * v[i]) % mod) % mod;
   }
   cout << ans << endl;
    
    
    return 0;
}