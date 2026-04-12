// C++ 14
#include <iostream>
#include <string>
#include <cstring> // memset
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <math.h>

#define ll long long
#define Int ll
#define loop(__x, __start, __end) for(Int __x = __start; __x < __end; __x++)
#define loopdown(__x, __start, __end) for(Int __x = __start; __x > __end; __x--)
#define rep(__n) for(Int __x = 0; __x < __n; __x++)
#define span(__a,__x,__y) __a.begin()+__x,__a.begin()+__y
#define span_all(__a) __a.begin(),__a.end()
#define len(__x) (__x.size())
#define last(__x) (__x[__x.size()-1])

using namespace std;

struct Point {
  Int x, y;
  Point(Int x, Int y): x(x), y(y) {}
  Point(): x(0), y(0) {}

  bool operator< (const Point &p1) {
    return x < p1.x && y < p1.y;
  }
};
ostream & operator << (ostream & out, Point const & v) {
  out << "Point(" << v.x << ", " << v.y << ')';
  return out;
}

istream & operator >> (istream & in, Point & v) {
  Int x, y;
  in >> x; in >> y; v.x = x; v.y = y;
  return in;
}

// Geometry

#define EPS 0.0000000001

class Vector2 {
public:
  double x, y;
  
  Vector2(double x = 0, double y = 0): x(x), y(y) {}
  
  Vector2 operator + (Vector2 v) { return Vector2(x + v.x, y + v.y); }
  Vector2 operator - (Vector2 v) { return Vector2(x - v.x, y - v.y); }
  Vector2 operator * (double k) { return Vector2(x * k, y * k); }
  Vector2 operator / (double k) { return Vector2(x / k, y / k); }
  
  double length() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
  double dot (Vector2 v) { return x * v.x + y * v.y; }
  double cross (Vector2 v) { return x * v.y - y * v.x; }

  bool operator < (const Vector2 &v) const {
    return x != v.x ? x < v.x : y < v.y;
  }

  bool operator == (const Vector2 &v) const {
    return fabs(x - v.x) < EPS && fabs(y - v.y) < EPS;
  }
};

ostream & operator << (ostream & out, Vector2 const & v) { 
  out<< "Vector2(" << v.x << ", " << v.y << ')';
  return out;
}

istream & operator >> (istream & in, Vector2 & v) { 
  double x, y;
  in >> x;
  in >> y;
  v.x = x;
  v.y = y;
  return in;
}

Int D;
vector<int> N;
#define MOD 1000000007


void input() {
  string n;
  cin >> n >> D;

  for (auto x: n) {
    N.push_back(x - '0');
  }
}

// (整数の最大桁数, 次の数字に制限があるか, 和)
int dp[10002][2][101];


Int solveRec(vector<int> &digits, int k = 0, bool tight = true, int sum = 0) {
  // 整数文字列の最後まで到達
  if (k == digits.size()) {
    return sum % D == 0;
  }
  Int x = digits.at(k);
  Int r = tight ? x : 9; // その桁において最大の場合は次の桁で制限がかかる

  Int res = dp[k][tight][sum];
  if (~res) return res; // DP
  res = 0;
  for (Int i=0; i<=r; i++) {
    res += solveRec(digits, k + 1, tight && i == r, (sum + i) % D);
    res %= MOD;
  }
  dp[k][tight][sum] = res;
  return res;
}


void solve() {
  memset(dp, -1, sizeof(dp));
  Int total = solveRec(N);
  total = (total - 1) % MOD; // remove 0
  if (total < 0) total += MOD;
  cout << total << endl;
}


int main() {
  input();
  solve();
  return 0;
}
