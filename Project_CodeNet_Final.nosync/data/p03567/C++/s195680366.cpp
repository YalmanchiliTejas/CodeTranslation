#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
typedef long long int ll;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EREP(i, n) for (int i = (n - 1); i >= 0; --i)
#define D(n, retu)                                                             \
  REP(i, n) { cin >> retu[i]; }
#define mod 1000000007
#define INF 93193111451418101
#define MIN -933111451418101
//#define INF 931931114518101
using namespace std;
typedef pair<ll, ll> P;
template <typename T> void fill_all(T &arr, const T &v) { arr = v; }
template <typename T, typename ARR> void fill_all(ARR &arr, const T &v) {
  for (auto &i : arr) {
    fill_all(i, v);
  }
}
#define yo 100001
//------------------変数-----------------------//
ll n, maxmove = 0, movesize;

//-------------------関数----------------------//

int main() {
  string s;
  cin >> s;
  REP(i, s.size() - 1) {
    if (s[i] == 'A' && s[i + 1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
