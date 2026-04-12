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

Int A, B, C, X, Y;

// i) 
//

void input() {
  cin >> A >> B >> C >> X >> Y;
}

Int dfs(Int x, Int y) {
  if (x <= 0 && y <= 0) return 0;
  if (x > 0 && y > 0) {
    Int num = min(x, y);
    Int cost = 0;
    if (C*2 > A+B) cost += A*num + B*num;
    else cost += C*2*num;
    cost += dfs(x-num, y-num);
    return cost;
  }

  if (x > 0) {
    if (C*2 > A) return A*x;
    else return C*2*x;
  }

  // y > 0;
  if (C*2 > B) return B*y;
  else return C*2*y;
}

void solve() {
  cout << dfs(X, Y) << endl;
}

int main() {
  input();
  solve();
  return 0;
}
