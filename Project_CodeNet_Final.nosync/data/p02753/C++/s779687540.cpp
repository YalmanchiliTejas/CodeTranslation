#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll countGreater(ll arr[], ll n, ll k) 
{ 
    ll l = 0; 
    ll r = n - 1; 
  
 
    ll leftGreater = n; 
  
 
    while (l <= r) { 
        ll m = l + (r - l) / 2; 
  
        if (arr[m] > k) { 
            leftGreater = m; 
            r = m - 1; 
        } 
  
 
        else
            l = m + 1; 
    } 
  
   
    return (n - leftGreater); 
}
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

ll ans(ll A[],ll left,ll right,ll x)
{
    if(A[left]==x)return 1;

    else if(A[right==x])return 1;

   ll m=left+(right-left)/2;
   while(left<=right)
   {
    if(A[m]>x)right=m-1;
    else if(A[m]<x)left=m+1;
    else return 1;
   }
   return 0;
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
ll a=0,b=0,i;
  string s;
  cin>>s;
  for(i=0;i<3;i++)
  {
    if(s[i]=='A')a++;
    else b++;
  }

  if(a==3||b==3)cout<<"No"<<"\n";
  else cout<<"Yes"<<"\n";


    return 0;
    
}


 