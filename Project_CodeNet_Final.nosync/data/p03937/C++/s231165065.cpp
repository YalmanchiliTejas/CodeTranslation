#include "bits/stdc++.h"
#define ALL(x) x.begin(), x.end()
#define LEN(x) (int)x.size()
#define iostreamBooster() do{ cin.tie(nullptr); ios_base::sync_with_stdio(false); }while(0)
using namespace std;
typedef int64_t i64;
typedef pair<int,int> pii;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF = 0x3f3f3f3f;

signed main()
{
  int h, w;
  char s[11];

  cin >> h >> w;
  int cnt = 0;
  for (int i = 0; i < h; ++i) {
    cin >> s;
    cnt += count(s, s+w, '#');
  }

  puts((cnt == h+w-1) ? "Possible" : "Impossible");


  return 0;
}

