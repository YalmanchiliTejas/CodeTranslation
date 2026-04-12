#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a[200009];
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  if(n%2==0){
    for(int i=n;i>=2;i-=2){
      cout<<a[i]<<' ';
    }
    for(int i=1;i<n;i+=2){
      cout<<a[i];
      if(i==n-1)cout<<endl;
      else cout<<' ';
    }
  }
  else{
    for(int i=n;i>=1;i-=2){
      cout<<a[i]<<' ';
    }
    for(int i=2;i<=n-1;i+=2){
      cout<<a[i];
      if(i==n-1)cout<<endl;
      else cout<<' ';
    }
  }
  return(0);
}
