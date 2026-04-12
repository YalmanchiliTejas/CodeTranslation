#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a[222222];
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  if(n%2==0){
    for(int i=n;i>=1;i-=2){
      cout<<a[i]<<' ';
    }
    cout<<a[1]<<' ';
    for(int i=3;i<=n-1;i+=2){
      cout<<a[i];
      if(i!=n-1) cout<<' ';
    }
  }else{
    for(int i=n;i>=1;i-=2){
      cout<<a[i]<<' ';
    }
    for(int i=2;i<=n-1;i+=2){
      cout<<a[i];
      if(i!=n-1) cout<<' ';
    }
  }
  cout<<endl;
  return(0);
}
