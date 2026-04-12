#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define FOR(i, m, n) for(int i = (m); i < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

signed main() {
  string s;
  cin >> s;
  if(s[0] != s[1] || s[0] != s[2] || s[1] != s[2]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
