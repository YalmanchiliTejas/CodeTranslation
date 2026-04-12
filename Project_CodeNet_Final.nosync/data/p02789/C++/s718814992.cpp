#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i, n) for(int i=0;i<(int)(n);++i)
template <typename T> lint gcd(T a, T b) {return b?gcd(b, a%b):a;}
template <typename T> lint lcm(T a, T b) {return a * b / gcd(a, b);};
template <typename T> inline void chmin(T &a, const T& b){if(a>b)a=b;}
template <typename T> inline void chmax(T &a, const T& b){if(a<b)a=b;}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == m) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}
