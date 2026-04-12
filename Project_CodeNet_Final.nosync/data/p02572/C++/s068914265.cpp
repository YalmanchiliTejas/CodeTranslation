#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long long int sum=0;
  long long int arr[n];
  long long int main=0;
  long long int mod=1000000007;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }
  for(int i=0;i<n;i++)
  {
    sum=sum-arr[i];
    main+=(arr[i]%mod*(sum%mod))%mod;
  }
  cout<<main%mod<<endl;
}