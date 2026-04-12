#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
template<typename T>
ostream& operator<<(ostream& os, vector<T> const& v) {
  os << "[";
  for (size_t i = 0; i < v.size(); i++) {
    os << (i == 0 ? "" : ",") << v[i];
  }
  return os << "]";
}
template<typename S, typename T>
ostream& operator<<(ostream& os, pair<S, T> const& v) {
  return os << "<" << v.first << "," << v.second << ">";
}

typedef int64_t I;
typedef vector<I> vI;
typedef vector<vI> vvI;
typedef pair<int, int> II;
typedef vector<II> vII;

const I M = 998244353;
I inv(I a, I b) {
  I x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b != 0) {
    I q = a / b, nb = a % b;
    a = b;
    b = nb;
    I nx1 = x0 - q * x1, ny1 = y0 - q * y1;
    x0 = x1;
    x1 = nx1;
    y0 = y1;
    y1 = ny1;
  }
  while (x0 < 0) {
    x0 += M;
  }
  return x0;
}
 

I solve(vI const& a, I n, I s) {
  I r = 0;
  vI counts(s + 1, 0);
  counts[0] = 0;
  for (size_t i = 0; i < a.size(); i++) {
    counts[0]++;
    vI newcounts(counts);
    for (I j = 0; j < s; j++) {
      if (j + a[i] <= s) {
        newcounts[j + a[i]] = (newcounts[j + a[i]] + counts[j]) % M;
      }
    }
    //cerr << newcounts << "," << counts << endl;
    counts.swap(newcounts);
    r = (r + counts[s]) % M;
  }
  return r % M;
}

int main() {
  I n, s; cin >> n >> s;
  vI a(n);
  for (size_t i = 0; i < a.size(); i++) cin >> a[i];
  cout << solve(a, n, s) << endl;
}
