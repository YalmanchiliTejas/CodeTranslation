#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define REP(i, s, e) for ( int i = s; i <= e; i++ )  
 
const double INF = 1e12;
typedef complex<double> P,point;
 
std::istream& operator>>(std::istream& is,P& p)
{
	is >> p.real() >> p.imag();
	return is;
}
 
typedef vector<P> G,polygon;
namespace std {bool operator < (const P& a, const P& b) {return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);} }
double cross(const P& a, const P& b) {return imag(conj(a)*b);}
double dot(const P& a, const P& b) {return real(conj(a)*b);}
struct L : public vector<P> {L(const P &a, const P &b) {push_back(a); push_back(b);} };
struct C {P p; double r;C(const P &p, double r) : p(p), r(r) { } C(){} };
int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;
	if (cross(b, c) < 0)   return -1;
	if (dot(b, c) < 0) return +2;
	if (norm(b) < norm(c)) return -2;
	return 0;
}
 
// Check Funcs //
bool intersectLL(const L &l, const L &m) {return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;}
bool intersectLS(const L &l, const L &s) {return cross(l[1]-l[0], s[0]-l[0])*cross(l[1]-l[0], s[1]-l[0]) < EPS;}
bool intersectLP(const L &l, const P &p) {return abs(cross(l[1]-p, l[0]-p)) < EPS;}
bool intersectSS(const L &s, const L &t) {return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;}
bool intersectSP(const L &s, const P &p) {return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS;}
 
// Where is Point in Polygon? //
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
enum { OUT, ON, IN };
int contains(const polygon& P, const point& p) {
	bool in = false;
	for (int i = 0; i < P.size(); ++i) {
		point a = curr(P,i) - p, b = next(P,i) - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
			if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
	}
	return in ? IN : OUT;
}
// Area of Polygon //
double area2(const polygon& P) {
	double A = 0;
	for (int i = 0; i < P.size(); ++i)A += cross(curr(P, i), next(P, i));
	return A;
}
// Totsuhou! Andrew's Monotone Chain //
 
vector<point> convex_hull(vector<point> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<point> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}
 
P projection(const L &l, const P &p) {double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);return l[0] + t*(l[0]-l[1]);}
P reflection(const L &l, const P &p) {return p + 2.0 * (projection(l, p) - p);}
 
