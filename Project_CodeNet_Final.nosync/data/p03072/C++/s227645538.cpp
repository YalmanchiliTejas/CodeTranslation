
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
  int N;
  int a[30];

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i];

  int ans = 0;
  int mx = 0;
  for (int i = 0; i < N; ++i) {
    if (a[i] >= mx) ++ans;
    chmax(mx, a[i]);
  }

  cout << ans << endl;
  return 0;
}

