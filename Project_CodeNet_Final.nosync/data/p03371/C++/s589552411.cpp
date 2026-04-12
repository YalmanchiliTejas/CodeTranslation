#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans=a*x+b*y;
  
  for(int i=1;i<=max(x,y);i++){
    ans=min(ans,max(x-i,0)*a+max(y-i,0)*b+c*2*i);
  }
  cout << ans << endl;
}