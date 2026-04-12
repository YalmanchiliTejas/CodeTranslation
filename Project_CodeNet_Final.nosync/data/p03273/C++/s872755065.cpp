#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

const int MAX_H = 100;
const int MAX_W = 100;
int H, W;
char a[MAX_H][MAX_W];
bool is_comp_h[MAX_H];
bool is_comp_w[MAX_W];

void _main() {
  cin >> H >> W;
  rep(i, 0, H) rep(j, 0, W) cin >> a[i][j];

  rep(i, 0, H) {
    bool f = true;
    rep(j, 0, W) if (a[i][j] == '#') f = false;
    is_comp_w[i] = f;
  }

  rep(j, 0, W) {
    bool f = true;
    rep(i, 0, H) if (a[i][j] == '#') f = false;
    is_comp_h[j] = f;
  }

  rep(i, 0, H) {
    if (is_comp_w[i]) continue;
    rep(j, 0, W) if (!is_comp_h[j]) cout << a[i][j];
    cout << "\n";
  }
}