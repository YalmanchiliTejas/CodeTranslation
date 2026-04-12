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
  int n;
  cin >> n;
  vector <ll> vec(n);
  vector <ll> original(n);
  rep(i, n) {
    cin >> vec[i];
    original[i] = vec[i];
  }
  sort(original.begin(), original.end());
  ll x = original[n/2 - 1] + original[n/2];
  for (int i = 0; i < n; ++i) {
    if (vec[i]*2 <= x) {
      cout << original[n/2] << '\n';
    } else {
      cout << original[n/2 - 1] << '\n';
    }
  }
  
}
