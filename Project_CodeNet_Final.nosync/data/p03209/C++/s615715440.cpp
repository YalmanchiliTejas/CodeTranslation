#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct BoolName : numpunct<char> {
  string t, f;
  BoolName (string t = "Yes", string f = "No") : t(t), f(f) {}
  string do_truename() const {return t;}
  string do_falsename() const {return f;}
};

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
    cout.imbue(locale(cout.getloc(), new BoolName));
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

void set_bool_name(string t, string f) {
  cout.imbue(locale(cout.getloc(), new BoolName(t, f)));
}

template<typename T> bool chmin(T& a, T b) {return a > b ? a = b, true : false;}

template<typename T> bool chmax(T& a, T b) {return a < b ? a = b, true : false;}

template<typename T> void sort(vector<T>& v) {sort(v.begin(), v.end());}

vector<int64_t> dp1, dp2;

int64_t solve(int n, int64_t x) {
  if (x == dp1[n]) return dp2[n];
  if (x == 1) return 0;
  if (x < dp1[n - 1] + 2) return solve(n - 1, x - 1);
  if (x == dp1[n - 1] + 2) return dp2[n - 1] + 1;
  return dp2[n - 1] + solve(n - 1, x - dp1[n - 1] - 2) + 1;
}

int main() {
  int64_t n, x;
  cin >> n >> x;
  dp1.resize(n + 1, 1);
  dp2.resize(n + 1, 1);
  for (int i = 1; i <= n; ++i) dp1[i] = 2 * dp1[i - 1] + 3;
  for (int i = 1; i <= n; ++i) dp2[i] = 2 * dp2[i - 1] + 1;
  cout << solve(n, x) << endl;
}

