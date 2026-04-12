#include <iostream>
#include <cstdio>
#include <cmath>
#define REP(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;

struct point { double x, y; };
struct line { point p, q; };

int N, M, L, X[100], Y[100], A[100], R[100];
double d[100][100];

bool intersect(line l1, line l2) {
  double ax = l1.p.x, ay = l1.p.y;
  double bx = l1.q.x, by = l1.q.y;
  double cx = l2.p.x, cy = l2.p.y;
  double dx = l2.q.x, dy = l2.q.y;
  double ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  double tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  double tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  double td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
  return tc * td < 0 && ta * tb < 0;
}

double distance(line l, point p) {
  double x0 = p.x, y0 = p.y;
  double x1 = l.p.x, y1 = l.p.y;
  double x2 = l.q.x, y2 = l.q.y;
  double a = x2 - x1;
  double b = y2 - y1;
  double a2 = a * a;
  double b2 = b * b;
  double r2 = a2 + b2;
  double tt = -(a*(x1 - x0) + b*(y1 - y0));
  if(tt < 0) return sqrt((x1 - x0)*(x1-x0) + (y1 - y0)*(y1-y0));
  if(tt > r2) return sqrt((x2 - x0)*(x2 - x0) + (y2 - y0)*(y2 - y0));
  double f1 = a*(y1 - y0) - b*(x1 - x0);
  return sqrt((f1*f1)/r2);
}

double distance_star(int a, int b) {
  point pa[5], pb[5];
  REP(i, 0, 5) {
    double xa = X[a] + R[a] * cos((double) (A[a] + 72 * i + 90) / 180 * M_PI);
    double ya = Y[a] + R[a] * sin((double) (A[a] + 72 * i + 90) / 180 * M_PI);
    double xb = X[b] + R[b] * cos((double) (A[b] + 72 * i + 90) / 180 * M_PI);
    double yb = Y[b] + R[b] * sin((double) (A[b] + 72 * i + 90) / 180 * M_PI);
    pa[i] = (point) { xa, ya };
    pb[i] = (point) { xb, yb };
  }

  REP(i, 0, 5) REP(j, 0, 5) {
    line la = (line) { pa[i], pa[(i + 2) % 5] };
    line lb = (line) { pb[j], pb[(j + 2) % 5] };
    if(intersect(la, lb)) return 0;
  }

  double dist = 1e10;
  REP(i, 0, 5) REP(j, 0, 5) {
    line la = (line) { pa[i], pa[(i + 2) % 5] };
    line lb = (line) { pb[i], pb[(i + 2) % 5] };
    dist = min(dist, distance(la, pb[j]));
    dist = min(dist, distance(lb, pa[j]));
  }

  return dist;
}

int main(void) {
  while(cin >> N >> M >> L, N || M || L) {
    M--;
    L--;
    REP(i, 0, N) cin >> X[i] >> Y[i] >> A[i] >> R[i];

    REP(i, 0, N) REP(j, 0, N) d[i][j] = distance_star(i, j);
    REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    printf("%.8lf\n", d[M][L]);
  }

  return 0;
}