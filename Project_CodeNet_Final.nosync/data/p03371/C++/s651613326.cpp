#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a,b,c,x,y,ll0=0,m=LONG_LONG_MAX; cin>>a>>b>>c>>x>>y;
  for(int i=0;i<=max(x,y)*2;i+=2) m=min(m,c*i+a*max(ll0,x-i/2)+b*max(ll0,y-i/2));
  cout<<m;
}