#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int h,w;
int cnt = 0;

bool f(vector<vector<char>> &a, int i = 0, int j = 0) {
  cnt++;
  if (i == h-1 && j == w-1) return true;

  if (i+1 < h && j+1 && w && 
      a[i+1][j] == '#' && a[i][j+1] == '#') return false;

  bool fi = false, fj = false;
  if (i+1 < h && a[i+1][j] == '#') {
    fi = f(a, i+1, j);
  }
  if (j+1 < w && a[i][j+1] == '#') {
    fj = f(a, i, j+1);
  }

  if (fi || fj) return true;
  return false;
}

int main() {
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  int tot = 0;
  rep(i,h) rep(j,w) {
    cin >> a[i][j];
    if (a[i][j] == '#') tot++;
  }
  string ans = "Impossible";
  if (f(a) && cnt == tot) ans = "Possible";
  cout << ans << endl;
  return 0;
}