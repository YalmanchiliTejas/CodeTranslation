
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, s, e) for(int i = (int)(s); i < (int)(e); ++i)

#define X() real()
#define Y() imag()
#define x(p) (p).X()
#define y(p) (p).Y()
#define SZ(R) (int)(R).size()
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%SZ(P)]
#define prev(P, i) P[(i-1+SZ(P)%SZ(P)]

using D = double;
using P = complex<D>;
namespace std {
  bool operator < (const P& a, const P& b) {
    return x(a) != x(b) ? x(a) < x(b) : y(a) < y(b);
  }
}
D dot(const P& a, const P& b) {
  return x(conj(a)*b);
}
D cross(const P& a, const P& b) {
  return y(conj(a)*b);
}
int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if(cross(b, c) > 0) return +1;
  if(cross(b, c) < 0) return -1;
  if(dot(b, c) < 0) return +2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}
struct L : public vector<P> {
  L(){}
  L(const P& a, const P& b) {
    push_back(a);
    push_back(b);
  }
};

using G = vector<P>;
const D EPS = 1e-8;
const D PI = acos(-1);

P makeP(D arg, D r = 1.0) {
  return r * P{cos(arg), sin(arg)};
}
P rotP(const P& p, D arg) {
  return p * makeP(arg);
}
D getArgP(const P& p) {
  return atan2(y(p), x(p));
}
D toRad(D deg) {
  return PI * deg / 180.0;
}

G makeStar(const P& p, D arg, D r) {
  G ret;
  P v{0.0, r};
  rep(i, 5) {
    ret.push_back(p + rotP(v, 2*PI/5*i+arg));
  }
  return ret;
}

bool interSP(const L& s, const P& p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[0]-s[1]) < EPS;
}
bool interSS(const L& s, const L& t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
    ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
P proj(const L& l, const P& p) {
  P v = l[0]-l[1];
  D t = dot(p - l[0], v) / norm(v);
  return l[0] + t*(v);
}
D distSP(const L& s, const P& p) {
  P r = proj(s, p);
  if(interSP(s, r)) return abs(r-p);
  return min(abs(s[0]-p), abs(s[1]-p));
}
D distSS(const L& s, const L& t) {
  if(interSS(s, t)) return 0.0;
  return min({distSP(s, t[0]), distSP(s, t[1]), distSP(t, s[0]), distSP(t, s[1])});
}

int main() {
  cout << fixed << setprecision(20);
  int n, a, b;
  while(cin >> n >> a >> b) {
    if(n == 0 && a == 0 && b  == 0) break;
    a--;
    b--;
    vector<G> gs;
    rep(i, n) {
      D x, y, a, r;
      cin >> x >> y >> a >> r;
      gs.push_back(makeStar(P{x, y}, toRad(a), r));
    }
    const D INF = 1e18;
    vector<vector<D>> d(n, vector<D>(n, INF));
    rep(i, n) d[i][i] = 0.0;
    using Ls = vector<L>;
    vector<Ls> v(n);
    rep(i, n) {
      rep(j, 5) {
	v[i].push_back(L{curr(gs[i], j), next(gs[i], j+1)});
      }
    }
    rep(i, n) rep(j, i) {
      double dist = INF;
      rep(k, 5) rep(l, 5) {
	dist = min(dist, distSS(v[i][k], v[j][l]));
      }
      d[i][j] = d[j][i] = min(d[i][j], dist);
    }

    rep(k, n) rep(i, n) rep(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cout << d[a][b] << endl;
  }
  return 0;
}