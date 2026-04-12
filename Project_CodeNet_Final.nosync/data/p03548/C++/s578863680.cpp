#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int cnt=x/(y+z);
  if(x%(y+z)>=z) cout<<cnt<<endl;
  else cout<<cnt-1<<endl;
}