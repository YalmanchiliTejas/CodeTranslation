#include <algorithm>
#include <bitset>
#include <cassert>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define POW(n) ((n) * (n))
#define ALL(a) (a).begin(), (a).end()
#define dump(v) (cerr << #v << ": " << v << endl)
#define cerr                                                                   \
  if (true)                                                                    \
  cerr

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<unsigned long long> vull;

// ll n = to_T<ll>("114514")
template <class T> T to_T(const string &s) {
  istringstream is(s);
  T res;
  is >> res;
  return res;
}
template <class T> string to_s(const T &a) {
  ostringstream os;
  os << a;
  return os.str();
}

void solve(long long n, vector<long long> a) {
  // 1 2 3 4
  // 3 2 4 1

  // 1 2 3
  // 2 3 1
  deque<ll> f, b;
  for (int i = n - 1; i >= 1; i -= 2) {
    f.push_back(a[i]);
    b.push_front(a[i - 1]);
  }

  if (n % 2 != 0)
    b.push_front(a[0]);

  REP(i, f.size()) cout << f[i] << " ";
  REP(i, b.size() - 1) cout << b[i] << " ";

  cout << b.back() << endl;
}

int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> a(n - 1 + 1);
  for (int i = 0; i <= n - 1; i++) {
    cin >> a[i];
  }
  solve(n, a);
  return 0;
}
