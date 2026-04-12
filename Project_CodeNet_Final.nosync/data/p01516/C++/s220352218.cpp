#define NDEBUG
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;

typedef double R;
typedef complex<R> P;

namespace std {
    bool operator < (P a, P b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
    bool operator > (P a, P b) {
        return (b < a);
    }
}

const R EPS = 1e-10;
const R PI = acos((R)(-1));

/*
 -1 -> neg
  0 -> near 0
  1 -> pos
  */
int sgn(R a) {
    if (a < -EPS) return -1;
    if (a > EPS) return 1;
    return 0;
}

int sgn(R a, R b) {
    return sgn(b-a);
}

bool near(const P &a, const P &b) {
    return !sgn(abs(a-b));
}

//R cross(P a, P b) { return imag(conj(a)*b); }
R cross(P a, P b) { return a.real()*b.imag() - a.imag()*b.real(); }
R dot(P a, P b) { return a.real()*b.real() + a.imag()*b.imag(); }


R ssqrt(R d) {
    d = max<R>(0, d);
    return sqrt(d);
}

R sacos(R d) {
    d = max<R>(-1, d);
    d = min<R>(1, d);
    return acos(d);
}


R deg2rad(R x) {
    return x/180*PI;
}

//?§???????[0, 2*PI)???
R radNor(R x) {
    return fmod(fmod(x, 2*PI) + 2*PI, 2*PI);
}

/* 1->cclock
  -1->clock
   0->on
   2->back
  -2->front
  */
int ccw(P a, P b, P c) {
    assert(!near(a, b));
    if (near(a, c) || near(b, c)) return 0;
    int s = sgn(cross(b-a, c-a));
    if (s) return s;
    if (dot(b-a, c-a) < 0) return 2;
    if (dot(a-b, c-b) < 0) return -2;
    return 0;
}

struct L {
    P x, y;
    L() {};
    L(P x, P y) :x(x), y(y) {};
};

P vec(const L &l) {
    return l.y - l.x;
}

R abs(const L &l) {
    return abs(vec(l));
}


bool insSS(const L &s, const L &t) {
    int a = ccw(s.x,s.y,t.x), b = ccw(s.x,s.y,t.y);
    int c = ccw(t.x,t.y,s.x), d = ccw(t.x,t.y,s.y);
    if (a*b <= 0 && c*d <= 0) return true;
    return false;
}

R distLP(const L &l, const P &p) {
    return abs(cross(vec(l), p-l.x)/abs(vec(l)));
}

//????????¨??????????°??????¢
R distSP(const L &s, const P &p) {
    P s2 = vec(s)*P(0, 1);
    if (ccw(s.x, s.x+s2, p) == 1) return abs(s.x-p);
    if (ccw(s.y, s.y+s2, p) == -1) return abs(s.y-p);
    return min(min(abs(s.x-p), abs(s.y-p)), distLP(s, p));
}

//????????¨?????????????°??????¢
R distSS(const L &s, const L &t) {
    if (insSS(s, t)) return 0;
    return min(min(distSP(s, t.x), distSP(s, t.y)),
               min(distSP(t, s.x), distSP(t, s.y)));
}

const int MN = 110;
L sl[MN][5];
R g[MN][MN];
int main() {
    while (true) {
        int n, m, l;
        cin >> n >> m >> l; m--; l--;
        if (!n) break;
        for (int i = 0; i < n; i++) {
            R x, y, a, r;
            cin >> x >> y >> a >> r;
            P p[5];
            for (int j = 0; j < 5; j++) {
                R aa = a + 90+72*j;
                p[j] = P(x, y) + polar<R>(r, radNor(deg2rad(aa)));
            }
            for (int j = 0; j < 5; j++) {
                sl[i][j] = L(p[j], p[(j+2)%5]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                R r = 1e9;
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