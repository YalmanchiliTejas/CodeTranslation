#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,0,h) cin >> a[i];
  vector<bool> r(h,false), c(w,false);
  rep(i,0,h) {
    rep(j,0,w) {
      if (a[i][j] == '#') r[i] = true;
    }
  }
  rep(j,0,w) {
    rep(i,0,h) {
      if (a[i][j] == '#') c[j] = true;
    }
  }
  rep(i,0,h) {
    if (!r[i]) continue;
    rep(j,0,w) {
      if (c[j]) cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
