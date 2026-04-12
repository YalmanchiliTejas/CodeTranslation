#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lpin(a,i,n) for(int i=0;i<n;i++){cin>>a[i];}

int a[1000000],b[1000000],check;

void migi(int i,int n){
  lp(x,n){
    if(a[x]==0) 1;
    else{
      b[x]+=1;
      b[x+a[x]]-=1;
    }
  }
  for(int x=1;x<n;x++){
    b[x]+=b[x-1];
  }
  lp(x,n){
    if(b[x]>0) 1;
    else{
      check=1;
      return;
    }
  }
  return;
}

int main(){
  int n;
  cin>>n;
  lp(i,n){
    cin>>a[i];
    a[i]/=10;
  }
  check=0;
  migi(0,n);
  if(check==0){
    lp(j,1000000){
      b[j]=0;
    }
    check=0;
    reverse(a,a+n);
    migi(0,n);
    if(check==0){
      cout<<"yes"<<endl;
    }
    else cout<<"no"<<endl;
  }
  else cout<<"no"<<endl;
  
  return 0;
}
