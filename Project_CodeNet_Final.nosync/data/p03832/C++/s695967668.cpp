#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <cmath>


using namespace std;


typedef long long ll;
typedef long double ld;


const ll MOD_CONST = 1000000007ll;


ll modSum(ll a, ll b, ll MOD = MOD_CONST) {
  return ((a % MOD) + (b % MOD)) % MOD;
}


ll modSubtract(ll a, ll b, ll MOD = MOD_CONST) {
  return (((a % MOD) - (b % MOD)) + MOD + MOD) % MOD;
}


ll modProd(ll a, ll b, ll MOD = MOD_CONST) {
  return ((a % MOD) * (b % MOD)) % MOD;
}


ll getPowMod(ll x, ll e, ll MOD = MOD_CONST) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPowMod(x, e/2, MOD);
    return modProd(tmp, tmp);
  } else {
    ll tmp = getPowMod(x, e-1, MOD);
    return modProd(tmp, x);
  }
}


ll getPow(ll x, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPow(x, e/2);
    return tmp * tmp;
  } else {
    ll tmp = getPow(x, e-1);
    return tmp * x;
  }
}


ll getInverse(ll x, ll MOD = MOD_CONST) {
  return getPowMod(x, MOD-2, MOD);
}


bool isEven(ll x) {
  ll tmp = ((x % 2) + 2) % 2;
  return tmp == 0;
}


ll getSumOfDigitsInBase(ll n, ll b) {
  ll ret = 0;
  while (n > 0) {
    ret += n % b;
    n /= b;
  }
  return ret;
}


vector<int> getKMP(string &s) {
  int len = (int)s.size();
  vector<int> ret (len, 0);
  for (int i = 1 ; i < len ; i++) {
    int at = ret[i-1];
    while (at > 0 && s[i] != s[at]) {
      at = ret[at-1];
    }
    if (s[i] == s[at]) {
      at++;
    }
    ret[i] = at;
  }
  return ret;
}


string getSubstring(string &s, int from, int to) {
  int l = to-from+1;
  if (l <= 0) {
    return "";
  }
  return s.substr(from, l);
}

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


pair<ll, ll> getIntersectingRange(ll a1, ll b1, ll a2, ll b2) {
  ll s = max(a1, a2);
  ll e = min(b1, b2);

  return {s, e};
}


bool isNonEmptyIntersection(ll a1, ll b1, ll a2, ll b2) {
  auto p = getIntersectingRange(a1, b1, a2, b2);
  return p.first <= p.second;
}


double getPointDistance(double x1, double y1, double x2, double y2) {
  double dx = x1-x2;
  double dy = y1-y2;
  double d = (dx * dx) + (dy * dy);
  return sqrt(d);
}


bool isPrime(ll x) {
  if (x == 2 || x == 3 || x == 5 || x == 7) return true;
  if (x < 10) return false;
  ll till = min((ll)sqrt(x) + 1, x-1);
  for (ll i = 2 ; i <= till ; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}














const int MAXN = 1002;


int N, A, B, C, D;
ll binom[MAXN][MAXN], memo[MAXN][MAXN], permDiv[MAXN];


void input() {
  cin >> N >> A >> B >> C >> D;
}


void preprocess() {
  for (int i = 1 ; i < MAXN ; i++) {
    binom[i][0] = 1;
    binom[i][i] = 1;
    for (int j = 1 ; j < i ; j++) {
      binom[i][j] = modSum(binom[i-1][j], binom[i-1][j-1]);
    }
  }
  permDiv[1] = 1;
  for (int i = 2 ; i < MAXN ; i++) {
    permDiv[i] = modProd(permDiv[i-1], getPowMod(i, MOD_CONST-2));
  }
}


void solve() {
  for (int add = 0 ; add <= B-A+1 ; add++) {
    memo[0][add] = 1;
  }
  for (int rem = 1 ; rem <= N ; rem++) {
    for (int add = 1 ; add <= B-A+1 ; add++) {
      memo[rem][add] = memo[rem][add-1];
      int val = add + A - 1;
      if (rem - (val * C) < 0) continue;
      ll mul = 1;
      for (int rep = 1 ; rep < C ; rep++) {
        mul = modProd(mul, binom[rem-(val*(rep-1))][val]);
      }

      for (int rep = C ; rep <= D && rem - (val * rep) >= 0 ; rep++) {
        mul = modProd(mul, binom[rem-(val*(rep-1))][val]);
        memo[rem][add] = modSum(memo[rem][add], modProd(modProd(mul, permDiv[rep]), memo[rem - (val * rep)][add-1]));
      }
    }
  }
  cout << memo[N][B-A+1];
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);

  int T;
//  cin >> T;
  T = 1;

  for (int i = 0 ; i < T ; i++) {
    input();
    preprocess();
    solve();
  }

  return 0;
}

/*
/home/mjguru/Desktop/CP/E-grouping/main.cpp:211:62: runtime error: index -1 out of bounds for type 'll [1002]'
 */