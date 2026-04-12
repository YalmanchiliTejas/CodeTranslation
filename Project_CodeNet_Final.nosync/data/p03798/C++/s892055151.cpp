#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  
  const int sheep = 0, wolf = 1;
  vi zoo(n);
  bool possible = false;

  rep(tmp,1<<2) {
    bitset<2> t(tmp);
    rep(i,2) {
      if (t.test(i)) zoo[i] = sheep;
      else zoo[i] = wolf;
    }

    for (int j=1; j<n-1; ++j) {
      if (zoo[j] == sheep) {
        if (s[j] == 'o') zoo[j+1] = zoo[j-1];
        else zoo[j+1] = 1 - zoo[j-1];
      }
      else {
        if (s[j] == 'x') zoo[j+1] = zoo[j-1];
        else zoo[j+1] = 1 - zoo[j-1];
      }
    }

    if (zoo[0] == sheep) {
      if (s[0] == 'o' && zoo[n-1] != zoo[1]) continue;
      if (s[0] == 'x' && zoo[n-1] == zoo[1]) continue;
    }
    else {
      if (s[0] == 'x' && zoo[n-1] != zoo[1]) continue;
      if (s[0] == 'o' && zoo[n-1] == zoo[1]) continue;
    }

    if (zoo[n-1] == sheep) {
      if (s[n-1] == 'o' && zoo[n-2] != zoo[0]) continue;
      if (s[n-1] == 'x' && zoo[n-2] == zoo[0]) continue;
    }
    else {
      if (s[n-1] == 'x' && zoo[n-2] != zoo[0]) continue;
      if (s[n-1] == 'o' && zoo[n-2] == zoo[0]) continue;
    }

    possible = true;
    break;
  }

  if (!possible) {
    cout << -1 << endl;
    return 0;
  }

  rep(i,n) {
    if (zoo[i] == sheep) cout << 'S';
    else cout << 'W';
  }
  cout << endl;
  return 0;
}
