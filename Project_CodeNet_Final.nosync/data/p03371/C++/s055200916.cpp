#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}


int main(){
  int a,b,c,x,y,ans = 0;
  cin >> a >> b >> c >> x >> y;

  if( a >= 2*c){
    ans += 2*x*c;
    y = max(y-x,0);
    x = 0;
  }

  if( b >= 2*c){
    ans += 2*y*c;
    x = max(x-y,0);
    y = 0;
  }

  if(a+b >= 2*c){
    int minXY = min(x,y);
    ans += 2*c*minXY;
    x-= minXY;
    y-= minXY;
  }

  cout << a*x + b*y + ans << endl;

  return 0;
}
