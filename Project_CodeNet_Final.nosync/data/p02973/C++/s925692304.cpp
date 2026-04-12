#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(), (x).end()
#define Sort(x) sort((x).begin(), (x).end())
#define Reverse(x) reverse((x).begin(), (x).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, m, n) for (int i = m; i < n; i++)
#define INF INT_MAX
#define fcout cout << fixed << setprecision(15) // 15桁まで表示
#define en '\n'
using str = string;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using puu = pair<ui, ui>;
using P = pair<int, int>;
using vi = vector<int>;
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
};
int lcm(int a, int b) {
  return a / gcd(a, b) * b;
};
int floor(int a, int b) {
  return (a + b - 1) / b;
};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
};
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
};
const ll mod = 1000000007;
const double PI = acos(-1.0);
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << setiosflags(ios::fixed);

  int n, a;
  cin >> n;
  multiset<int> q;
  rep(i,n){
    cin >> a;
    auto it = q.upper_bound(a - 1);
    if (it != q.begin())
      q.erase(--it);
    q.insert(a);
  }
  cout << q.size() << en;
}