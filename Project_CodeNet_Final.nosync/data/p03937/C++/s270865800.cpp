#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  int h, w; cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for(int i=0;i<h;++i) {
    for(int j=0;j<w;++j) {
      cin >> a[i][j];
    }
  }
  bool ans = true;
  for(int i=0;i<h;++i) {
    for(int j=0;j<w;++j) {
      int cnt1 = 0, cnt2 = 0;
      if(0 <= i-1) cnt1 += a[i-1][j] == '#';
      if(0 <= j-1) cnt1 += a[i][j-1] == '#';
      if(i+1 < h) cnt2 += a[i+1][j] == '#';
      if(j+1 < w) cnt2 += a[i][j+1] == '#';
      if(cnt1 > 1 || cnt2 > 1) {
        ans = false;
        break;
      }
    }
  }
  cout << (ans ? "Possible" : "Impossible") << endl;
}
