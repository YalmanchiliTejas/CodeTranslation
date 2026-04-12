#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int z=max(x,y);
  int min1 = 1e10;
  for(int i=0;i<=z;i++){
    int d = 2*c*i + a * max(0,x-i) + b * max(0,y-i);
    min1 = min(min1, d);
  }
  cout<<min1<<endl;
}