double distanceLP(const L &l, const P &p) {
	return abs(p - projection(l, p));
}
double distanceLL(const L &l, const L &m) {
	return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double distanceLS(const L &l, const L &s) {
	if (intersectLS(l, s)) return 0;
	return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP(const L &s, const P &p) {
	const P r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const L &s, const L &t) {
	if (intersectSS(s, t)) return 0;
	return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
 
P crosspoint(const L &l, const L &m) {
	double A = cross(l[1] - l[0], m[1] - m[0]);
	double B = cross(l[1] - l[0], l[1] - m[0]);
	if (abs(A) < EPS && abs(B) < EPS) return m[0];
	return m[0] + B / A * (m[1] - m[0]);
}
 
vector<P> C_cp(C a,C b){
	vector<P> ret;
	double L = abs(a.p-b.p);
 
	/* anma dekitenai */
	if(	L-a.r-b.r > EPS || (abs(a.p-b.p)<EPS && fabs(a.r-b.r)<EPS) || 
		abs(a.p-b.p) < abs(a.r-b.r)
	)return ret;
 
	double theta = atan2(b.p.imag()-a.p.imag(),b.p.real()-a.p.real());
	double c = (L*L+a.r*a.r-b.r*b.r)/(2*L*a.r);
	ret.push_back(
		P(a.p.real()+a.r*cos(theta+acos(c)),
		  a.p.imag()+a.r*sin(theta+acos(c)))
	);
	if(fabs(L-a.r-b.r) > EPS)
		ret.push_back(
			P(a.p.real()+a.r*cos(theta-acos(c)),
			  a.p.imag()+a.r*sin(theta-acos(c)))
		);
	return ret;
}
 
 
P getPedal(L l, P p){
	double A;
	if(abs(l[1].real()-l[0].real()) < EPS){
		return P(l[1].real(),p.imag()); // important
	}else{
		A = (l[1].imag()-l[0].imag())/(l[1].real()-l[0].real());
	}
	double a = -A , b = 1 , c = A*l[0].real() - l[0].imag();
	double t = (a*p.real() + b*p.imag() + c)/(a*a+b*b);
	return p-t * P(a,b);
}
 
vector<P> crosspointCL(const L l, const C c){
	vector<P> ret;
	P p = getPedal(l,c.p);
	if(	abs(p-c.p) > c.r+EPS)return ret;
	P e = P((l[1]-l[0])/abs(l[1]-l[0]));
	double S = sqrt(c.r*c.r-abs(p-c.p)*abs(p-c.p));
	ret.push_back(p+S*e);
	ret.push_back(p-S*e);
	return ret;
}
 
P getCircumcenter(P a,P b,P c){
	double A1 = 2 * ( b.real() - a.real() );
	double B1 = 2 * ( b.imag() - a.imag() );
	double C1 = pow(a.real(),2)-pow(b.real(),2) + pow(a.imag(),2)-pow(b.imag(),2);
	double A2 = 2 * ( c.real() - a.real() );
	double B2 = 2 * ( c.imag() - a.imag() );
	double C2 = pow(a.real(),2)-pow(c.real(),2) + pow(a.imag(),2)-pow(c.imag(),2);
	double X = (B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1);
	double Y = (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1);
	return P(X,Y);
}
 
double AreaOfPolygon(vector<P> p){
	double S = 0 ; 
	p.push_back(p[0]);
	/*　多角形の面積公式 (反時計回りの場合) */
	for(int i = 0 ; i < p.size()-1 ; i++){
		S += (p[i].real() - p[i+1].real()) * (p[i].imag()+p[i+1].imag());
	}
	S /= 2.0;
	return S;
}
vector<vector<L> > rect;

vector<C> c;
double seg(double y){
	L l = L(P(0,y),P(1,y));
	vector< pair<double,double> > segs;
	for(int i = 0 ; i < c.size() ; i++){
		vector<P> cp = crosspointCL(l,c[i]);
		if( cp.size() ){
			double a = cp[0].real(), b = cp[1].real();
			if( a > b ) swap(a,b);
			segs.push_back(mp(a,b));
		}
	}
	for(int i = 0 ; i < rect.size() ; i++){
		double mx = -1e9;
		double mi = 1e9;
		for(int j = 0 ; j < 4 ; j++){
			if( intersectLS(l,rect[i][j]) ){
				double x = crosspoint(rect[i][j],l).real();
				mx = max(mx,x);
				mi = min(mi,x);
			}
		}
		if( mi > mx ) continue;
		//cout << mi << " " << mx << endl;
		segs.push_back(mp(mi,mx));
	}
	vector< pair<double,double> > tmpseg;
	for(int i = 0 ; i < segs.size() ; i++){
		if( segs[i].second < -5 ) continue;
		if( segs[i].first > 5 ) continue;
		segs[i].first = max(-5.,segs[i].first);
		segs[i].second = min(5.,segs[i].second);
		tmpseg.push_back(segs[i]);
	}
	segs = tmpseg;
	
	if( segs.size() == 0 ) return 0.0;
	sort(segs.begin(),segs.end());
	double st = segs[0].first;
	double en = segs[0].second;
	double ans = 0;
	for(int i = 1 ; i < segs.size() ; i++){

		if( en < segs[i].first ){
			ans += en - st;
			st = segs[i].first;
			en = segs[i].second;
		}else{
			en = max(en,segs[i].second);
		}
	}
	ans += en - st;
	return ans;
}
int main(){
	int N;
	while(cin >> N && N){
		c.clear();
		rect.clear();
		for(int i = 0 ; i < N ; i++){
			P a,b;
			double r;
			cin >> a >> b >> r;
			P e = (b - a) / abs(b-a);
			e = P(-e.imag(),e.real());
			vector<L> ln;
			P A = a + e * r;
			P B = a - e * r;
			P C = b - e * r;
			P D = b + e * r;
			ln.push_back(L(A,B));
			ln.push_back(L(B,C));
			ln.push_back(L(C,D));
			ln.push_back(L(D,A));
			
			rect.push_back(ln);
			c.push_back(::C(a,r));
			c.push_back(::C(b,r));
		}
		double ans = 0;
		int D = 20000;
		//cout << seg(1.3) << endl;
		//return 0;
		for(int i = 0 ; i < D ; i++){
			double y = -5 + 10. * i / D;
			ans += seg(y) * (1./D);
		}
		printf("%.10lf%c",ans*10,10);
	}
}