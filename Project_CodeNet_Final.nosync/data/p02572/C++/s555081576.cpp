#pragma region
#ifndef LOCAL_DEBUG
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <assert.h>
#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define revf(i, b, a) for (int i = b; i >= a; i--)
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define revsrt(v) sort(v.rbegin(), v.rend())
#define sp << ' ' <<
#define en << '\n'
#define precision(x) cout << fixed << setprecision(x);
#define fio                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &v) {
  os << "{" << v.first << ", " << v.second << "}" en;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> &v) {
  for (T t : v) os << t << " ";
  os en;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (T t : v) os << t << " ";
  os en;
  return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) is >> v[i];
  return is;
}

#define int long long
#define pii pair<int, int>
#define float long double
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vvpii vector<vpii>
#pragma endregion

int mod = 1e9 + 7;  // 998244353;
const int MAX = 1e5 + 5;

void preprocessing() {}

void solvetestcase() {
  int n;
  cin >> n;
  vi v(n), pre(n + 1, 0);
  cin >> v;
  f(i, 1, n + 1) pre[i] = (pre[i - 1] + v[i - 1]) % mod;
  int ans = 0;

  f(i, 0, n) { ans = (ans + (pre[i] * v[i]) % mod) % mod; }
  cout << ans en;
}

#undef int
int main() {
  fio;
  preprocessing();

  int t = 1;
  // UNCOMMENT FOR TESTCASES	\
	cin >> t;

  f(T, 1, t + 1) {
    // UNCOMMENT FOR CODEJAM,HACKERCUP	\
		cout << "Case #" << T << ": ";
    solvetestcase();
    cout.flush();
  }

  return 0;
};

/*
    AUTHOR:     KUNAL TAWATIA
    EDUCATION:  INDIAN INSTITUTE OF TECHNOLOGY, JODHPUR
*/
