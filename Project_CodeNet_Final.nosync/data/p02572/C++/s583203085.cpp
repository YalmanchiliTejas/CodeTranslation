#include <bits/stdc++.h>
 
using namespace std;
#define int long long int
int32_t main() {
    
    int n;
    cin>>n;
    int a[n];
    int x=1000000007;
    for(int i=0;i<n;i++)
   {
       cin>>a[i];
      // s+=a[i];
   }
  // s=s*s;
    int sum[n],s=0;
    for(int i=n-1;i>=0;i--)
    {
      s=s+a[i];
      sum[i]=s;
      
      //sum=sum+(a[i]*a[i]);
        //sum[i]=s;
    }
  int ss=0,si=0;
  for(int i=0;i<=n-2;i++)
    {
      si=((a[i]%x)*(sum[i+1]%x))%x;
      ss=ss%x+si%x;
      //sum=sum+(a[i]*a[i]);
        //sum[i]=s;
    }
    ss=ss%x;
    
    cout<<ss;
    
    return 0;
}
