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
#include <set>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define POW(n) ((n) * (n))
#define ALL(a) (a).begin(), (a).end()

using namespace std;

namespace Dump {
#define dump(...) Dump::print(#__VA_ARGS__, __VA_ARGS__)
static std::vector<string> dumpKey;
static string dumpKeyBuf;

void print() { cerr << endl; }
template <class Head, class... Tail> void print(Head &&head, Tail &&... tail) {
  if (dumpKey.empty()) {
    dumpKeyBuf = head;
    dumpKeyBuf.erase(std::remove_if(dumpKeyBuf.begin(), dumpKeyBuf.end(),
                                    [](char c) { return c == ' '; }),
                     dumpKeyBuf.end());

    std::istringstream stream(dumpKeyBuf);
    string field;
    while (std::getline(stream, field, ','))
      dumpKey.push_back(field);

    reverse(dumpKey.begin(), dumpKey.end());
  } else {
    cerr << dumpKey.back() << ":" << head << "  ";
    dumpKey.pop_back();
  }
  Dump::print(std::move(tail)...);
}
}

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef pair<int, int> pii; // p.first p.second

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

void solve(long long X, long long Y, long long Z) {
  ll ans = 0;
  REP(i, X + 1) {
    ll buf = i * Y + (i + 1) * Z;
    if (buf > X)
      break;
    ans = i;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  long long Y;
  long long Z;
  long long X;
  cin >> X;
  cin >> Y;
  cin >> Z;
  solve(X, Y, Z);
  return 0;
}
