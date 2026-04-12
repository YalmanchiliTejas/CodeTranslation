#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;

int main(){
  int n;cin>>n;
  int h[n];
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    //bool型で初期化していく
    bool a=true;
    for(int j=0;j<i;j++){
      if(h[j]>h[i]){
        a=false;
        break;
    }
  }
    if(a) ans++;
  }
  cout<<ans<<endl;
  return 0;
}