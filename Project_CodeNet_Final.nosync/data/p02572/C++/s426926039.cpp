#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int main()
{

  long long n;
  cin>>n;
  long long arr[n];
  long long arr1[n];
  long long sum=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    arr[i]%=mod;
  }
  arr1[0]=arr[0];
   for(int i=1;i<n;i++){
    arr1[i]=arr1[i-1]+arr[i];
    arr1[i]%=mod;
  }
  for(int i=n-1;i>=1;i--){
    sum+=(arr[i]*arr1[i-1]);
    sum%=mod;
  }


    cout<<sum<<"\n";
	return 0;
}
