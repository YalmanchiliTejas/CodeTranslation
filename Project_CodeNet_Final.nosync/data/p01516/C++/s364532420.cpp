#include <bits/stdc++.h>
using namespace std;

using P = complex<double>;

const double eps = 1e-7;

double dot(P a, P b) {
  return (a * conj(b)).real();
}

double cross(P a, P b) {
  return (conj(a) * b).imag();
}

int ccw(P a, P b, P c) {
  if(cross(b-a, c-a) > eps) return 1;
  if(cross(b-a, c-a) < -eps) return -1;
  if(dot(b-a, c-a) < -eps) return -2;
  if(dot(a-b, c-b) < -eps) return 2;
  return 0;
}

bool isIntersectedSS(P a1, P a2, P b1, P b2) {
  int a = ccw(b1, b2, a1);
  int b = ccw(b1, b2, a2);
  int c = ccw(a1, a2, b1);
  int d = ccw(a1, a2, b2);

  return a * b <= 0 && c * d <= 0;
}

double distanceSP(P a, P b, P c) {
  if(dot(b-a, c-a) < eps) return abs(c-a);
  if(dot(a-b, c-b) < eps) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

double getDistance(P a1, P a2, P b1, P b2) {
  if(isIntersectedSS(a1, a2, b1, b2)) return 0;

  return min({
              distanceSP(a1, a2, b1),
              distanceSP(a1, a2, b2),
              distanceSP(b1, b2, a1),
              distanceSP(b1, b2, a2),
    });
}

bool solve() {
  int N, M, L;
  int x[101], y[101], a[101], r[101];
  P points[101][5];

  cin >> N >> M >> L;

  if (N == 0) return false;

  for(int i=0; i<N; i++) {
    cin >> x[i] >> y[i] >> a[i] >> r[i];
    a[i] += 90;

    for(int j=0; j<5; j++) {
      double sx = cos((j * 72 + a[i]) / 180.0 * M_PI) * r[i] + x[i];
      double sy = sin((j * 72 + a[i]) / 180.0 * M_PI) * r[i] + y[i];
      points[i][j] = P(sx, sy);
    }
  }

  double dist[101][101];

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      dist[i][j] = (i != j) * 1e17;

  for(int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {

      for(int i2=0; i2<5; i2++) {
        for(int j2=0; j2<5; j2++) {
          dist[i][j] = dist[j][i] =
            min(dist[i][j], getDistance(points[i][i2], points[i][(i2+2)%5],
                                        points[j][j2], points[j][(j2+2)%5])
                );
        }
      }
    }
  }

  for(int k=0; k<N; k++)
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

  printf("%.10lf\n", dist[M-1][L-1]);


  return true;
}

int main(){
  while(solve());

}

