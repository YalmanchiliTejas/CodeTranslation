#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#define rep(i, n) for(int i=0;i<(int)(n);++i)
template <typename T> ll gcd(T a, T b) {return b?gcd(b, a%b):a;}
template <typename T> ll lcm(T a, T b) {return a * b / gcd(a, b);};
template <typename T> inline void chmin(T &a, const T& b){if(a>b)a=b;}
template <typename T> inline void chmax(T &a, const T& b){if(a<b)a=b;}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'A') a++;
    else b++;
  }
  if (a==0 || b == 0) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
  }
}
