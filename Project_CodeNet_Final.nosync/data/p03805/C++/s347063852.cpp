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

ll N, M;
bool E[10][10];
ll ans;
unsigned char endf;

void dfs(int n, unsigned char flag) {
  if (flag == endf) {
    ans++;
    return;
  }

  REP(i, N) if (E[n][i]) {
    if (flag & 0x01 << i)
      continue;
    unsigned char buf = flag + (0x01 << i);
    dfs(i, buf);
  }
}

void solve(long long NN, long long MM, vector<long long> a,
           vector<long long> b) {
  N = NN;
  M = MM;

  REP(i, N) { endf += 0x01 << i; }
  // cout << (int)end << endl;

  REP(i, M)
  E[a[i]][b[i]] = E[b[i]][a[i]] = true;

  dfs(0, 1);

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  long long M;
  long long N;
  cin >> N;
  cin >> M;
  vector<long long> a(M - 1 + 1);
  vector<long long> b(M - 1 + 1);
  for (int i = 0; i <= M - 1; i++) {
    cin >> a[i];
    a[i]--;
    cin >> b[i];
    b[i]--;
  }
  solve(N, M, a, b);
  return 0;
}
