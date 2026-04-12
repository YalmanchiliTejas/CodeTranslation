//Daniel Grzegorzewski
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

const int N = 1<<18;

int n, m, dp[N];
VII prz[N];

class treePM
{
  public:
    int w[2*N], W[2*N];

    void init()
    {
      for (int i = 0; i < 2*N; ++i)
        w[i] = W[i] = 0;
    }

    void insert(int a, int b, int v)
    {
      _insert(a, b, v, 0, N-1, 1);
    }

    int query(int a, int b)
    {
      return _query(a, b, 0, N-1, 1, 0);
    }

    void _insert(int a, int b, int v, int beg, int end, int k)
    {
      if (b < beg || a > end)
        return;
      if (a <= beg && end <= b) {
        w[k] += v;
        W[k] += v;
        return;
      }
      _insert(a, b, v, beg, (beg+end)/2, 2*k);
      _insert(a, b, v, (beg+end)/2+1, end, 2*k+1);
      W[k] = w[k] + max(W[2*k], W[2*k+1]);
    }

    int _query(int a, int b, int beg, int end, int k, int war)
    {
      if (b < beg || a > end)
        return 0;
      if (a <= beg && end <= b)
        return war + W[k];
      return max(_query(a, b, beg, (beg+end)/2, 2*k, war+w[k]), _query(a, b, (beg+end)/2+1, end, 2*k+1, war+w[k]));
    }
} drz;

signed main() {
  init_ios();
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int l, r, a;
    cin >> l >> r >> a;
    prz[r].PB({l, a});
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = drz.query(0, i-1);
    drz.insert(i, i, dp[i]);
    for (const auto& el: prz[i])
      drz.insert(el.ST, i, el.ND);
  }
  cout<<drz.query(1, n)<<"\n";
}