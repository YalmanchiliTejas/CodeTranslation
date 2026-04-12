#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
  cin>>n;
  long long sum[n+1];
  sum[n]=0;
  long long arr[n];
  for(int i=0;i<n;i++){
   cin>>arr[i]; 
   
  }
  for(int i=n-1;i>0;i--){
       sum[i]=arr[i]+sum[i+1];
       sum[i]%=1000000007;
   // cout<<sum[i]<<" "<<n<<endl;
      
  }
  long long ans=0;
  for(int i=0;i<n-1;i++){
    //   cout<<arr[i]<<endl;
    //   cout<<sum[i+1]<<endl;
    ans+=(arr[i]*sum[i+1])%(1000000007);
    ans%=1000000007;
  }
  cout<<ans<<endl;
  return 0;
}