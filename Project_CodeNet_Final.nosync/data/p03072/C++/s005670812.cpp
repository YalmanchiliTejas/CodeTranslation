#include <bits/stdc++.h>
using namespace std;

// templates -------------------------------------

#define ULL unsigned long long
#define LL long long
#define LLD long long double
#define REP(i, n) for(LL i = 0; i < n; i++)
#define INV_REP(i, n) for(LL i = n; 0 <= i; i--)

LL combination(LL n, LL m)
{
  LL nume = 1;
  REP(i, m) nume *= (n-i);
  LL demo = 1;
  for(int i = 1; i <= m; i++) demo *= i;
  return nume / demo;
}

template<class T>
class UnionFind
{
private:
  vector<T> par;
  vector<T> rank;
  vector<T> size;

public:
  UnionFind(T N) :
    par(N, T()), rank(N, T()), size(N, T())
  {
    REP(i, N)
    {
      par[i] = i;
      rank[i] = 0;
      size[i] = 1;
    }
  }

  inline T root(T x)
  {
    return par[x] == x ? x : par[x] = root(par[x]);
  }

  inline bool same(T x, T y)
  {
    return root(x) == root(y);
  }

  inline T getSize(T x)
  {
    return size[root(x)];
  }

  void unite(T x, T y)
  {
    T r1 = root(x);
    T r2 = root(y);
    if(r1 == r2) return;

    if(rank[r1] < rank[r2]) swap(r1, r2);
    if(rank[r1] == rank[r2]) rank[r1]++;
    par[r2] = r1;
    size[r1] += size[r2];
  }
};

// --------------------------------------

int n;
vector<int> h;

void input()
{
  cin >> n;
  h.resize(n);
  REP(i, n)
  {
    cin >> h[i];
  }
}

void solve()
{
  int cnt = 1;
  int maxH = h[0];
  for(int i = 1; i < n; i++)
  {
    maxH = max(h[i], maxH);
    if(maxH == h[i]) cnt++;
  }
  cout << cnt << endl;
}

int main()
{
  input();
  solve();
  return 0;
}