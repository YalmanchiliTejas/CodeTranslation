#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
int n;
cin>>n;
long long int a[n];
long long int b[n];
for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }

 long long int sum=0;
 b[0]=a[0];
 for(int i=n-2;i>=0;i--)
 { b[i]=a[i];
   a[i]= (a[i]%mod + a[i+1]%mod)%mod;
 }
 b[n-1]=a[n-1];

 long long int ans=0;
 for(int i=0;i<n-1;i++)
 {
   ans +=(  ((a[i+1]%mod) *(b[i]%mod))%mod  );
   ans=ans%mod;
 } 
 cout<<ans<<endl;

  return 0;
}