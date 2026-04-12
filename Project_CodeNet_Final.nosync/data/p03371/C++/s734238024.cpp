#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;

  int ans=1e9;
  for (int i=0; i<=max(2*x,2*y); i++) {
    ans=min(ans,a*max(0,(x-i/2))+b*max(0,(y-i/2))+i*c);
  }
  
  cout <<ans<< endl;
  return 0;
}