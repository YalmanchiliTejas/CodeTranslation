#include <cassert>
#include <algorithm>
#include <cctype>
#include <complex>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <typeinfo>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REPD(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define PB(e) push_back(e)
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define MP(a, b) make_pair(a, b)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;

template <typename S, typename T> ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  REP(i, v.size()){
    if (i > 0) out << ", ";
    out << v[i];
  }
  out << "]";
  return out;
}

const int MAX = 110;
const ll mod = 1000 * 1000 * 1000 + 7;
int N;
vector<ll> H;
ll memo1[MAX];
ll memo2[MAX][MAX];
ll memo3[MAX][MAX];
ll memo4[MAX][MAX];

ll modpow(ll n, ll p) {
  ll res = 1;
  while (p > 0) {
    if (p & 1) {
      res *= n;
      res %= mod;
    }
    p >>= 1;
    n = n * n % mod;
  }
  return res;
}

pair<ll, ll> rec(int l, int r, int h) {
  assert(r - l > 0);
  if (r - l == 1) {
    const ll c = modpow(2, H[l] - h);
    return {c, c};
  }

  int min_h = *min_element(H.begin() + l, H.begin() + r);
  assert(min_h > h);

  vector<pair<int, int>> v;
  int i = l;
  while (i < r) {
    int j = i;
    while (j < r && (H[i] == min_h) == (H[j] == min_h)) j++;
    v.push_back({i, j});
    i = j;
  }
  
  int w = count(H.begin() + l, H.begin() + r, min_h);
  int x = min_h;

  ll prod1 = 1;
  ll prod2 = 1;
  for (auto& p : v) {
    int x = p.first, y = p.second;
    if (H[x] != min_h) {
      auto g = rec(x, y, min_h);
      prod1 *= g.first;
      prod1 %= mod;
      prod2 *= g.second + g.first;
      prod2 %= mod;
    }
  }
  ll res1 = modpow(2, min_h - h) * prod1 % mod;
  ll res2 = (modpow(2, w) * prod2 + (modpow(2, min_h - h) - 2) * prod1) % mod;
  return {res1, res2 % mod};
}

int main(int argc, char *argv[])
{
  cin >> N;
  H.resize(N);
  REP(i, N) cin >> H[i];
  cout << rec(0, N, 0).second << endl;
  return 0;
}
