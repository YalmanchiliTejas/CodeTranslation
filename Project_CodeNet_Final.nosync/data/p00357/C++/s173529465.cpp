#include <iostream>
#include <algorithm>
using namespace std;
int main(){

  int n,a[300000]={},r1=0,r2=0,can=0;

  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++){
    int how=a[i]/10;
    can=max(can,i+how);
    if(can>=n-1){
      r1=1;
      break;
    }
    if(can==i) break;
  }
  if(r1==0){
    cout<<"no"<<endl;
    return 0;
  }
  can=0;
  reverse(a,a+n);
  for(int i=0;i<n;i++){
    int how=a[i]/10;
    can=max(can,i+how);
    if(can>=n-1){
      r2=1;
      break;
    }
    if(can==i) break;
  }
  if(r2==0){
    cout<<"no"<<endl;
    return 0;
  }
  cout<<"yes"<<endl;
  return 0;

}