#include <bits/stdc++.h>
using namespace std;

#define df(b, e) ((b) > (e))
#define fore(i, b, e) for(auto i = (b) - df(b, e); i != e - df(b, e); i += 1 - 2 * df(b, e))
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define pb push_back
#define em emplace_back

typedef long long lli;
typedef long double ld;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
struct rge { T b, e; };

template <class T>
rge<T> range(T i, T j) {
  return rge<T>{i, j};
}

template <class T> auto dud(T *x) -> decltype(cerr << *x, 0);
template <class T> char dud(...);

struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }

  template <class T>
  typename enable_if<sizeof dud<T>(0) != 1, debug &>::type operator << (T i) {
    cerr << boolalpha << i;
    return *this;
  }

  template <class T>
  typename enable_if<sizeof dud<T>(0) == 1, debug &>::type operator << (T i) {
    return *this << range(begin(i), end(i));
  }

  template <class A, class B>
  debug & operator << (pair<A, B> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }

  template <class T>
  debug & operator << (rge<T> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
      *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
#else
  template <class T> 
  debug & operator << (const T&) {
    return *this; 
  }
#endif
};

#define deb(...) " " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " "

string num;
int k;
lli mem[105][4][2];
int done[105][4][2], timer = 0;
#define state [i][k][small]
int dp(int i, int k, bool small) {
  if (i == sz(num))
    return k == ::k;
  lli &ans = mem state;
  if (done state != timer) {
    done state = timer;
    ans = 0LL;
    int hi = small ? 9 : num[i] - '0';
    fore (d, 0, hi + 1) {
      int nk = (k + (d != 0));
      if (nk > ::k) continue;
      ans += dp(i + 1, nk, small | (d < hi));
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (cin >> num >> k) {
    ++timer;
    cout << dp(0, 0, 0) << '\n';
  }
  return 0;
}
