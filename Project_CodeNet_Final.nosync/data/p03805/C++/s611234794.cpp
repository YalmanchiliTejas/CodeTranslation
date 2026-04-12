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
#include <sstream>
#include <unistd.h>

#define ll long long
#define Int int
#define loop(x, start, end) for(Int x = start; x < end; x++)
#define loopdown(x, start, end) for(int x = start; x > end; x--)
#define rep(n) for(int __x = 0; __x < n; __x++)
#define span(a,x,y) a.begin()+x,a.begin()+y
#define span_all(a) a.begin(),a.end()
#define len(x) (x.size())
#define last(x) (x.at(x.size()-1))

using namespace std;

#define EPS 0.0000000001
#define MOD 1000000007

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

#define MAX_N 8
#define MAX_M (8*7*0.5)

Int N, M;
vector<vector<Int> > G(MAX_N, vector<Int>(MAX_N, 0));

void input() {
  cin >> N >> M;
  Int u, v;
  loop(m,0,M) {
    cin >> u >> v;
    u--,v--;
    G.at(u).at(v) = 1;
    G.at(v).at(u) = 1;
  }
}

Int bit() {
  vector<Int> path;
  loop(n,0,N) path.push_back(n);
  Int numPaths = 0;
  do {
    bool ok = true;
    loop(i,1,path.size()) {
      if (!G.at(path.at(i-1)).at(path.at(i))) {
        ok = false;
        break;
      }
    }
    if (ok) numPaths++;
  } while (next_permutation(path.begin()+1, path.end()));
  return numPaths;
}

void solve() {
  cout << endl;
  cout << bit() << endl;
}

int main(void) {
  input();
  solve();
  return 0;
}
