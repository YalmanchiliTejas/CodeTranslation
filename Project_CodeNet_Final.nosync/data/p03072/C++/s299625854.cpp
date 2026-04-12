#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,h,maxh=0,r=0;
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>h;
    if(maxh<=h){
      r++;
      maxh=h;
    }
  }
  cout<<r<<endl;
  return 0;
}