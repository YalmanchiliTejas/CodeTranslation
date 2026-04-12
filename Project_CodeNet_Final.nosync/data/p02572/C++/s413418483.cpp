#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
// int a[100010],n,j;
int main()
{
  int size;
  cin >>size;
  long long  a[size];
  for(int i=0;i<size;i++)
    cin >> a[i];
  long long ans=0;
  long long suffix[size];
  long long sum=a[size-1];
  suffix[size-1]=a[size-1];
  for(int i=size-2;i>=1;i--)
  {
     sum+=a[i];
     sum%=mod;
     suffix[i]=sum;
  }
  for(int i=0;i<size-1;i++)
  {
    ans+=(a[i]%mod)*(suffix[i+1]%mod)%mod;
    ans%=mod;
  }
  cout << ans << endl;
  // for(int i=1;i<size;i++)
  //   cout << suffix[i] << " " ;
   
}