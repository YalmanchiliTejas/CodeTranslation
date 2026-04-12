#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> c(26);
  string s, t;
  cin >> t;
  for(auto k : t) c[k-'a']++;
  rep(i,n-1) {
    cin >> s;
    vector<int> b(26,0);
    for(auto k : s) b[k-'a']++;
    rep(j,26) c[j] = min(c[j],b[j]); 
  }
  string ans = "";
  rep(i,26) {
    rep(j,c[i]) ans += (char)('a'+i);
  }
  cout << ans << endl;
  return 0;
}
