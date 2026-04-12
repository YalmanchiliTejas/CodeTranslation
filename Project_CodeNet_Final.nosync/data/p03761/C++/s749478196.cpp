#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;
  
  vector<map<char, int> > vm(n);
  rep(i, 0, n) {
    string s;
    cin >> s;
    int L = s.size();
    rep(j, 0, L)
      vm[i][s[j]]++;
  }
  
  vector<int> b(26, 51);
  rep(i, 0, n) {
    rep(j, 0, 26) {
      b[j] = min(b[j], vm[i][j+'a']);
    }
  }
  
  rep(i, 0, 26) {
    rep(j, 0, b[i]) {
      cout << char(i+'a');
    }
  }
  cout << "\n";
}