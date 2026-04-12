#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
#define vall(x) (x).begin(), (x).end()
using namespace std;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
template <class T1, class T2>
void vadd(vector<T1> &v, T2 x);

#define int long long int
map<lli, lli> dp[200005][2];
// dp[i][j][k] := iまでにk回休んでjが1なら直前休んだ
void set_v(lli i, lli j, lli k, lli v)
{
  // cout << i << " " << j << " " << k << " <- " << v << endl;

  if (dp[i][j].find(k) != dp[i][j].end())
    chmax(dp[i][j][k], v);
  else
  {
    dp[i][j][k] = v;
  }
}
void solve(long long N, std::vector<long long> A)
{
  dp[0][0][0] = 0;
  dp[0][1][0] = 0;

  rep(i, N) rep(j, 2)
  {
    for (auto s : dp[i][j])
    {
      if (s.first > (i + 8) / 2 || s.first < (i - 8) / 2)
      {
        continue;
      }
      if (j)
      {
        set_v(i + 1, 1, s.first + 1, s.second);
        set_v(i + 1, 0, s.first, s.second + A[i]);
      }
      else
      {
        set_v(i + 1, 1, s.first + 1, s.second);
      }
    }
  }
  cout << max(dp[N][1][N - N / 2], dp[N][0][N - N / 2]) << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}

template <class T1, class T2>
void vadd(vector<T1> &v, T2 x)
{
  for (auto &s : v)
    s += T2(x);
}
