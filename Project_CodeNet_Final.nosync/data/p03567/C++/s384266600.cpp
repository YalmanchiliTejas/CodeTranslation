#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T> lint gcd(T a, T b) {return b?gcd(b, a%b):a;}
template <typename T> lint lcm(T a, T b) {return a * b / gcd(a, b);};
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false; }
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b;return true;}return false; }

struct IoSetup{
    IoSetup(){
      ios::sync_with_stdio(false);
      cin.tie(0);
      cout << fixed << setprecision(20);
      cerr << fixed << setprecision(20);
    }
} IoSetup;

int main() {
  string s; cin >> s;
  for (int i = 0; i < (int) s.size()-1; ++i) {
    if (s[i] == 'A' && s[i+1] == 'C') {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}
