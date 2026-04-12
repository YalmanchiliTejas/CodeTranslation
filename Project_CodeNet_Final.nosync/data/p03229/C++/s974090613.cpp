#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif

template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////

const ll inf = 1LL<<60;

int main()
{
  ll n; cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];
  sort(a.rbegin(),a.rend());

  if (n%2) {
    ll r1 = 0;
    for (int i=0; i<n/2-1; i++) {
      r1 += a[i]*2;
    }
    r1 += a[n/2-1] + a[n/2];
    for (int i=n/2+1; i<n; i++) {
      r1 -= a[i]*2;
    }

    ll r2 = 0;
    for (int i=0; i<n/2; i++) {
      r2 += a[i]*2;
    }
    r2 -= a[n/2] + a[n/2+1];
    for (int i=n/2+2; i<n; i++) {
      r2 -= a[i]*2;
    }
    cout << max(r1, r2) << endl;

  } else {
    ll r = 0;
    for (int i=0; i<n/2-1; i++) {
      r += a[i]*2;
    }
    r += a[n/2-1] - a[n/2];
    for (int i=n/2+1; i<n; i++) {
      r -= a[i]*2;
    }
    cout << r << endl;

  }

  return 0;
}
