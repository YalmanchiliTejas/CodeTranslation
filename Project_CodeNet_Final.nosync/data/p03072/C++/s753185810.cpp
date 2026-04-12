#include<bits/stdc++.h>
using namespace std;
int n;
int a[30];
int main() {
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int max=-1,sum=0;
  for(int i=0;i<n;i++){
  	if(a[i]>=max) {
      sum++;
      max=a[i];
    }
  }
  cout<<sum<<endl;
  return 0;
}