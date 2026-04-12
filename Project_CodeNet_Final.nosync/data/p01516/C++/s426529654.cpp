#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <complex>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef long double ld;
typedef complex<ld> P;
typedef vector<P> VP;
const ld eps = 1e-9, pi = acos(ld(-1.0));

#define EQ(a,b) (abs((a)-(b))<eps)

ld dot (P a, P b) { return real(conj(a) * b); }
ld cross (P a, P b) { return imag(conj(a) * b); }

namespace std {
  bool operator<(const P &lhs, const P &rhs) {
    return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
  }
}

// Line
class L{
public:
  P a, b;
  L (P aa, P bb) { a = aa; b = bb; }
  L (ld ax, ld ay, ld bx, ld by) { a = P(ax, ay); b = P(bx, by); }
};

// counter clockwise
int ccw (P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > eps) return 1;   // counter clockwise
  if (cross(b, c) < -eps) return -1; // clockwise
  if (dot(b, c) < 0) return 2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line
  return 0;                          // a--c--b on line
}

// 点pから直線lに下ろした垂線の足
P proj(L l, P p) {
  ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + t * (l.a - l.b);
}

// 直線lと線分mが交点を持つか
bool isis_ss(L s, L t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
    ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

// 点pが線分s上に存在するか
bool isis_sp(L s, P p) {
  return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps;
}

// 線分sと点pの距離
ld dist_sp(L s, P p) {
  P r = proj(s, p);
  if (isis_sp(s, r)) return abs(r - p);
  return min(abs(s.a - p), abs(s.b - p));
}

// 線分sと線分tの距離
ld dist_ss(L s, L t) {
  if (isis_ss(s, t)) return 0;
  return min(min(dist_sp(s, t.a), dist_sp(s, t.b)), min(dist_sp(t, s.a), dist_sp(t, s.b)));
}

struct Star {
  vector<L> lines;
};

ld d(Star s1, Star s2) {
  ld mind = 1000000000.0;
  REP(i,5)REP(j,5){
    mind = min(mind,dist_ss(s1.lines[i],s2.lines[j]));
  }
  return mind;
}

int main() {
  while(1){
    int n,m,l;
    cin>>n>>m>>l;
    --m;--l;
    vector<Star> s;
    if(!n)break;
    REP(i,n){
      ld x,y,a,r;
      cin>>x>>y>>a>>r;
      P p = polar<ld>(r, a/180.0*pi+pi/2.0);
      P c(x,y);
      Star st;
      REP(j,5){
        st.lines.emplace_back(p*polar<ld>(1.0,2.0*j*pi/2.5)+c,p*polar<ld>(1.0,2.0*(j+1)*pi/2.5)+c);
      }
      s.push_back(st);
    }
    vector<vector<ld>> dist(n,vector<ld>(n));
    REP(i,n)REP(j,n){
      if(i==j){
        dist[i][j]=0.0;
      }else{
        dist[i][j] = d(s[i],s[j]);
      }
    }
    REP(k,n)REP(i,n)REP(j,n)
      dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    cout << setprecision(15) << fixed << dist[m][l] << endl;
  }
  return 0;
}