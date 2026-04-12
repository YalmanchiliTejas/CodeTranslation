#include<bits/stdc++.h>
using namespace std;
int main(){
long long int n;
  cin>>n;
  long long int a[n+1];
  for(long long int i=1;i<=n;i++)cin>>a[i];
    if(n%2){
      for(long long int j=n;j>=1;j=j-2)cout<<a[j]<<" ";
      for(long long int j=2;j<=n-1;j=j+2)cout<<a[j]<<" ";
    }
  else{
    for(long long int j=n;j>=2;j=j-2)cout<<a[j]<<" ";
    for(long long int j=1;j<=n-1;j=j+2)cout<<a[j]<<" ";
  }
  cout<<"\n";
}
      