#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
  int n; string s = ""; cin >> n;
  vector<map<char, int>> v(n); vector<int> u(26, 1e9);
  rep(i, n){
    string t; cin >> t;
    rep(j, t.size()) v[i][t[j]]++;
    rep(j, 26) u[j] = min(u[j], v[i][(char)('a'+j)]);
  }
  rep(i, 26) rep(j, u[i]) s += (char)('a'+i);
  cout << s << "\n";
  return 0;
}