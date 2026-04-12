#include "bits/stdc++.h"
#define LF '\n'
#define ALL(x) x.begin(), x.end()
#define iostreamBooster() { cin.tie(nullptr); ios_base::sync_with_stdio(false); }
using namespace std;
typedef int64_t i64;
typedef pair<int,int> pii;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF = 0x3f3f3f3f;
template<class Itr> void dump(Itr begin, Itr end) { for (;begin != end; ++begin) clog << *begin << LF; }

int N;
i64 a[3005];
i64 dp[3005][3005];

i64 slv(int left, int right)
{
  if (left > right) { return 0; }
  i64 &ret = dp[left][right];
  if(~ret) { return ret; }

  bool isTaro = ((left + (N-1 - right)) % 2 == 0);

  if (isTaro) {
    ret = max(
        slv(left+1, right) + a[left],
        slv(left, right-1) + a[right]
    );
  }
  else {
    ret = min(
        slv(left+1, right) - a[left],
        slv(left, right-1) - a[right]
    );
  }
  return ret;
}

signed main()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << slv(0, N-1) << endl;

  return 0;
}

