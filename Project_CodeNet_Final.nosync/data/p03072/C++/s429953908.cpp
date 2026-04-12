#include<iostream>
using namespace std;
int a[25];
int main(){
  int n,i,sum=0,mx=0;
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
    if(a[i]>=mx)
    {
      sum++;
      mx=a[i];
    }
  }
  cout<<sum;
  return 0;
}