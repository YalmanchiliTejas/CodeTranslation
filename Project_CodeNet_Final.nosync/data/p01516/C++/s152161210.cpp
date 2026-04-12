#include<bits/stdc++.h>
typedef double D;      // 座標値の型。doubleかlong doubleを想定
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)

typedef complex<D> P;  // Point
typedef vector<P> VP;
const D EPS = 1e-9;    // 許容誤差。問題によって変える
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
static const double pi = 3.141592653589793;
// 内積　dot(a,b) = |a||b|cosθ
D dot(P a, P b) {
  return (conj(a)*b).X;
}
// 外積　cross(a,b) = |a||b|sinθ
D cross(P a, P b) {
  return (conj(a)*b).Y;
}

P rotateP(P a, P o ,D arg) { //点aを点oを中心に反時計周りにまわした複素数を返す。
	a -= o;
	a *= P(cos(arg / 180 * pi), sin(arg / 180 * pi));
	a += o;
	return a;
}
// 点の進行方向
int ccw(P a, P b, P c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}


P proj(P a1, P a2, P p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}
bool isecSP(P a1, P a2, P b) {
  return !ccw(a1, a2, b);
}
D distSP(P a1, P a2, P p) {
  P r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  return min(abs(a1-p), abs(a2-p));
}

D distSS(P a1, P a2, P b1, P b2) {
  if (isecSS(a1, a2, b1, b2)) return 0;
  return min(min(distSP(a1, a2, b1), distSP(a1, a2, b2)),
             min(distSP(b1, b2, a1), distSP(b1, b2, a2)));
}
////////////////

int N,M,L;
int x,y,a,r;

D ds(array<P, 5> a, array<P, 5> b) {
	D res = 1e30;
	rep(i, 5) {
		rep(j, 5) {
			res = min(res,distSS(a[i] , a[(i + 1) % 5], b[j], b[(j+ 1) % 5]));
		}
	}
	return res;
}
				

int main() {
	while(cin >> N >> M >> L, N) {
		vector<array<P, 5> > stars;
		M --; L--;
		for(int n = 1; n <= N; n++) {
			cin >> x >> y >> a >> r;
			P p0, p1, p2, p3, p4, p5;
			p0 = P(x, y);
			p1 = p0 + P(0, r);
			p1 = rotateP(p1, p0, a);
			p2 = rotateP(p1, p0, 144);
			p3 = rotateP(p2, p0, 144);
			p4 = rotateP(p3, p0, 144);
			p5 = rotateP(p4, p0, 144);
			stars.push_back({p1,p2,p3,p4,p5});
		}
		
		double table[110][110];
		for(int n = 0; n < N; n++) {
			for(int i = 0; i < N; i++) {
				if(i == n) {
					table[i][n] = 0;
				} else {
					table[i][n] = ds(stars[i], stars[n]);
					table[n][i] = table[i][n];
				}
			}
		}
		rep(k, N) {
			rep(i, N){
				rep(j, N){
					table[i][j] = min(table[i][j],table[i][k] + table[k][j]);
				}
			}
		}
		cout << setprecision(20) << table[M][L] << endl;
	}
}
	



