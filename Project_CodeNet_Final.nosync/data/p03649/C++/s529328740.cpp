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

void solve(long long N, vector<long long> a) {
  ll ans = 0;
  while (true) {
    ll c = 0;
    REP(i, N) {
      ll b = a[i] / N;
      a[i] %= N;
      a[i] -= b;
      c += b;
    }
    REP(i, N) a[i] += c;
    ans += c;
    if (!c)
      break;
  }

  // 123456789486
  // 123456789492

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  long long N;
  cin >> N;
  vector<long long> a(N - 1 + 1);
  for (int i = 0; i <= N - 1; i++) {
    cin >> a[i];
  }
  solve(N, a);
  return 0;
}
