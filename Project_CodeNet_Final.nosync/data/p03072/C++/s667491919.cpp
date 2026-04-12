#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,count = 0;
  cin>>n;
  int h[n];
  for(int i=0;i<n;++i){
    cin>>h[i];
  }
  for(int i=0;i<n;++i){
    int f=0;
    for(int j=0;j<i;++j){
      if(h[i]<h[j]){
        f=1;
      }
    }
    if(f==0){
      count++;
    }
  }
  cout<<count;
}
