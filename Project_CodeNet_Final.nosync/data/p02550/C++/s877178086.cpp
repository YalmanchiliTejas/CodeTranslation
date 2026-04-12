#pragma region
#include <assert.h>
#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &v) {
  return os << v.first << ' ' << v.second << '\n';
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (T t : v) os << t << ' ';
  return os << '\n';
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &t : v) is >> t;
  return is;
}
#pragma endregion

#define int long long

void solvetestcase() {
  int n, x, mod, idx = -1;
  cin >> n >> x >> mod;
  vector<int> v, v1, v2;
  map<int, int> m;
  v.push_back(x);
  m[x] = 1;

  for (int i = 2;; i++) {
    x = (x * x) % mod;
    if (!x) break;
    if (m[x]) {
      idx = m[x];
      break;
    }
    m[x] = i;
    v.push_back(x);
  }
  if (idx == -1) {
    v1 = v;
  } else {
    for (int i = 0; i < idx - 1; i++) {
      v1.push_back(v[i]);
    }
    for (int i = idx - 1; i < v.size(); i++) {
      v2.push_back(v[i]);
    }
  }

  // cout << v1 << v2;
  int ans = 0;
  if (n <= v1.size()) {
    for (int i = 0; i < n; i++) {
      ans += v1[i];
    }
    n = 0;
  } else {
    for (int i = 0; i < v1.size(); i++) {
      ans += v1[i];
    }
    n -= v1.size();
  }
  if (n && v2.size()) {
    int q = n / v2.size();
    int sum = 0;
    for (auto &&num : v2) {
      sum += num;
    }
    ans += sum * q;
    n %= v2.size();

    for (int i = 0; i < n; i++) {
      ans += v2[i];
    }
  }
  cout << ans << endl;
}

#undef int
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;

  for (int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solvetestcase();
    cout.flush();
  }

  return 0;
};

/*
    AUTHOR:     KUNAL TAWATIA
    EDUCATION:  INDIAN INSTITUTE OF TECHNOLOGY, JODHPUR
*/
