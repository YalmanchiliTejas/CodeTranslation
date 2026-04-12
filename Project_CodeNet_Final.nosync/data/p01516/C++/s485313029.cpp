#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/* 基本要素 */

#define X real()
#define Y imag()

using Double = double;
using Point = complex<Double>;
using Line = pair<Point, Point>;
using Polygon = vector<Point>;

const Double EPS = 1e-9;
const Double PI = acos(-1);
const Double INF = numeric_limits<Double>::max();

// 正，負，ゼロの判定
int sgn(Double x) {
  return x < -EPS ? -1 : x > +EPS ? 1 : 0;
}
// 内積
Double dot(Point a, Point b) {
  return (conj(a)*b).X;
}
// 外積
Double cross(Point a, Point b) {
  return (conj(a)*b).Y;
}
// 点の進行方向
int ccw(Point a, Point b, Point c) {
  b -= a; c -= a;
  if (sgn(cross(b,c))    > 0) return +1; // counter clockwise
  if (sgn(cross(b,c))    < 0) return -1; // clockwise
  if (sgn(dot(b,c))      < 0) return +2; // c--a--b on line
  if (sgn(abs(b)-abs(c)) < 0) return -2; // a--b--c on line or a==b
  return 0;                              // a--c--b on line or a==c or b==c
}
// ベクトルの回転（xはラジアン）
Point rotated(Point a, double x) {
  return Point(a.X*cos(x)-a.Y*sin(x), a.X*sin(x)+a.Y*cos(x));
}

/* 交差判定 */

// 直線と点
bool isecLP(Point a1, Point a2, Point b) {
  return abs(ccw(a1, a2, b)) != 1;
}
// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}
// 直線と直線（交差もしくは重なる）
bool isecLL(Point a1, Point a2, Point b1, Point b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}
// 直線と線分
bool isecLS(Point a1, Point a2, Point b1, Point b2) {
  return sgn(cross(a2-a1, b1-a1)*cross(a2-a1, b2-a1)) <= 0;
}
// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

/* 距離 */

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}
// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

Double distLP(Point a1, Point a2, Point p) {
  return abs(proj(a1, a2, p) - p);
}
Double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  return min(abs(a1-p), abs(a2-p));
}
Double distLL(Point a1, Point a2, Point b1, Point b2) {
  return isecLL(a1, a2, b1, b2) ? 0 : distLP(a1, a2, b1);
}
Double distLS(Point a1, Point a2, Point b1, Point b2) {
  return isecLS(a1, a2, b1, b2) ? 0 : min(distLP(a1, a2, b1), distLP(a1, a2, b2));
}
Double distSS(Point a1, Point a2, Point b1, Point b2) {
  if (isecSS(a1, a2, b1, b2)) return 0;
  return min(min(distSP(a1, a2, b1), distSP(a1, a2, b2)),
             min(distSP(b1, b2, a1), distSP(b1, b2, a2)));
}
// 2直線の交点
Point crossPointLL(Point a1, Point a2, Point b1, Point b2) {
  Double d1 = cross(b2-b1, b1-a1);
  Double d2 = cross(b2-b1, a2-a1);
  if (!sgn(d1) && sgn(d2)) return a1;    // same line
  if (!sgn(d2)) throw "No cross point";  // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

int N, M, L;
Point ps[110][5];
Line es[110][5];
Double dis[110][110];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  while (cin >> N >> M >> L, N) {
    for (int i = 0; i < N; i++) {
      int x, y, a, r;
      cin >> x >> y >> a >> r;
      Point o(x, y);
      Point p = rotated(Point(0,r), PI*a/180);
      for (int j = 0; j < 5; j++) {
        ps[i][j] = o + p;
        p = rotated(p, 2*PI/5);
      }
      for (int j = 0; j < 5; j++) {
        es[i][j] = Line(ps[i][j], ps[i][(j+2)%5]);
      }
    }

    fill_n((Double*)dis, 110*110, INF);
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        Double tmp = INF;
        for (int k = 0; k < 5; k++) {
          for (int l = 0; l < 5; l++) {
            tmp = min(tmp, distSS(es[i][k].first, es[i][k].second, es[j][l].first, es[j][l].second));
          }
        }
        dis[i][j] = dis[j][i] = tmp;
      }
    }

    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
        }
      }
    }
    cout << dis[M-1][L-1] << endl;
  }

  return 0;
}
