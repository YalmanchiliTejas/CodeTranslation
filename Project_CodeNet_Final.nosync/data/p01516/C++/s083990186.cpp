#include <bits/stdc++.h>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

using D = double;
using P = complex<D>;

const D PI = acos(D(-1)), EPS = 1e-10;

int sgn(D a) {
    if (abs(a) <= EPS) return 0;
    return (a < 0) ? -1 : 1;
}
int sgn(D a, D b) { return sgn(b-a); }
bool near(P a, P b) { return !sgn(abs(a-b)); }
D mabs(P p) { return abs(p.real()) + abs(p.imag()); }

bool lessP(P l, P r) {
    if (sgn(l.real(), r.real())) return l.real() < r.real();
    if (sgn(l.imag(), r.imag())) return l.imag() < r.imag();
    return false;
}

D cross(P a, P b) { return a.real()*b.imag() - a.imag()*b.real(); }
D dot(P a, P b) { return a.real()*b.real() + a.imag()*b.imag(); }
  
D deg2rad(D x) {
    return x/180*PI;
}
  
/* 1->cclock
  -1->clock
   0->on
   2->back
  -2->front
  */
int ccw(P b, P c) {
    int s = sgn(cross(b, c) / mabs(b));
    if (s) return s;
    if (!sgn(mabs(c)) || !sgn(mabs(c-b))) return 0;
    if (dot(b, c) < 0) return 2;
    if (dot(-b, c-b) < 0) return -2;
}
int ccw(P a, P b, P c) { return ccw(b-a, c-a); }
 
struct L {
    P s, t;
    L() {};
    L(P s, P t) :s(s), t(t) {};
};
 
P vec(const L &l) {
    return l.t - l.s;
}
 
D abs(const L &l) {
    return abs(vec(l));
}
 
 
bool insSS(const L &s, const L &t) {
    int a = ccw(s.s,s.t,t.s), b = ccw(s.s,s.t,t.t);
    int c = ccw(t.s,t.t,s.s), d = ccw(t.s,t.t,s.t);
    if (a*b <= 0 && c*d <= 0) return true;
    return false;
}
 
D distLP(const L &l, const P &p) {
    return abs(cross(vec(l), p-l.s)/abs(vec(l)));
}
 
D distSP(const L &s, const P &p) {
    P s2 = vec(s)*P(0, 1);
    if (ccw(s.s, s.s+s2, p) == 1) return abs(s.s-p);
    if (ccw(s.t, s.t+s2, p) == -1) return abs(s.t-p);
    return min(min(abs(s.s-p), abs(s.t-p)), distLP(s, p));
}
 
D distSS(const L &s, const L &t) {
    if (insSS(s, t)) return 0;
    return min(min(distSP(s, t.s), distSP(s, t.t)),
               min(distSP(t, s.s), distSP(t, s.t)));
}
 
const int MN = 110;
L sl[MN][5];
D g[MN][MN];
int main() {
    while (true) {
        int n, m, l;
        cin >> n >> m >> l; m--; l--;
        if (!n) break;
        for (int i = 0; i < n; i++) {
            D x, y, a, r;
            cin >> x >> y >> a >> r;
            P p[5];
            for (int j = 0; j < 5; j++) {
                D aa = a + 90+72*j;
                p[j] = P(x, y) + polar<D>(r, deg2rad(aa));
            }
            for (int j = 0; j < 5; j++) {
                sl[i][j] = L(p[j], p[(j+2)%5]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                D r = 1e9;
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < 5; l++) {
                        r = min(r, distSS(sl[i][k], sl[j][l]));
                    }
                }
                g[i][j] = g[j][i] = r;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
        printf("%.20lf\n", g[m][l]);
    }
    return 0;
}

