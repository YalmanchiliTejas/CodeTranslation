#include <iostream>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define FOR(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define PRINT(str) printf(#str "\n")

//関数定義
//最大公約数
ll gcd(ll a, ll b);

//最小公倍数
ll lcm(ll a, ll b);

int main() {
  // ========================================================
  string s;
  cin >> s;
  REP(i, 2) {
    if (s[i] != s[i + 1]) {
      PRINT(Yes);
      return 0;
    }
  }
  PRINT(No);
}

//最大公約数
ll gcd(ll a, ll b) {
  if (!b) return a;
  return gcd(b, a % b);
}

//最小公倍数
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }