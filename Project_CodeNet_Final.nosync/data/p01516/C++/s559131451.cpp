#include<iostream>
#include<cmath>
#include<queue>
#include<complex>
#include<cstdio>
#include<vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

const double INF = 1e40;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef complex<double> P;
typedef pair<P, P> L;
#define X real()
#define Y imag()
enum CCW{FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, ON = 16};

int sig(double r) {return (r < -EPS) ? -1 : (r > EPS) ? 1: 0;}
bool eq(double a, double b) {return abs(a - b) < EPS;}
double dot(P a, P b) {return a.X * b.X + a.Y * b.Y;}
double cross(P a, P b) {return a.X * b.Y - a.Y * b.X;}
int ccw(const P a, P b, P x) {
  b -= a;
  x -= a;
  double cr = cross(b, x);
  if (eq(cr, 0)) {
    if (dot(b, x) < 0) return BACK;
    if (abs(b) < abs(x)) return FRONT;
    return ON;
  }
  return (cr > 0) ? LEFT : RIGHT;
}
P vec(L a) {return a.second - a.first;}
bool iSS(L a, L b) {
  int cwaf = ccw(a.first, a.second, b.first);
  int cwbf = ccw(b.first, b.second, a.first);
  int cwas = ccw(a.first, a.second, b.second);
  int cwbs = ccw(b.first, b.second, a.second);
  if ((cwaf | cwas | cwbf | cwbs) & ON) return true;
  return (cwaf | cwas) == (LEFT | RIGHT) && (cwbf | cwbs) == (LEFT | RIGHT);
}
double dLP(L l, P x) {return abs(cross(vec(l), x - l.first)) / abs(vec(l));}
double dSP(L s, P x) {
  if (dot(vec(s), x - s.first) <= 0) return abs(x - s.first);
  if (dot(-vec(s), x - s.second) <= 0) return abs(x - s.second);
  return dLP(s, x);
}
double dSS(L a, L b) {return iSS(a, b) ? 0 : min(min(dSP(a, b.first), dSP(a, b.second)), min(dSP(b, a.first), dSP(b, a.second)));}


double x[111], y[111], a[111], r[111];
L star[111][5];
double dis[111][111];
double mem[111];

void f(int s, int t) {
  double res = 1e40;
  rep (i, 5) rep (j, 5) {
    res = min(dSS(star[s][i], star[t][j]), res);
    if (eq(res, 0)) break;
  }
  dis[s][t] = res;
}

int main() {
  int n, m, l;
  for (;;) {
    cin >> n >> m >> l;
    if (n == 0 && m == 0 && l == 0) break;
    --m; --l;
    rep (i, n) cin >> x[i] >> y[i] >> a[i] >> r[i];
    rep (i, n) a[i] = a[i] / 360 * 2 * PI;
    rep (i, n) rep (j, 5) {
      double theta = a[i] + j * 2 * PI / 5 + PI / 2;
      P p1 = P(x[i] + r[i] * cos(theta), y[i] + r[i] * sin(theta));
      theta = a[i] + (j + 2) * 2 * PI / 5 + PI / 2;
      P p2 = P(x[i] + r[i] * cos(theta), y[i] + r[i] * sin(theta));
      star[i][j] = L(p1, p2);
    }
    rep (i, n) rep (j, n) if (i < j) f(i, j);
    rep (i, n) rep (j, n) if (i > j) dis[i][j] = dis[j][i];
    rep (i, n) mem[i] = INF;
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que;
    que.push(make_pair(0, m));
    while (!que.empty()) {
      pair<double, int> now = que.top();
      que.pop();
      if (mem[now.second] <= now.first) continue;
      mem[now.second] = now.first;
      rep (i, n) if (i != now.second) {
	que.push(make_pair(now.first + dis[now.second][i], i));
      }
    }
    printf("%.12lf\n", mem[l]);
  }
}