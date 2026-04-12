#include <bits/stdc++.h>
using namespace std;

int main() {
 int x,y,z;
 cin >>x >>y>>z;
  int total=z;
  int ans = 0;
for (int i=0;i>=0;i++){
  total+=y+z;
  if (total<=x)
   ans ++;
  else 
    break;
}
  cout <<ans ;
}
