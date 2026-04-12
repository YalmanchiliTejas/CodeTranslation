#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() { 
  int n;
  cin >> n;
  vector<string> S(n);
  rep(i,n) cin >> S[i];
  vector<int> a(26, 50);
  rep(i,n) {
    map<char, int> mp;
    rep(j, S[i].length()) {
      mp[S[i][j]]++;
    }
    rep(j, 26) {
      a[j] = min(a[j], mp['a'+j]);
    }
  }
  string ans = "";
  rep(i,26) {
    string temp(a[i], 'a'+i);
    ans += temp;
  }
  cout << ans << endl;
  return 0;
}