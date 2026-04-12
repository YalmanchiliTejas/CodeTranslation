#include<cstdio>
#include<complex>
#include<algorithm>
#include<cmath>
using namespace std;
typedef complex<double> P;
const double EPS = 1e-10;
#define EQ(a, b) (abs((a) - (b)) < EPS)

double dot(P a, P b) { return (a.real() * b.real() + a.imag() * b.imag()); }
double det(P a, P b) { return (a.real() * b.imag() - a.imag() * b.real()); }

int n, m, l, x[100], y[100], a[100], r[100];

P p[100][5];
double d[100][100];

double distanceLSP(P a, P b, P c) {
  if (dot(b-a, c-a) < EPS) return abs(c-a);
  if (dot(a-b, c-b) < EPS) return abs(c-b);
  return abs(det(b-a, c-a)) / abs(b-a);
}

bool isIntersectedLS(P a1, P a2, P b1, P b2) {
  if (EQ(det(a1-a2, b1-b2), 0.0)) {
    if (abs(a1-b1) + abs(a2-b1) < abs(a1-a2) + EPS) return true;
    if (abs(a1-b2) + abs(a2-b2) < abs(a1-a2) + EPS) return true;
    return false;
  }
  return (det(a2-a1, b1-a1) * det(a2-a1, b2-a1) < EPS) &&
         (det(b2-b1, a1-b1) * det(b2-b1, a2-b1) < EPS);
}

int main() {
  while (1) {
    scanf("%d%d%d", &n, &m, &l);
    if (n == 0) break;
    for (int i = 0; i < n; i++) scanf("%d%d%d%d", &x[i], &y[i], &a[i], &r[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        double S = (double)(a[i] + 72 * j) * M_PI / 180;
        p[i][j] = P(x[i] - r[i] * sin(S), y[i] + r[i] * cos(S));
      }
    }
    for (int i = 0; i < n; i++) d[i][i] = 0.0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        double temp = distanceLSP(p[i][0], p[i][2], p[j][0]);
        for (int k = 0; k < 5; k++) {
          for (int z = 0; z < 5; z++) {
            temp = min(temp, distanceLSP(p[i][k], p[i][(k + 2) % 5], p[j][z]));
            temp = min(temp, distanceLSP(p[i][k], p[i][(k + 3) % 5], p[j][z]));
            temp = min(temp, distanceLSP(p[j][k], p[j][(k + 2) % 5], p[i][z]));
            temp = min(temp, distanceLSP(p[j][k], p[j][(k + 3) % 5], p[i][z]));
            if (isIntersectedLS(p[i][k], p[i][(k + 2) % 5], p[j][z], p[j][(z + 2) % 5])) temp = 0.0, k = 5, z = 5;
            if (isIntersectedLS(p[i][k], p[i][(k + 3) % 5], p[j][z], p[j][(z + 2) % 5])) temp = 0.0, k = 5, z = 5;
            if (isIntersectedLS(p[i][k], p[i][(k + 2) % 5], p[j][z], p[j][(z + 3) % 5])) temp = 0.0, k = 5, z = 5;
            if (isIntersectedLS(p[i][k], p[i][(k + 3) % 5], p[j][z], p[j][(z + 3) % 5])) temp = 0.0, k = 5, z = 5;
          }
        }
        d[i][j] = d[j][i] = temp;
      }
    }
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    printf("%.9f\n", d[m-1][l-1]);
  }
}

