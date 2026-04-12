#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T> ostream& operator << (ostream& os, vector<T> v) {
  for (auto& i : v) os << i << " "; return os; 
}
template<typename T> istream& operator >> (istream& is, vector<T>& v) {
  for (auto& i : v) is >> i; return is;
}
template<typename K, typename V> ostream& operator << (ostream& os, unordered_map<K, V> m) {
  for (auto& i : m) os << i.first << ":" << i.second << endl; return os;
}
template<typename T> inline bool chmin(T& x, T y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template<typename T> inline bool chmax(T& x, T y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
  for (int len=1; len<=n; len++) {
    for (int i=0; i+len<=n; i++) {
      int j = i + len;
      if ((n-len) % 2 == 0) {
        dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
      } else {
        dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
      }
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}
