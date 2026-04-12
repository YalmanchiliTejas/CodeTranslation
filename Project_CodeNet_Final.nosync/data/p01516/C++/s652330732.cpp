/*
 * 2402.cc: Milky Way
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 100;
const int PN = 5;
const double PI = acos(-1.0);
const double DINF = 1.0e10;
  
/* typedef */

typedef pair<double,int> pdi;

template <typename T>
struct Pt {
  T x, y;

  Pt() {}
  Pt(T _x, T _y) : x(_x), y(_y) {}
  Pt(const Pt& pt) : x(pt.x), y(pt.y) {}

  bool operator==(const Pt pt) const { return x == pt.x && y == pt.y; }
  Pt<T> operator+(const Pt pt) const { return Pt<T>(x + pt.x, y + pt.y); }
  Pt<T> operator-() const { return Pt<T>(-x, -y); }
  Pt<T> operator-(const Pt pt) const { return Pt<T>(x - pt.x, y - pt.y); }
  Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
  Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
  T dot(Pt v) const { return x * v.x + y * v.y; }
  T cross(Pt v) const { return x * v.y - y * v.x; }
  Pt<T> mid(const Pt pt) { return Pt<T>((x + pt.x) / 2, (y + pt.y) / 2); }
  T d2() { return x * x + y * y; }
  double d() { return sqrt(d2()); }

  Pt<T> rot(double th) {
    double c = cos(th), s = sin(th);
    return Pt<T>(c * x - s * y, s * x + c * y);
  }

  Pt<T> rot90() { return Pt<T>(-y, x); }

  bool operator<(const Pt& pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
  }

  void print(string format) {
    printf(("(" + format + ", " + format + ")\n").c_str(), x, y);
  }
  void print() { print("%.6lf"); }
};

typedef Pt<double> pt;
typedef vector<pt> vpt;

struct CL {
  pt p;
  double t0, t1;
  CL() {}
  CL(const pt& _p, double _t0, double _t1) : p(_p), t0(_t0), t1(_t1) {}
};

/* global variables */

pt pts[MAX_N][PN];
double ds[MAX_N][MAX_N], dists[MAX_N];

/* subroutines */

bool cross_lines(const pt& ap, const pt av, const pt& bp, const pt bv, CL& cl) {
  double op01 = av.cross(bv);
  //if (op01 == 0.0) return false; /* need to handle parallel?? */

  if (op01 == 0.0) {
    pt v = bp - ap;
    if (v.cross(av) != 0.0) return false;

    pt a1 = ap + av;
    pt b1 = bp + bv;

    return
      ((bp - ap).dot(b1 - ap) <= 0.0 ||
       (bp - a1).dot(b1 - a1) <= 0.0 ||
       (ap - bp).dot(a1 - bp) <= 0.0 ||
       (ap - b1).dot(a1 - b1) <= 0.0);
  }

  pt v = bp - ap;
  double op0 = v.cross(av);
  double op1 = v.cross(bv);

  double t0 = op1 / op01;
  double t1 = op0 / op01;

  cl.p = bv * t1 + bp;
  cl.t0 = t0;
  cl.t1 = t1;

  return true;
  //return (0.0 <= cl.t0 && cl.t0 <= 1.0 && 0.0 <= cl.t1 && cl.t1 <= 1.0);
}

bool cross_segs(const pt& ap, const pt av, const pt& bp, const pt bv, CL& cl) {
  if (! cross_lines(ap, av, bp, bv, cl)) return false;
  return (0.0 <= cl.t0 && cl.t0 <= 1.0 && 0.0 <= cl.t1 && cl.t1 <= 1.0);
}

double dist_pt_seg(pt &p, pt &bp, pt &bv) {
  pt v0 = p - bp;
  if (v0.dot(bv) < 0.0) return v0.d();
  pt v1 = p - (bp + bv);
  if (v1.dot(-bv) < 0.0) return v1.d();

  CL cl;
  pt pv = bv.rot90();
  cross_lines(p, pv, bp, bv, cl);
  return (cl.p - p).d();
}

double dist_segs(pt &ap, pt &av, pt &bp, pt &bv) {
  CL cl;
  if (cross_segs(ap, av, bp, bv, cl)) return 0.0;

  double mind = dist_pt_seg(ap, bp, bv);
  pt ap0 = ap + av;
  double d = dist_pt_seg(ap0, bp, bv);
  if (mind > d) mind = d;
  d = dist_pt_seg(bp, ap, av);
  if (mind > d) mind = d;
  pt bp0 = bp + bv;
  d = dist_pt_seg(bp0, ap, av);
  if (mind > d) mind = d;
  return mind;
}

double dist_stars(int s0, int s1) {
  double mind = DINF;
  for (int i = 0; i < PN; i++) {
    pt &ap = pts[s0][i];
    pt av = pts[s0][(i + 2) % PN] - ap;
    for (int j = 0; j < PN; j++) {
      pt &bp = pts[s1][j];
      pt bv = pts[s1][(j + 2) % PN] - bp;
      double d = dist_segs(ap, av, bp, bv);
      if (mind > d) mind = d;
    }
  }
  return mind;
}

/* main */

int main() {
  for (;;) {
    int n, m, l;
    cin >> n >> m >> l;
    if (n == 0) break;
    m--, l--;
    
    double dth = PI * 2 / PN;
    
    for (int i = 0; i < n; i++) {
      double x, y, a, r;
      cin >> x >> y >> a >> r;
      double th0 = PI * (90 + a) / 180;

      for (int j = 0; j < PN; j++) {
	double th = th0 + dth * j;
	pts[i][j].x = x + r * cos(th);
	pts[i][j].y = y + r * sin(th);
      }
    }

    for (int i = 0; i < n; i++) {
      ds[i][i] = 0.0;
      for (int j = i + 1; j < n; j++)
	ds[i][j] = ds[j][i] = dist_stars(i, j);
      dists[i] = DINF;
    }

    dists[m] = 0.0;
    priority_queue<pdi> q;
    q.push(pdi(0.0, m));

    while (! q.empty()) {
      pdi u = q.top(); q.pop();
      double ud = -u.first;
      int &ui = u.second;
      if (dists[ui] != ud) continue;
      if (ui == l) break;

      for (int vi = 0; vi < n; vi++) {
	if (vi == ui) continue;
	double vd = ud + ds[ui][vi];
	if (dists[vi] > vd) {
	  dists[vi] = vd;
	  q.push(pdi(-vd, vi));
	}
      }
    }

    printf("%.10lf\n", dists[l]);
  }
  return 0;
}