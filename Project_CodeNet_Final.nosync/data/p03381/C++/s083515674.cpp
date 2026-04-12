#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<map>
#include<iomanip>
using namespace std;
int a[222222],b[222222];
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i];
  }
  sort(b,b+n);
  int num1=b[n/2-1];
  int num2=b[n/2];
  for(int i=0;i<n;i++){
    if(a[i]<=num1)
      cout<<num2<<"\n";
    else
      cout<<num1<<"\n";
  }
  return 0;
}
