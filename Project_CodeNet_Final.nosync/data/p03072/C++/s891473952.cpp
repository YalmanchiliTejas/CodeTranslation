#include<iostream>
using namespace std;
int a[25];
int main(){
  int n,i,sum=0,max=0;
  cin>>n;
  for(i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]>=max){
      sum++;
      max=a[i];
    }
  }
  cout<<sum;
  return 0;
}