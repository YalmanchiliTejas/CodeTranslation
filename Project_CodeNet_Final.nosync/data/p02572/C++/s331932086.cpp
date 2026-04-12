#include<iostream>
using namespace std;
 
int main()
{
 long long int n;
  cin>>n;
  long long int a[n+1];
  long long int mod=1000000007;
long long int sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
   sum+=a[i];
}
  long long int r=0;
  for(int i=0;i<n-1;i++)
  {
    sum-=a[i];
   r+=((a[i]%mod)*(sum%mod))%mod;
    r%=mod;
  }
  cout<<r<<endl;
}