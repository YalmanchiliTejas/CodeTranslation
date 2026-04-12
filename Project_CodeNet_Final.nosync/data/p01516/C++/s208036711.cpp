#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

typedef complex<ld> Point;

const ld eps = 1e-9, pi = acos(-1.0);

namespace std {
  bool operator<(const Point &lhs, const Point &rhs) {
    if (lhs.real() < rhs.real() - eps) return true;
    if (lhs.real() > rhs.real() + eps) return false;
    return lhs.imag() < rhs.imag();
  }
}

bool eq(ld a, ld b) {
  return (abs(a - b) < eps);
}

ld dot(Point a, Point b) {
  return real(conj(a) * b);
}

ld cross(Point a, Point b) {
  return imag(conj(a) * b);
}

class Line {
public:
  Point a, b;
  Line () : a(Point(0, 0)), b(Point(0, 0)) {}
  Line (Point a, Point b) : a(a), b(b) {}
};

int ccw (Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b, c) > eps) return 1;
  if (cross(b, c) < -eps) return -1;
  if (dot(b, c) < 0) return 2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

bool isis_ss(Line s, Line t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
    ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool isis_sp (Line s, Point p) {
  return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

Point proj (Line l, Point p) {
  ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + t * (l.a - l.b);
}

ld dist_sp (Line s, Point p) {
  Point r = proj(s, p);
  return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss (Line s, Line t) {
  if (isis_ss(s, t)) return 0;
  return min({dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b)});
}

int main(){
  int N, M, L;
  while(cin >> N >> M >> L && N) {
    M--;
    L--;
    vector<vector<Point>> star(N, vector<Point> (5));
    REP(i,N) {
      ld x, y, a, r;
      cin >> x >> y >> a >> r;
      a *= pi / 180;
      REP(j,5){
        star[i][j] = Point(x, y) + r * exp(Point(0,1) * (a + pi / 2 + j * 2 * pi / 5));
      }
    }

    vector<vector<ld>> d(N, vector<ld> (N, 0));
    REP(i,N)REP(j,N){
      ld tmp = INF;
      REP(k,5)REP(l,5){
        Line l1(star[i][k], star[i][(k + 2) % 5]);
        Line l2(star[j][l], star[j][(l + 2) % 5]);
        tmp = min(tmp, dist_ss(l1, l2));
      }
      d[i][j] = tmp;
    }

    REP(k,N)REP(i,N)REP(j,N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cout << fixed << setprecision(10) << d[M][L] << endl;
  }
  return 0;
}