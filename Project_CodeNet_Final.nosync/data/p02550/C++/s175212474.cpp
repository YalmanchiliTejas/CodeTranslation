// This template belongs to Juan Carlo Vieri

/*   ____   __
    /  _/  |  |    __         __
 __|  |__  |  |   /_/        |  |
|__    __| |  |   __    ____ |  | __   ___   _  ___
   |  |    |  |  |  |  /  _/ |  |/ /  / _ \ | |/ _/
   |  |    |  |  |  | |  |_  |     \ |  __/ |   /
   |__|    |__|  |__|  \___\ |__|\__\ \___\ |__|
*/

#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;
typedef long double ld;
typedef int_fast64_t intt;
typedef int_fast32_t tmp_m;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define from(x, y, arr) (arr[y] - ((x > 0) ? (arr[x - 1]) : (0)))
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a <  b ? b : a)
#define puts(x) cout << x << endl
#define deb(x) cout << "\033[1;35m" << #x << "\033[0m" << ' ' << x << endl
#define rep(i, cmp1, cmp2) for (tmp_m i = (tmp_m)cmp1; i < (tmp_m)cmp2; ++i)
#define repp(i, cmp1, cmp2) for (tmp_m i = (tmp_m)cmp1; i >= (tmp_m)cmp2; --i)
#define pb push_back
#define st stack
#define pa pair
#define vc vector
#define qu queue
#define pq priority_queue
#define fr first
#define sc second
#define mp map
const ld pi = acos(-1.0);
const intt mod = 1e9 + 7;

struct pr {
  intt x = 0;
  intt y = 0;
  intt dst = 0;
  pr() {}
  pr(intt x, intt y, intt dst) : x(x), y(y), dst(dst) {}
  inline bool operator<(const pr& cmp2) const {
    if (dst != cmp2.dst) return dst < cmp2.dst;
    if (x != cmp2.x) return x < cmp2.x;
    return y < cmp2.y;
  }
  inline bool operator==(const pr& cmp2) const {
    return (cmp2.dst == dst) && (cmp2.x == x) && (cmp2.y == y);
  }
  inline bool operator>(const pr& cmp2) const {
    if (dst != cmp2.dst) return dst > cmp2.dst;
    if (x != cmp2.x) return x > cmp2.x;
    return y > cmp2.y;
  }
};

struct point {
  intt x = 0;
  intt y = 0;
  point() {}
  point(intt x, intt y) : x(x), y(y) {}
  inline bool operator<(const point& cmp2) const {
    if (cmp2.x != x) return cmp2.x < x;
    return cmp2.y < y;
  }
  inline bool operator==(const point& cmp2) const {
    return (cmp2.x == x) && (cmp2.y == y);
  }
  inline bool operator>(const point& cmp2) const {
    if (cmp2.x != x) return cmp2.x > x;
    return cmp2.y > y;
  }
};

namespace std {

template<typename T>
struct hash<vector<T> > {
  size_t operator()(const vector<T>& k) const {
    size_t ret = 0xf3ee477d;
    for (size_t i = 0; i != k.size(); ++ i)
      ret ^= hash(hash(k[i]) + i);
    return ret;
  }
};

template<>
struct hash<pr> {
  size_t operator()(const pr& cmp1) const {
    return (hash<intt>()(cmp1.x)) ^ (hash<intt>()(cmp1.y)) ^
           (hash<intt>()(cmp1.dst));
  }
};

template<>
struct hash<point> {
  size_t operator()(const point& cmp1) const {
    return (hash<intt>()(cmp1.x)) ^ (hash<intt>()(cmp1.y));
  }
};
}

inline bool spoint(const point& cmp1, const point& cmp2) {
  // swap(cmp1, cmp2);
  if (cmp1.x != cmp2.x) return cmp1.x < cmp2.x;
  return cmp1.y < cmp2.y;
}

inline bool spr(const pr& cmp1, const pr& cmp2) {
  // swap(cmp1, cmp2);
  if (cmp1.dst != cmp2.dst) return cmp1.dst < cmp2.dst;
  if (cmp1.x != cmp2.x) return cmp1.x < cmp2.x;
  return cmp1.y < cmp2.y;
}

void sub() {

}

void solve() {
  // intt t; cin >> t;
  // while (t--) sub();
  intt n, x, m;
  cin >> n >> x >> m;
  unordered_map<intt, intt> pos;
  intt cur = x;
  intt curPos = 0;
  vc<intt> ans;
  while(1){
    if(pos.count(cur) != 0 || ans.size() == n)break;
    pos[cur] = curPos;
    ans.pb(cur);
    ++curPos;
    cur = cur * cur % m;
  }
  if(ans.size() == n){
    intt res = 0;
    rep(i, 0, n){
      res += ans[i];
    }
    cout << res << endl;
    return;
  }
  // rep(i, 0, ans.size()){
  //   cout << ans[i] << ' ';
  // }
  intt res = 0;
  rep(i, 0, pos[cur]){
    res += ans[i];
  }
  intt sum = 0;
  rep(i, pos[cur], ans.size()){
    sum += ans[i];
  }
  // deb(sum);
  // deb(res);
  intt len = curPos - pos[cur];
  res += sum * ((n - pos[cur]) / len);
  // deb((n - pos[cur]) / len);
  rep(i, pos[cur], pos[cur] + (n - pos[cur]) % len){
    res += ans[i];
  }
  cout << res << endl;
}

void init() {
  // remove if interactive
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(0));
  // memset(dp, -1, sizeof dp);
}

int main() {
  init();
  solve();
  return 0;
}
