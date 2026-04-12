#include<bits/stdc++.h>
using namespace std;

long long moduloMultiplication(long long a, long long b, long long mod) 
{ 
    long long res = 0;
    a %= mod; 
  
    while (b) 
    {  if (b & 1) 
          res = (res + a) % mod; 
          a = (2 * a) % mod;  
        b >>= 1;
    }   
    return res; 
} 

int main()
{
  long long mod=pow(10,9)+7,n;
  cin>>n;
  long long arr[n],sum=0,ans=0,pro;
  
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }
  for(int i=0;i<n-1;i++)
  {
    sum-=arr[i];
    pro=moduloMultiplication(sum,arr[i],mod)%mod;
    ans=(pro%mod+ans%mod)%mod;
  }
  cout<<ans;
  return 0;
}