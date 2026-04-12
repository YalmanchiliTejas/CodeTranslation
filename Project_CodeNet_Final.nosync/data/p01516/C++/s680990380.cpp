#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, e) for(int i = (int)s; i < (int) e; i++)
#define rep(i, n) REP(i, 0 ,n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;

const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);
typedef complex<double> P;
namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
}
double dist2(const P& a, const P& b){
	P c (b - a);
	return dot(c, c);
}

struct L : public vector<P> {
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}

bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}
bool intersectSS(const L &s, const L &t) {
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
				 ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}
struct Edge{
	int to;
	double cost;
};
double d[110];

int main(){
	int n, start ,goal;
	while(cin>>n>>start>>goal && n && start && goal){
		start--;
		goal--;
		rep(i, 110) d[i] = 1e18;
		vector<vector<P>> p(n);
		rep(i, n){
			double x, y, a, r;
			cin>>x>>y>>a>>r;
			a = PI * a/180.0;
			rep(j, 5){
				P t(cos(a+2.0*PI * j / 5.0+PI/2)*r+x, sin(a+2.0*PI * j / 5.0+PI/2)*r+y);
				p[i].pb(t);
			}
		}
		vector<vector<L>> l(n);
		rep(i, n){
			rep(j, 5){
				int k = (j + 2) % 5;
				l[i].pb({p[i][j], p[i][k]});
			}
			rep(j, 5){
				int k = (j+1)%5;
				p[i].pb(crosspoint(l[i][j], l[i][k]));
			}
		}
		vector<vector<Edge>> es(n);
		rep(i, n) rep(j, i){
			bool f = false;
			rep(a, 5) rep(b, 5) if(intersectSS(l[i][a], l[j][b])) f = true;
			double dist = f ? 0.0 : 1e18;
			rep(a, 10) rep(b, 10) dist = min(dist, sqrt(dist2(p[i][a], p[j][b])));
			rep(a, 5) rep(b, 10) dist = min({dist, distanceSP(l[i][a], p[j][b]), distanceSP(l[j][a], p[i][b])});
			es[i].pb({j, dist});
			es[j].pb({i, dist});
		}
		d[start] = 0.0;
		typedef pair<double, int> PP;
		priority_queue<PP, vector<PP>, greater<PP>> q;
		q.push({0.0, start});
		while(!q.empty()){
			PP pp = q.top(); q.pop();
			int from = pp.se;
			double  c = pp.fi;
			for(auto& e : es[from]){
				int to = e.to;
				double cost = c + e.cost;
				if(d[to]>cost){
					d[to] = cost;
					q.push({cost, to});
				}
			}
		}
		printf("%.15lf\n", d[goal]);
	}
}