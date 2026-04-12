#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>

using namespace std;

const int mod = 1'000'000'007;
vector<int> h;

struct dp_t {
  long long alternating;
  long long other;
};

long long power(long long n, long long k, long long m) {
  if (m < 0) m = -m;
  n %= m;
  long long ret = 1;
  while (k) {
    if (k & 1) ret = (ret * n % m);
    n = (n * n % m);
    k >>= 1;
  }
  return ret;
}


dp_t solve(int L, int R, int base) {
  dp_t res = { 0, 0 };
  if (L == R) {
    int count = h[L] - base;
    res.alternating = power(2, count - 1, mod);
    return res;
  }
  int splitbase = *min_element(h.begin() + L, h.begin() + R + 1);
  int last = L;
  long long alternate = 1;
  long long all = 1;
  for (int i = L; i <= R; i++) {
    if (h[i] == splitbase) {
      last = i + 1;
      all *= 2;
      all %= mod;
    }
    else if (i + 1 > R || h[i + 1] == splitbase) {
      if (last == i) {
        all *= power(2, h[i] - splitbase, mod);
        all *= 2;
        all %= mod;
        alternate *= power(2, h[i] - splitbase, mod);
        alternate %= mod;
      }
      else {
        dp_t sub = solve(last, i, splitbase);
        alternate *= sub.alternating * 2;
        alternate %= mod;
        all *= (sub.alternating * 4 + sub.other) % mod;
        all %= mod;
      }
    }
  }

  res.other = (all - alternate * 2) % mod;
  alternate *= power(2, splitbase - base - 1, mod);
  alternate %= mod;
  res.alternating = alternate;
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  h.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  dp_t ans = solve(0, n-1, 0);
  long long val = (ans.alternating * 2 + ans.other) % mod;
  val += mod;
  val %= mod;
  printf("%lld\n", val);
  return 0;
}
