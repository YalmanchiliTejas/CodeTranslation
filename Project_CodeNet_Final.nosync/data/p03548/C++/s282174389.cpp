#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int tmp=x-z;
  int ans=tmp/(y+z);
  cout<<ans<<endl;
  return 0;
}