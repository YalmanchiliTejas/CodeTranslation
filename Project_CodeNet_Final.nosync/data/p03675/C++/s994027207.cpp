#include<bits/stdc++.h>
using namespace std;
int n,ch;
int aa[200002];
int up=100001,dn=100001;
void push(int a[],int now){
  if(now==0){
    aa[dn]=a[now];
    return;
  }
  push(a,now-1);
  if(ch==0){
    dn--;
    aa[dn]=a[now];
    ch=1;
    return;
  }else{
    up++;
    aa[up]=a[now];
    ch=0;
    return;
  }
}
int main(){
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  push(a,n-1);
  if(ch==1){
    for(int i=dn;i<up;i++){
      cout<<aa[i]<<' ';
    }
    cout<<aa[up]<<endl;
  }else{
    for(int i=up;i>dn;i--){
      cout<<aa[i]<<' ';
    }
    cout<<aa[dn]<<endl;
  }
  return(0);
}
