#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,h,maxh,r=1;
  cin>>n>>maxh;
  for(int i=1;i<n;++i){
    cin>>h;
    if(maxh<=h){
      r++;
      maxh=h;
    }
  }
  cout<<r;
  return 0;
}