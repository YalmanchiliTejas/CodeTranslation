#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long int mod=1e9+7;
  long long int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  long long int sum=0;
  for(int i=0;i<n;i++)
    sum=sum+arr[i];
  long long int res=0;
  for(int i=0;i<n-1;i++)
  {
    long long int a=sum-arr[i];
    sum=sum-arr[i];
    long long int p=((arr[i]%mod)*(a%mod))%mod;
    res=res+p;
  }
  long long int x=res%mod;
  cout<<x;
}
    