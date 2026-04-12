#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n; cin>>n; int arr[n+2]; for(int i=0;i<n;i++)cin>>arr[i];
  int brr[n+2],j=0,t=0;ll g=1000000007,ans=0;
  for(int i=n-1;i>0;i--){
    t=(t+arr[i])%g;
    brr[i-1]=t;j++;
  }
  for(int i=0;i<n-1;i++){
    ans=(ans+(((arr[i])%g)*((brr[i])%g)))%g;
  }
  cout<<ans;
}
