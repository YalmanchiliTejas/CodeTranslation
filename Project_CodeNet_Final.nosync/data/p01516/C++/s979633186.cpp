#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <complex>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define REP2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(S) (S).begin(), (S).end()

template <typename T, typename E>
ostream &operator<<(std::ostream &os, const std::pair<T, E> &p){
  return os << "(" << p.first << ", " << p.second << ")";
}

typedef long long ll;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line_t;
typedef pair<xy_t, double> circle_t;
typedef vector<xy_t> poly_t;

namespace std {
  bool operator<(const xy_t &a, const xy_t &b){
    return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real();
  }
}

const double EPS = 1e-9;

inline bool equal(double a, double b){
  return abs(a - b) < EPS;
}

istream &operator>>(istream &is, xy_t &p)   {
  double x, y;
  is >> x >> y;
  p = xy_t(x, y);
  return is;
}

istream &operator>>(istream &is, line_t &l) {
  return is >> l.first >> l.second;
}

inline double cross(const xy_t &a, const xy_t &b){
  return imag(conj(a) * b);
}

inline double dot(const xy_t &a, const xy_t &b){
  return real(conj(a) * b);
}

inline xy_t rotate(const xy_t &a, double theta){
  return a * polar(1.0, theta);
}

inline xy_t direction(const line_t &line){
  return line.second - line.first;
}

int ccw(const xy_t &a, xy_t b, xy_t c){
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return 1;
  if (cross(b, c) < 0) return -1;
  if (dot(b, c)   < 0) return 2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

int ccw(const line_t &l, const xy_t &a){
  return ccw(l.first, l.second, a);
}

bool intersectSP(const line_t &s, const xy_t &p) {
  return abs(s.first - p) + abs(s.second - p) - abs(direction(s)) < EPS;
}

bool intersectSS(const line_t &s, const line_t &t) {
  return ccw(s, t.first) * ccw(s, t.second) <= 0 &&
         ccw(t, s.first) * ccw(t, s.second) <= 0;
}

xy_t projection(const line_t &l, const xy_t &p) {
  double t = dot(p - l.first, direction(l)) / norm(direction(l));
  return l.first + t*(direction(l));
}

double distanceSP(const line_t &s, const xy_t &p) {
  const xy_t r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s.first - p), abs(s.second - p));
}

double distanceSS(const line_t &s, const line_t &t) {
  if (intersectSS(s, t)) return 0;
  
  return min(min(distanceSP(s, t.first), distanceSP(s, t.second)),
             min(distanceSP(t, s.first), distanceSP(t, s.second)));
}

struct star {
  int x, y, a, r;
  
  vector<xy_t> points() const {
    vector<xy_t> ps;
    xy_t   center = xy_t(x, y);
    double theta  = (double)a / 180 * M_PI + M_PI / 2;
    REP(i, 5) {
      ps.push_back(center + polar((double)r, theta + M_PI * i * 2 / 5));
    }
    return ps;
  }
  
  vector<line_t> segments() const {
    vector<xy_t>   ps = this->points();
    vector<line_t> res;

    res.push_back(line_t(ps[0], ps[2]));
    res.push_back(line_t(ps[1], ps[3]));
    res.push_back(line_t(ps[2], ps[4]));
    res.push_back(line_t(ps[3], ps[0]));
    res.push_back(line_t(ps[4], ps[1]));
    return res;
  }
};

double distance(const star &s, const star &t){
  vector<line_t> seg_ss = s.segments();
  vector<line_t> seg_ts = t.segments();
  double res = 1e9;

  for (line_t seg_s : seg_ss){
    for (line_t seg_t : seg_ts){
      res = min(res, distanceSS(seg_s, seg_t));
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);

  int N, M, L;
  while (cin >> N >> M >> L && N + M + L){
    vector<star> stars(N);
    vector<vector<double> > dist(N, vector<double>(N));
    REP(i, N){
      cin >> stars[i].x >> stars[i].y >> stars[i].a >> stars[i].r;
    }

    REP(i, N) REP(j, N){
      dist[i][j] = distance(stars[i], stars[j]);
      // cout << dist[i][j]<< (j == N - 1 ? '\n' : ' ');
    }
    
    REP(k, N) REP(i, N) REP(j, N){
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    printf("%.20lf\n", dist[L - 1][M - 1]);
  }
  return 0;
}