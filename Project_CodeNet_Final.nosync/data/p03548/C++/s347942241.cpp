#include<bits/stdc++.h>
using namespace std;
signed main(){
  int x,y,z,l=0,r,m;
  cin>>x>>y>>z;
  r=x/y+1;
  while(l+1<r){
    m=(l+r)/2;
    (m*(y+z)+z<=x?l:r)=m;
  }
  cout<<l;
}