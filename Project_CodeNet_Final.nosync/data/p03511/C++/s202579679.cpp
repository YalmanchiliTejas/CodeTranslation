#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int l;
  cin >> l;
  string s, t;
  cin >> s >> t;
  if(s > t) swap(s,t);
  int ls = s.length(), lt = t.length();
  string ans = "";
  int res = l;
  vector<bool> can(l+1,false);
  can[0] = true;
  rep(i,l) {
    if(can[i]) {
      if(i + ls <= l) can[i+ls] = true;
      if(i + lt <= l) can[i+lt] = true; 
    }
  }
  if(s == t) {
    int k = l / s.length();
    rep(i,k) ans += s; 
  } else {
    if(ls < lt and s == t.substr(0,ls)) {
      string u = t;
      int lu = u.length();
      while(ls < lu and s == u.substr(0,ls)) {
        u = u.substr(ls,lu-ls);
        lu = u.length();
      }
      bool f = false;
      if(u < s) f = true;
      if(lu < ls and u == s.substr(0,lu) and s.substr(lu,ls-lu) < u) f = false;
      while(res > 0) {
        if((f and res - lt >= 0 and can[res-lt]) or (res - ls < 0 or !can[res-ls])) {
          ans += t;
          res -= lt;
        } else {
          ans += s;
          res -= ls;
        }
      }
    } else {
      while(res > 0) {
        if(res - ls >= 0 and can[res-ls]) {
          ans += s;
          res -= ls;
        } else {
          ans += t;
          res -= lt;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
