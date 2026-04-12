#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k[200000];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>k[i];
  }
  if(n%2==1){
  for(int i=n-1;i>=0;i-=2){
    cout<<k[i]<<" ";
  }
  for(int i=1;i<=n-1;i+=2){
    cout<<k[i]<<" ";
  }
  }
  else{
    for(int i=n-1;i>=1;i-=2){
      cout<<k[i]<<" ";
    }
    for(int i=0;i<=n-2;i+=2){
      cout<<k[i]<<" ";
    }
  }
  cout<<endl;
}
