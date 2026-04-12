#include<bits/stdc++.h>
using namespace std;



int main(){
  int n;
  cin>>n;

  int a[300500];
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]=a[i]/10;
  }
  int mx=0;
  for(int i=0;i<=mx;i++){
    mx=max(mx,a[i]+i);
    if(mx>n){break;}
  }
  bool j=true;
  if(n-1>mx){j=false;}
  
  reverse(a,a+n);
  mx=0;
  for(int i=0;i<=mx;i++){
    mx=max(mx,a[i]+i);
    if(mx>n){break;}
  }
  if(n-1>mx){j=false;}
  
  if(j){cout<<"yes"<<endl;}
  else{cout<<"no"<<endl;}


  return 0;
}

