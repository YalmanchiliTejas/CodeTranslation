#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,z,y,cnt=0;
  cin>>x>>y>>z;
  for(int i=1;(z+y)*i<=x-z;i++)
    cnt++;
  cout<<cnt;
}