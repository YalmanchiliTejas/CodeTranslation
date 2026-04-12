#include<bits/stdc++.h>   
#include<tr1/unordered_map>
#define ll long long int  
#define mkp make_pair 
#define mod 1000000007 
#define maxn 1000002 
#define ff first
#define ss second 
using namespace std;      
bool isprime(ll n){    
    if(n==2||n==1)return true;
   if(n==0||n%2==0)return false; 
    
   for(int i=3;i*i<=n;i+=2)   
         if(n%i==0)return false; 
    return true;
}
int main(){    
  ios_base::sync_with_stdio(false);  
    
  cin.tie(NULL);      
    int n; 
  cin>>n; 
  ll arr[n];   
  ll s=0; 
  ll s1=0;
  for(int i=0;i<n;++i){  
       cin>>arr[i]; 
       s+=arr[i];  
       ll temp=((arr[i]%mod)*(arr[i]%mod))%mod;
       s1=(s1%mod+temp%mod)%mod;
    } 
  s=((s%mod)*(s%mod))%mod; 
  ll res=((s-s1)%mod+mod)%mod; 
  res=(res*500000004)%mod;
  cout<<res<<"\n";
  return 0;
}