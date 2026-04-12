#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << '\n'
#define debugMatrix(x, h, w)                                         \
  cerr << __LINE__ << ": " << #x << " =\n";                          \
  for (long long hoge = 0; (hoge) < (long long)(h); ++(hoge)) {      \
    cerr << ((hoge ? " {" : "{{"));                                  \
    for (long long fuga = 0; (fuga) < (long long)(w); ++(fuga))      \
      cerr << ((fuga ? ", " : "")) << x[hoge][fuga];                 \
    cerr << "}" << (hoge + 1 == (long long)(h) ? "}" : ",") << '\n'; \
  }
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#define debugMatrix(x, h, w) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long N, X, M;
  cin >> N >> X >> M;
  map<long long, pair<long long, long long>> mp;
  int cnt = 0;
  long long A = X % M;
  long long sum = X - A;
  while (1) {
    if (A == 0) {
      cout << sum << '\n';
      return 0;
    }
    if (cnt == N) {
      cout << sum << '\n';
      return 0;
    }
    if (mp.count(A)) {
      break;
    }
    mp[A] = make_pair(cnt, sum);
    sum += A;
    cnt++;
    A = A * A % M;
  }
  int prev, psum;
  tie(prev, psum) = mp[A];
  N -= prev;
  cnt -= prev;
  long long ans = N / cnt * (sum - psum) + psum;
  N %= cnt;
  for (int i = 0; i < N; i++) {
    ans += A;
    A = A * A % M;
  }
  cout << ans << '\n';
  return 0;
}
