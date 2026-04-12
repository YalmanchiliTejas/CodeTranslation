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

vector<int> e[100005];
bool leaf[100005];
bool dfs(int u, int p)
{
  bool use = false;
  for (auto s : e[u])
  {
    if (s != p)
    {
      bool pained = dfs(s, u);
      if (!pained && !use)
      {
        use = true;
      }
      else if (!pained && use)
      {
        cout << "First" << endl;
        exit(0);
      }
    }
  }
  return use;
}
void solve(long long N, std::vector<long long> a, std::vector<long long> b)
{
  rep(i, N - 1) a[i]--, b[i]--;
  rep(i, N - 1) e[a[i]].push_back(b[i]), e[b[i]].push_back(a[i]);
  cout << (dfs(0, -1) ? "Second"
                      : "First")
       << endl;
}
signed main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N - 1);
  std::vector<long long> b(N - 1);
  for (int i = 0; i < N - 1; i++)
  {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
  }
  solve(N, std::move(a), std::move(b));
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
