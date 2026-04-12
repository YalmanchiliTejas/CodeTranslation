#include <cstdio>
#include <set>

using namespace std;

#define int long long
#define dotimes(i, n) for (int i = 0, i##max__ = (n); i < i##max__; i++)

int rint() {
  int x;
  scanf("%lld", &x);
  return x;
}

void wint(int x) {
  printf("%lld\n", x);
}

template<typename T>
int size(T const& container) {
  return static_cast<int>(container.size());
}

template <typename T>
bool maxs(T& a, T const& b) {
  return a < b ? a = b, true : false;
}

template <typename T>
bool mins(T& a, T const& b) {
  return a > b ? a = b, true : false;
}

signed main() {
  const int N = rint();
  multiset<int> s;
  dotimes(i, N) {
    int A = rint();
    auto it = s.lower_bound(A);
    if (it != s.begin())
      s.erase(--it);
    s.insert(A);
  }
  wint(::size(s));
  return 0;
}
