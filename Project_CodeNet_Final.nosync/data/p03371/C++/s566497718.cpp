#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  int ans=min(x,y)*min(a+b,2*c);
  if(x>y)ans+=min(a,2*c)*abs(x-y);
  if(x<y)ans+=min(b,2*c)*abs(x-y);
  cout<<ans<<endl;
}