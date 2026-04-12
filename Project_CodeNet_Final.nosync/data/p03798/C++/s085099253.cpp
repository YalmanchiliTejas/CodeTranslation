#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;

char next(char now, char prev, char stat){
  if(now == 'S'){
    if((prev=='S' && stat=='o') || (prev=='W' && stat=='x')) return 'S';
    return 'W';
  }
  if((prev=='S' && stat=='x') || (prev=='W' && stat=='o')) return 'S';
  return 'W';
}

int main(){
  int n; string s; cin >> n >> s;
  string init[4] = {"SS", "SW", "WS", "WW"};
  rep(i, 4){
    string ans = init[i];
    For(j, 1, n-1) ans += next(ans[j], ans[j-1], s[j]);
    if(ans[0]==next(ans[n-1], ans[n-2], s[n-1]) && ans[1]==next(ans[0], ans[n-1], s[0])){
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}