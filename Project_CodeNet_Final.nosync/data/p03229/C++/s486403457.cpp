#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> as(N);
  for (auto i = 0; i < N; i++) {
    cin >> as[i];
  }
  sort(as.begin(), as.end());
  ll l, r;
  l = as[0];
  r = as[N-1];
  ll b, e;
  b = 1;
  e = N-2;
  ll res = abs(l - r);
  while (b <= e) {
    ll tmp = e;
    if (l > r) {
      tmp = l;
      l = r;
      r = tmp;
    }
    if (abs(l - as[e]) < abs(r - as[b])) {
      res += abs(r - as[b]);
      r = as[b];
      b++;
    } else {
      res += abs(l - as[e]);
      l = as[e];
      e--;
    }
  }

  cout << res << endl;

  return 0;
}
