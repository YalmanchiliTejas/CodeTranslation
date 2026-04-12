#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

constexpr int MAX_H = 8;
constexpr int MAX_W = 8;
int H, W;
char a[MAX_H + 1][MAX_W + 1];

void _main() {
  cin >> H >> W;
  rep(i, 0, H) cin >> a[i];

  int cnt = 0;
  rep(i, 0, H) rep(j, 0, W) if (a[i][j] == '#') cnt++;
  if (cnt == H + W - 1) cout << "Possible" << "\n";
  else cout << "Impossible" << "\n";
}