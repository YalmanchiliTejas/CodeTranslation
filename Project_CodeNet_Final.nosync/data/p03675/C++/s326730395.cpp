#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,a[200009];
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  if(n%2==0){
    for(int i=n-1;0<=i;i-=2){
      cout<<a[i]<<' ';
    }
    for(int i=0;i<n;i+=2){
      if(i+2>=n)cout<<a[i]<<endl;
      else cout<<a[i]<<' ';
    }
  }
  else{
    if(n==1){
      cout<<a[0]<<endl;
      return(0);
    }
    for(int i=n-1;0<=i;i-=2){
      cout<<a[i]<<' ';
    }
    for(int i=1;i<n;i+=2){
      if(i+2>=n)cout<<a[i]<<endl;
      else cout<<a[i]<<' ';
    }
  }
  return(0);
}
