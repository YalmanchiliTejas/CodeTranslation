#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll H, W; cin >> H >> W;
  vector<string> field(H);
  rep(h, 0, H) cin >> field[h];
  bool f = true;
  rep(h, 0, H-1) rep(w, 0, W-1){
    if(field[h][w] == '#'&&field[h][w+1] == '#'
    && field[h+1][w] == '#'&&field[h+1][w+1] == '#') f = false;
    if(field[h][w] == '.'&&field[h][w+1] == '#'
    && field[h+1][w] == '#'&&field[h+1][w+1] == '#') f = false;
    if(field[h][w] == '#'&&field[h][w+1] == '#'
    && field[h+1][w] == '#'&&field[h+1][w+1] == '.') f = false;
  }

  if(f) cout << "Possible" << endl;
  else cout << "Impossible" << endl;

  return 0;
}
