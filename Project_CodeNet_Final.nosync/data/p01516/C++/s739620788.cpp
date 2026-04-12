#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <numeric>
#include <cassert>
#include <complex>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

// geometry library

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
bool operator<(const P& a, const P& b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
};
double cross(const P& a, const P& b) { return imag(conj(a) * b); }
double dot(const P& a, const P& b) { return real(conj(a) * b); }

struct L : public vector<P> {
  L(){}
  L(const P& a, const P& b) {
    push_back(a); push_back(b);
  }
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1; // counter clock wise
  if (cross(b, c) < 0)   return -1; // clock wise
  if (dot(b, c) < 0)     return +2; // c--a--b 
  if (norm(b) < norm(c)) return -2; // a--b--c
  return 0;
}

bool intersectLL(const L& l, const L& m) {
  return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||
      abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;
}

bool intersectLS(const L& l, const L& s) {
  return cross(l[1] - l[0], s[0] - l[0]) *
      cross(l[1] - l[0], s[1] - l[0]) < EPS;
}

bool intersectLP(const L& l, const P& p) {
  return abs(cross(l[1] - p, l[0] - p)) < EPS;
}

bool intersectSS(const L& s, const L& t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
      ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

bool intersectSP(const L& s, const P& p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

P projection(const L& l, const P& p) {
  double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

double distanceLP(const L& l, const P& p) {
  return abs(p - projection(l, p));
}

double distanceLL(const L& l, const L& m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}

double distanceLS(const L& l, const L& s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}

double distanceSP(const L& s, const P& p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

double distanceSS(const L& s, const L& t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

P crosspoint(const L& l, const L& m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];
  if (abs(A) < EPS) assert(false);
  return m[0] + B / A * (m[1] - m[0]);
}

// end of library
const double kRad = M_PI / 180.0;
const int kInf = 1 << 28;
int N, M, Li;
L ls[102][7];
double dist[102][102];

void make_graph() {
  rep(i,N) rep(j,N) dist[i][j] = kInf;
  rep(i,N) rep(j,5) {
    L me = ls[i][j];
    rep(k,N) rep(l,5) {
      if (i == k) continue;
      L other = ls[k][l];
      dist[i][k] = min(dist[i][k], distanceSS(me, other));
    }
  }
}

double solve(int s, int t) {
  // vector<double> d(N, kInf);
  // d[s] = 0;
  // priority_queue<Pd, vector<Pd>, greater<Pd> > pq;
  // pq.push(Pd(0, s));
  // while (!pq.empty()) {
  //   Pd p = pq.top(); pq.pop();
  //   int v = p.second;
  //   if (d[v] < p.first) continue;
  //   for (int i = 0; i < N; ++i) {
      
  //   }
  // }
  // return d[t];
  rep(i,N) dist[i][i] = 0;
  rep(k,N) rep(i,N) rep(j,N)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  return dist[s][t];
}

int main() {
  while (scanf("%d%d%d", &N, &M, &Li), N) {
    --M; --Li;
    int x, y, a, r;
    rep(i,N) {
      scanf("%d%d%d%d", &x, &y, &a, &r);
      a += 18;
      vector<P> vp;
      for (int j = 0; j < 5; ++j) {
        double lx = r * cos(a * kRad) + x, ly = r * sin(a * kRad) + y;
        vp.push_back(P(lx, ly));
        a += 72;
        a %= 360;
      }
      ls[i][0] = L(vp[0], vp[2]);
      ls[i][1] = L(vp[1], vp[4]);
      ls[i][2] = L(vp[2], vp[4]);
      ls[i][3] = L(vp[3], vp[0]);
      ls[i][4] = L(vp[3], vp[1]);
    }
    make_graph();
    printf("%f\n", solve(M, Li));
  }
  return 0;
}