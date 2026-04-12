#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans=0;
  if(a+b>=2*c){
    ans=2*c*min(x,y);
    if(a>=2*c && x>y){
      ans=ans+2*c*(x-y);
    }else if(b>=2*c && y>x){
      ans=ans+2*c*(y-x);
    }else{
      if(x>y) ans=ans+a*(x-y);
      else ans=ans+b*(y-x);
    }
  }else{
    ans=a*x+b*y;
  }
  cout << ans << endl;
}