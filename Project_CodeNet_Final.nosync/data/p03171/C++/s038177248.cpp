#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll p=pow(10,9)+7;
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      
    x = x % p;  
   while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 

ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,j,k;
   cin>>n;
   ll arr[n];
   for(i=0;i<n;i++)
   cin>>arr[i];
  ll dp[n][n];
  for(i=n-1;i>=0;i--)
  {
      for(j=i;j<n;j++)
      {
          if(i==j)
          dp[i][j]=arr[i];
          else
          {
              dp[i][j]=std::max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
          }
      }
  }
  cout<<dp[0][n-1];
  
      

   
  return 0;
    
}
    

