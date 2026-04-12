#pragma region

#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _rep3(i, begin, end) for (register int i = (begin), i##_end = (end); i < i##_end; i++)
#define _irep3(i, begin, end) for (register int i = (end)-1, i##_begin = (begin); i >= i##_begin; i--)
#define _rep2(i, n) _rep3(i, 0, n)
#define _irep2(i, n) _irep3(i, 0, n)
#define _overload3(_1, _2, _3, name, ...) name
#define rep(...) _overload3(__VA_ARGS__, _rep3, _rep2, )(__VA_ARGS__)
#define irep(...) _overload3(__VA_ARGS__, _irep3, _irep2, )(__VA_ARGS__)
#define out(x) cout << (x) << '\n';
#define debug(x) cerr << #x << " = " << (x) << " (line: " << __LINE__ << ") " << endl;
typedef long long ll;

void init() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "vec[ ";
  rep(i, vec.size()) i == 0 ? os << vec[i] : os << ", " << vec[i];
  os << " ]";
  return os;
}

#pragma endregion

#define MOD 1000000007
#define INF 2147483647

int main() {
  init();

  int N, M;
  cin >> N>> M;

  out(N == M ? "Yes" : "No");
}
