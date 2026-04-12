#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,l,r,a[50],j;
  while(cin>>n>>l>>r&&n&&l&&r){
    int cnt=0;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=l;i<=r;++i){
      for(j=0;j<n;++j){
        if(i%a[j]==0) break;
      }
      if(j<n){
        if((j+1)%2) ++cnt;
      }else{
        if(!(n%2)) ++cnt;
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}

