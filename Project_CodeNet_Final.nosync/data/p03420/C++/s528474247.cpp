// https://github.com/yuchiki/contest

#include <bits/stdc++.h>
using namespace std;

#ifdef YUCHIKIDEBUG
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                         \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
       << " " << __FUNCTION__ << endl;
#else
#define dump(x) ;
#define debug(x) ;
#endif  // YUCHIKIDEBUG

#define int long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define vvi vector<vi>

#define toupper(x) (char)toupper(x)
#define tolower(x) (char)tolower(x)

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _repinc(i, n) _repiinc(i, 0, n)
#define _repiinc(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define repinc(...) _overload3(__VA_ARGS__, _repiinc, _repinc, )(__VA_ARGS__)
#define _repr(i, n) repir(i, n, 0)
#define repir(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define repr(...) _overload3(__VA_ARGS__, repir, _repr, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define REV(x) reverse(all(x))
#define SORT(x) sort(all(x))

template <class ARG>
inline void put(ARG x) {
  cout << x << endl;
}

inline int sqr(int x) { return x * x; }
inline vi divisors(int x) {
  vi divs = {1};
  rep(i, 2, x) {
    if (x % i == 0) divs.push_back(i);
  }
  return divs;
}
inline vector<pair<int, int>> divpairs(int x) {
  vector<pair<int, int>> divs;
  rep(i, 1, x + 1) {
    if (x % i == 0) divs.push_back(make_pair(i, x / i));
  }
  return divs;
}

/// return the first i in [lb .. ub) where pred(i) holds.
/// if none of the above i satisfies pred, ub is returned.
template <class Predicate>
inline int bin_search(
    int lb, int ub,
    Predicate pred) {  // return the first i where pred(i) holds.
  while (lb + 1 < ub) {
    int mid = (lb + ub) / 2;
    if (pred(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  return pred(lb) ? lb : ub;
}

inline vector<int> to_digits(int i) {
  vector<int> digits;
  while (i >= 10) {
    digits.push_back(i % 10);
    i /= 10;
  }
  digits.push_back(i);

  reverse(digits.begin(), digits.end());
  return digits;
}

template <class T>
using matrix = vector<vector<T>>;

template <class T>
matrix<T> make_matrix(int R, int C, T value) {
  return matrix<T>(R, vector<T>(C, value));
}

template <class T, class F>
inline vector<T> operator>>(vector<T> &v, F f) {
  return f(v);
}
template <class T, class S, class F>
inline vector<S> map(F f, const vector<T> &v) {
  vector<S> res(v.size());
  transform(v.begin(), v.end(), res.begin, f);
  return res;
}

template <class T, class F>
inline vector<T> filter(F f, const vector<T> &v) {
  vector<T> res;
  copy_if(v.begin(), v.end(), back_inserter(res), f);
  return res;
}

template <class T, class S, class F>
inline S fold(F f, S initial, const vector<T> &v) {
  return accumulate(v.begin(), v.end(), initial, f);
}

const long long INF = LLONG_MAX / 2;
const double eps    = numeric_limits<double>::min() * 10;

using address = pair<int, int>;

inline int pow(int i, int n) { return (int)pow(i + eps, n); }

template <class T>
inline T &at(matrix<T> &m, address addr) {
  return m[addr.first][addr.second];
}
template <class T>
inline pair<T, T> operator+(pair<T, T> t1, pair<T, T> t2) {
  return make_pair(t1.first + t2.first, t1.second + t2.second);
}

template <class T>
inline pair<T, T> operator-(pair<T, T> t1, pair<T, T> t2) {
  return make_pair(t1.first - t2.first, t1.second - t2.second);
}

template <class T>
inline pair<T, T> operator*(pair<T, T> t1, pair<T, T> t2) {
  return make_pair(t1.first * t2.first, t1.second * t2.second);
}

template <class T>
inline pair<T, T> operator*(T t, pair<T, T> t2) {
  return make_pair(t + t2.first, t + t2.second);
}

void sayyes() { put("Yes"); }
void sayno() { put("No"); }

void exityes() {
  sayyes();
  exit(0);
};

void exitno() {
  sayno();
  exit(0);
}

int readint() {
  int i;
  cin >> i;
  return i;
}
string readstr() {
  string s;
  cin >> s;
  return s;
}

vector<int> eratosthenes(int n) {
  vector<bool> v(n + 1, true);
  rep(i, 2, sqrt(n + 1) + 5) {
    if (!v[i]) continue;
    repinc(j, i + 1, n) v[j] = v[j] & (j % i > 0);
  }

  vector<int> ans;
  ans.reserve(sqrt(n + 1) + 5);
  repinc(i, 2, n) if (v[i]) ans.pb(i);
  return ans;
}

/*********************************************************************/
const long long MAXN = 1e6;
const long long MOD  = 1e9 + 7;
/*********************************************************************/

int test(int N, int K) {
  int sum = 0;
  rep(a, 1, N + 1) {
    rep(b, 1, N + 1) {
      if (K <= a % b) {
        sum++;
      }
    }
  }
  return sum;
}

int run(int N, int K) {
  if (K == 0) {
    return N * N;
  }
  int sum = 0;
  rep(b, K + 1, N + 1) {
    int p = N / b;
    sum += (b - K) * p + max(0ll, (N - (b * p + K) + 1));
  }
  return sum;
}

signed main() {
  int N, K;
  cin >> N >> K;

  cout << run(N, K) << endl;

  return 0;
}
