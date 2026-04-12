#include<iostream>
#include<vector>
#include<complex>
#include<utility>
#include<queue>
#include<cmath>
#include<iomanip>

typedef long double ld;
typedef std::complex<ld> P;
const ld eps = 1e-8, pi = acos(-1.0);
struct L { P a, b; };

namespace std {
  bool operator<(const P &lhs, const P &rhs) {
    return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag()
      : lhs.real() < rhs.real();
  }
}

using namespace std;

ld dot(P a, P b) { return real(conj(a) * b); }
ld cross(P a, P b) { return imag(conj(a) * b); }
int ccw(P a, P b, P c) {
  b -= a, c -= a;
  if (cross(b, c) > eps) return 1;
  if (cross(b, c) < -eps) return -1;
  if (dot(b, c) < 0) return 2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

bool isis_sp(L s, P p) {
  return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps;
}


P is_ll(L s, L t){
  P sv = s.b - s.a, tv = t.b - t.a;
  return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

bool isis_ss(L s, L t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
    ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

P proj(L l, P p) {
  ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + t * (l.a - l.b);
}

ld dist_pp(P p, P q) {
  return abs(p - q);
}

ld dist_sp(L s, P p) {
  P r = proj(s, p);
  if (isis_sp(s, r)) return abs(r - p);
  return min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss (L s, L t) {
  if (isis_ss(s, t)) return 0;
  ld a = min(dist_sp(s, t.a), dist_sp(t, s.a));
  ld b = min(dist_sp(s, t.b), dist_sp(t, s.b));
  return min(a, b);
}

P rotate(ld deg, P p) {
  ld rad = deg * pi / 180.0;
  return polar((ld)1.0, rad) * p;
}

struct Star { L e[5]; };

ld dist_stst(Star s, Star t) {
  ld val = dist_ss(s.e[0], t.e[0]);
  for (L ss : s.e) for (L ts : t.e) {
    val = min(val, dist_ss(ss, ts));
  }
  return val;
}

int main() {
  int n, m, l;
  while (cin >> n >> m >> l and n) {
    m--; l--;
    vector<Star> stars(n);
    for (Star &s : stars) {
      int x, y ,a, r;
      cin >> x >> y >> a >> r;
      P center(x, y);
      for (int i = 0; i < 5; i++) {
        s.e[i].a = 
          center + polar((ld)r, (90 + a + 72 * i) * pi / 180.0);
        s.e[i].b = 
          center + polar((ld)r, (90 + a + 72 * (i + 2)) * pi / 180.0);
      }
    }

    vector<vector<ld>> dist(n);
    for (vector<ld> &v : dist) {
      v.reserve(n);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = dist_stst(stars[i], stars[j]);
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    cout << fixed << setprecision(30)<< dist[m][l] << endl;
  }
}