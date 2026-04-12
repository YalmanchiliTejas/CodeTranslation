#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define pb(a) push_back(a)
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(all(a))
#define REVERSE(a) reverse(all(a))

#define PRINT(str) printf(#str "\n")
#define yOUT PRINT(Yes)
#define nOUT PRINT(No)
#define YOUT PRINT(YES)
#define NOUT PRINT(NO)

//関数定義
//最大公約数
ll gcd(ll a, ll b);

//最小公倍数
ll lcm(ll a, ll b);

int main() {
  // ========================================================
  int a, b;
  cin >> a >> b;
  if (a == b)
    yOUT;
  else
    nOUT;
}

//最大公約数
ll gcd(ll a, ll b) {
  if (!b) return a;
  return gcd(b, a % b);
}

//最小公倍数
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
