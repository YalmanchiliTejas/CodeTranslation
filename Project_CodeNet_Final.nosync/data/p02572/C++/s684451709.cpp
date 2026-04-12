#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long power(long long x, long long y) 
{ 
    long long res = 1;    
    x=x%mod;
    while(y>0) 
    { 
        if(y & 1) 
        res=(res*x)%mod; 
        y=y/2; 
        x=(x*x)%mod;   
    } 
    return res; 
}
int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
   
      long long n,i,j,k,sum=0,count=0,ans=0,x=0,y=0,l,r,m;
      cin>>n;
      long long a[n];
      for(i=0;i<n;i++)
      {
          cin>>a[i];
          sum=(sum+a[i])%mod;
          count=(count+(a[i]*a[i])%mod)%mod;
      }
      sum=(sum*sum)%mod;
      ans=(sum-count+mod)%mod;
      ans=(ans*(power(2,mod-2)))%mod;
      cout<<ans;
	return 0;
}