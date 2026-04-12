#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
// utility
#define all(i) (i).begin(), (i).end()
#define rep(i, n) for(int i=0;i<int(n);++i)
#define rrep(i, n) for(int i=int(n)-1;i>=0;--i)
#define repv(ele, vec) for (auto &ele : vec)
#define in(a, x, b) (a<=x && x<b)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int MOD = 1000000007;

using namespace std;


signed main() {
  int H, W;
  cin >> H >> W;
  vector<string> vec(H);
  rep(i, H) cin >> vec[i];

  int h[H], w[W];
  rep(i, H) h[i] = 0;
  rep(i, W) w[i] = 0;
  rep(i, H){
    int flag = 0;
    rep(j, W) if(vec[i][j] == '#') flag = 1;
    if(flag) h[i] = 1;
  }
  rep(j, W){
    int flag = 0;
    rep(i, H) if(vec[i][j] == '#') flag = 1;
    if(flag) w[j] = 1;
  }
  rep(i, H){
    rep(j, W) if(h[i] && w[j]) cout << vec[i][j];
    if(h[i]) cout << endl;
  }

  return 0;
}