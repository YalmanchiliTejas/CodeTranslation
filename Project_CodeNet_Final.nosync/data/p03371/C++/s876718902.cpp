#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  int all = a*x+b*y;

  int ans = all;
  while (x > 0 && y > 0) {
      all = all - (a+b) + c*2;
      x--;
      y--;
  }
  ans = min(ans,all);

  if(x == 0){
    ans = min(ans, all - b*y+c*2*y);
  }
  if(y == 0){
    ans = min(ans, all - a*x+c*2*x);
  }
  cout << ans << endl;
}
