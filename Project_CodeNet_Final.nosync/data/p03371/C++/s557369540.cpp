#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans=1e9;
  for(int i=0;i<=max(x,y);++i){
    ans=min(ans,2*i*c+max(0,x-i)*a+max(0,y-i)*b);
  }
  cout << ans << endl;
  return 0;
}
