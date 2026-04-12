#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
const double EPS = 1e-8;
const double INF = 1e12;
#define pb push_back



int N,M,LL;
double d[128][128];

typedef complex<double> P;
bool operator < (const P& a, const P& b){
	return  real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}

double cross(const P& a, const P& b){
	return imag(conj(a)*b);
}

double dot(const P& a, const P& b){
	return real(conj(a)*b);
}

struct L : public vector<P>{
	L(){}
	L(const P &a, const P &b){
		push_back(a);
		push_back(b);
	}
};

typedef vector<P> G;
struct C {
	P p;double r;
	C(const P &p, double r) : p(p), r(r) {}
};

int ccw(P a, P b, P c){
	b -= a;c -=a;
	if( cross(b,c)>0)return +1;
	if(cross(b,c) < 0) return -1;
	if(dot(b,c) < 0) return +2;
	if(norm(b) < norm(c)) return -2;
}

bool intersectLL(const L& l, const L& m){
	return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;
}

bool intersectSS(const L&s, const L &t){
	return ccw(s[0], s[1], t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0;
}

bool intersectSP(const L &s, const P &p){
	return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS;
}

P projection(const L &l, const P &p){
	double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
	return l[0] + t*(l[0]-l[1]);
}

double distanceLP(const L &l, const P& p){
	return abs(p - projection(l,p));
}

double distanceLL(const L &l, const L &m){
	return intersectLL(l,m) ? 0 : distanceLP(l, m[0]);
}

double distanceSP(const L&s, const P &p){
	const P r = projection(s,p);
	if(intersectSP(s,r)) return abs(r-p);
	return min(abs(s[0]-p), abs(s[1]-p));
}

double distanceSS(const L &s, const L &t){
	if(intersectSS(s,t)) return 0;
	return min(min(distanceSP(s,t[0]), distanceSP(s,t[1])),min(distanceSP(t,s[0]), distanceSP(t,s[1])));
}

double tod(double r){
	return M_PI * r / 180;
}

struct star{
	P p[5];
	L l[5];
	star(double x, double y, double a, double r){
		double n = 72;
		a+=90;
		rep(i,5){
			p[i] = P(x+r*cos(tod(a+n*i)), y+r*sin(tod(a+n*i)));
		}
		l[0] = L(p[0],p[2]);
		l[1] = L(p[0],p[3]);
		l[2] = L(p[1],p[3]);
		l[3] = L(p[1],p[4]);
		l[4] = L(p[2],p[4]);
	}
};


void init(){
	rep(i, 128)rep(j,128)d[i][j] = INF;
	rep(i,128)d[i][i]=0;
}
	


int main() {
	while(1){
		cin >> N >> M >> LL;
		if( N == 0) break;
		int x,y,a,r;
		M--;
		LL--;
		init();
		vector<star> stars;

		rep(i,N){
			cin >> x >> y >> a >> r;
			stars.pb(star(x,y,a,r));
		}

		
		rep(i,N)rep(j,N){
			rep(k,5)rep(kk,5){
				d[i][j] = min(d[i][j], distanceSS(stars[i].l[k], stars[j].l[kk]));
				d[j][i] = d[i][j];
			}
		}


		rep(k,N)rep(i,N)rep(j,N){
			d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
		}

	//	rep(i,5)rep(j,5)cout << i << "-" << j << "->" << d[i][j] << endl;
		cout << fixed << setprecision(10);
		cout << d[M][LL] << endl;
	}

	return 0;
}