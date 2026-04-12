/*
 * atcoder/dp/l.cpp
 */

// C++ 14
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <cstring>

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

template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }


struct Point {
  Int x, y;
  Point(Int x, Int y): x(x), y(y) {}
  Point(): x(0), y(0) {}

  Point operator + (Point v) { return Point(x + v.x, y + v.y); }
  Point operator - (Point v) { return Point(x - v.x, y - v.y); }
  bool operator == (const Point &v) const {
    return x == v.x && y == v.y;
  }
  bool operator< (const Point &p1) const {
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


vector<Int> slice(vector<Int> &vec, int s, int t) {
  return vector<Int>(vec.begin()+s, vec.begin()+t);
}

vector<Int> trim(vector<Int> &vec, int n) {
  auto init = slice(vec, 0, n);
  auto tail = slice(vec, n+2, vec.size());
  init.insert(init.end(), tail.begin(), tail.end());
  return init;
}


const Int INFTY = 100000000000000000;
Int N;
vector<Int> A;

// [10 80 90 30] 0
// [10 80 90] 30
// [10 80] 30 - 90 = - 60
// [10] -60+80 = 20
// [] -10+20 = 10

// [n:m)
Int dp[3001][3001];

void input() {
  cin >> N;
  Int a;
  loop(n,0,N) {
    cin >> a;
    A.push_back(a);
  }
}

Int rec(Int l, Int r, Int sign) {
  Int &cache = dp[l][r];
  if (cache < INFTY) return cache;

  if (l==r) return cache = 0;
  if (r-l==1) {
    return cache = sign * A[l];
  }

  if (sign > 0) {
    return cache = max(
      sign * A[l] + rec(l+1, r, sign * -1),
      rec(l, r-1, sign * -1) + sign * A[r-1]
    );
  }

  // sign < 0
  return cache = min(
    sign * A[l] + rec(l+1, r, sign * -1),
    rec(l, r-1, sign * -1) + sign * A[r-1]
  );
}

Int minmax(Int a, Int b, int sign) {
  if (sign > 0) return max(a, b);
  else return min(a, b);
}

Int receive() {
  loop(i,0,N) dp[i][i] = 0;
  loop(len,1,N+1) {
    loop(i,0,N+1) {
      if (i+len > N) break;
      int j=i+len;
      int sign = ((N-len)%2==0) ? 1 : -1;
      dp[i][j] = minmax(dp[i+1][j] + sign * A[i], dp[i][j-1] + sign * A[j-1], sign);
    }
  }

  return dp[0][N];
}

Int memoRec() {
  loop(i,0,N+1) loop(j,0,N+1) dp[i][j] = INFTY;
  return rec(0, N, 1);
}

void solve() {
  // Int result = memoRec();
  Int result = receive();
  cout << result << endl;
}

int main() {
  // cout.precision(15);
  input();
  solve();
  return 0;
}
