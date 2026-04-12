#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void die() {
  cout << "Impossible\n";
  exit(0);
}

void solve() {
  int r, c;
  cin >> r >> c;
  vector<pii> v;
  for(int i = 0; i < r; i++) {
    string s;
    cin >> s;
    int lhs = c;
    int rhs = -1;
    int seen = 0;
    for(int j = 0; j < c; j++) {
      if(s[j] == '#') {
        lhs = min(lhs, j);
        rhs = max(rhs, j);
        seen++;
      }
    }
    if(seen != rhs - lhs + 1) {
      die();
    }
    v.push_back({lhs, rhs});
  }
  if(v[0].first != 0) die();
  if(v[r-1].second != c-1) die();
  for(int i = 1; i < v.size(); i++) {
    if(v[i-1].second != v[i].first) die();
  }
  cout << "Possible\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
