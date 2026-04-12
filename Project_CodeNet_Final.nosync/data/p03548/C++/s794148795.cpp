#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int ans=0;
  x-=2*z;
  for(int i=1;i<x;i++){
    if(x>=y*i+z*(i-1)){
      ans++;
    }
    else{
      break;
    }
  }
  cout<<ans<<endl;
}