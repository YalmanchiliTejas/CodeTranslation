#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> p;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, n) for(int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define srep(i, from, to) for(int i = from; i < (int)(to); i++)
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
template <class T> bool chmax(T &a, const T &b) {
  if(a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if(b < a) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) {
    cin >> a[i];
  }
  vector<bool> skiph(h);
  vector<bool> skipw(w);
  rep(i, h) {
    bool ok = true;
    rep(j, w) {
      if(a[i][j] == '#') ok = false;
    }
    skiph[i] = ok;
  }
  rep(i, w) {
    bool ok = true;
    rep(j, h) {
      if(a[j][i] == '#') ok = false;
    }
    skipw[i] = ok;
  }

  rep(i, h) {
    if(skiph[i]) continue;
    rep(j, w) {
      if(skipw[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
