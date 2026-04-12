#include<iostream>
using namespace std;
int main(){
  int i,n,sum=1,j,flag;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(i=1;i<n;i++){
    flag=1;
    for(j=0;j<i;j++){
      if(a[i]<a[j]){
        flag=0;
        break;
      }
    }
    if(flag)
      sum++;
  }
  cout<<sum;
  return 0;
}