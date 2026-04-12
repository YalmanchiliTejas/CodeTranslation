#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
  int ans=1e9;
  for(int i=0;i<=max(x,y);i++) {
    int cost=(max(x-i,0)*a)+(max(y-i,0)*b)+i*2*c;
    ans=min(ans,cost);
  }
  cout<<ans<<endl;
}
