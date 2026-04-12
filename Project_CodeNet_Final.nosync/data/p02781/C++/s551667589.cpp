#include <bits/stdc++.h>
using namespace std;

#define df(b, e) ((b) > (e))
#define fore(i, b, e) for(auto i = (b) - df(b, e); i != e - df(b, e); i += 1 - 2 * df(b, e))
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define pb push_back

typedef long long lli;
typedef long double ld;
typedef pair<int, int> ii;

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
  ~debug() { cout << endl; }

  template <class T>
  typename enable_if<sizeof dud<T>(0) != 1, debug &>::type operator << (T i) {
    cout << boolalpha << i;
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

const int N = 101;
const int K = 4;

lli mem[N][K][2];
short done[N][K][2], timer = 0;
string num;
int k;

lli dp(int i, int cnt, bool small) {
  if (cnt > k)  
    return 0LL;
  if (i == sz(num))
    return cnt == k;
  lli &ans = mem[i][cnt][small];
  if (done[i][cnt][small] != timer) {
    done[i][cnt][small] = timer;
    ans = 0;
    int lo = 0, hi = small ? 9: num[i] - '0';
    fore (x, lo, hi + 1) 
      ans += dp(i + 1, cnt + (x != 0), small | (x < hi));
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
