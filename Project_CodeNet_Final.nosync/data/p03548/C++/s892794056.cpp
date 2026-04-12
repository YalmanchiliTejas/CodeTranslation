#include<bits/stdc++.h>
using namespace std;
int x,y,z,l,r,m;
signed main(){
  cin>>x>>y>>z;
  r=x/y+1;
  while(l+1<r){
    m=(l+r)/2;
    (m*(y+z)+z<=x?l:r)=m;
  }
  cout<<l;
}