#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 2*c*(max(x,y));
  REP(i,0,max(x,y)){
    ll dou = 2*c*i + +a*max(0,x-i) + b*max(0,y-i);
    ans = min(ans,dou);
  }

  cout << ans << endl;

  //--debug : end_stoper
  string end_stoper; cin >> end_stoper;

  return 0;
}