#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  string s; cin >> s;

  int a = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A') a++;
  }
  int ans = 0;
  if(a == 1) ans = 2;
  if(a == 2) ans = 2;
  if(a == 3) ans = 0;
  cout << (ans == 2 ? "Yes" : "No") << endl;

  return 0;
}
