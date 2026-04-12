#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z;
  cin>>x>>y>>z;
  int res=0;
  for (int i=z; i+y+z-1<x; i=i+y+z) {
    res++;
  }
  
  cout<<res<<endl;
}
