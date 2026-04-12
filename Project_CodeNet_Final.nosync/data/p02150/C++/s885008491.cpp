#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbg2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define dbgB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

template<typename T>
void print1(T begin, T end) {
  while (begin != end) {
    cout << (*begin) << " ";
    *begin++;
  }
  cout << endl;
}

template<typename T>
void print2(T Array, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << " " << Array[i][j];
    }
    cout << endl;
  }
}

void print() { std::cerr << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cerr << head << " ";
  print(std::forward<Tail>(tail)...);
}

template<class T>
void Add(T &a, const T &b, const T &mod=1000000007) {
  int val = ((a % mod) + (b % mod)) % mod;
  if (val < 0) { val += mod; }
  a = val;
}

template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

// ------------------------------------------------------------------------------------------

const int mod = 1e9 + 7;

int a, b, x;

signed main() {
  cin >> a >> b >> x;

  if (x < a) {
    cout << x % mod << endl;
    return 0;
  }

  int cnt = (x - a) / (a - b);
  int ans = ((cnt%mod) * (a%mod))%mod;
  x -= cnt * (a - b);

  while (x >= a) {
    x -= a;
    x += b;
    ans += a;
    ans %= mod;
  }

  ans += x;
  ans %= mod;

  cout << ans << endl;

  return 0;
}
