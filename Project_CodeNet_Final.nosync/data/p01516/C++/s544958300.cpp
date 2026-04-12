#include <iostream>
#include <cmath>
using namespace std;

#define rep(i,x) for(int i = 0 ; i < x ; i ++)
#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)

typedef long double ld;
const ld PI = 3.141592653589793238462643383279;

struct po{
	ld x;
	ld y;
	po(ld a){ x = a; y = 0; }
	po(ld a,ld b){ x = a; y = b; }
	po(){}
	inline ld operator()(const po& rhs) const {
		return x*rhs.x+y*rhs.y;
	}
	inline ld norm() {
		return sqrt((*this)(*this));
	}
	inline po& operator+=(const po& rhs){
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	inline po& operator-=(const po& rhs){
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	inline po& operator*=(const po& rhs){
		ld x_ = x*rhs.x-y*rhs.y;
		y = x*rhs.y+y*rhs.x;
		x = x_;
		return *this;
	}
	inline po& operator/=(const po& rhs){
		ld x_ = x*rhs.x+y*rhs.y;
		y = -x*rhs.y+y*rhs.x;
		x = x_;
		ld nor = rhs(rhs);
		x /= nor;
		y /= nor;
		return *this;
	}
	inline void in(){
		scanf("%Lf%Lf",&x,&y);
	}
};
inline po operator+(const po& a, const po& b){ return po(a) += b; }
inline po operator-(const po& a, const po& b){ return po(a) -= b; }
inline po operator*(const po& a, const po& b){ return po(a) *= b; }
inline po operator/(const po& a, const po& b){ return po(a) /= b; }

inline po similar(const po& a,const po& b,const po& c,const po& p,const po& q){
	return p+(q-p)*(c-a)/(b-a);
}

typedef pair<po,po> se;
#define fr first
#define sc second

struct li{
	ld a;
	ld b;
	ld c;
	li(po p,po q){
		a = q.y-p.y;
		b = p.x-q.x;
		c = p.y*q.x-p.x*q.y;
	}
	/*explicit li(se s){
		a = s.sc.y-s.fr.y;
		b = s.fr.x-s.sc.x;
		c = s.fr.y*s.sc.x-s.fr.x*s.sc.y;
		li(s.fr,s.sc);
	}*/
	li(){}
	inline ld operator()(const po& p) const {
		return a*p.x+b*p.y+c;
	}
};

void intersect(const li &l,const li &m,po* &ret){
	if(abs(l.a*m.b-m.a*l.b) <= 1e-18){
		ret = nullptr;
		return;
	}
	ret = new po;
	ret->x = -(l.c*m.b-m.c*l.b)/(l.a*m.b-m.a*l.b);
	ret->y = -(l.a*m.c-m.a*l.c)/(l.a*m.b-m.a*l.b);
}

inline bool on(const po &p,const se &s){
	return (s.fr-p)(s.sc-p) <= 1e-9;
}

void intersect(const se &s,const se &t,po* &ret){
	li l = li(s.fr,s.sc);
	li m = li(t.fr,t.sc);
	po *p;
	intersect(l,m,p);
	if(p == nullptr || (on(*p,s)&&on(*p,t)))ret = p;
	else{
		delete p;
		ret = nullptr;
	}
}

inline ld dist(const po &p,const po &q){
	return sqrt((p-q)(p-q));
}
inline li perpen(const po &p,const li &l){
	li ret;
	ret.a = l.b;
	ret.b = -l.a;
	ret.c = l.a*p.y-l.b*p.x;
	return ret;
}
inline po perpen_leg(const po &p,const li &l){
	po ret;
	li m = perpen(p,l);
	ret.x = -(l.c*m.b-m.c*l.b)/(l.a*m.b-m.a*l.b);
	ret.y = -(l.a*m.c-m.a*l.c)/(l.a*m.b-m.a*l.b);
	return ret;
}
inline ld dist(const po &p,const se &s){
	po h = perpen_leg(p,li(s.fr,s.sc));
	if(on(h,s))return dist(p,h);
	else return min( dist(p,s.fr) , dist(p,s.sc) );
}
inline ld dist(const se &s,const se &t){
	po *p;
	intersect(s,t,p);
	if(p != nullptr){
		delete p;
		return 0.0;
	}
	ld ret = min( dist(s.fr,t) , dist(s.sc,t) );
	ret = min( ret , min( dist(t.fr,s) , dist(t.sc,s) ) );
	return ret;
}

int main(){
	int n,m,l;
	while(1){
		scanf("%d%d%d",&n,&m,&l);
		if(n == 0)break;
		static ld d[102][102];
		static po p[102];
		static ld a[102],r[102];
		rep1(i,n){
			p[i].in();
			scanf("%Lf%Lf",&a[i],&r[i]);
		}
		static po ver[102][5];
		rep1(i,n){
			rep(j,5){
				ver[i][j] = p[i]+r[i]*po(cos(2.0*PI*(72.0*2*j+a[i]+90.0)/360.0),sin(2.0*PI*(72.0*2*j+a[i]+90.0)/360.0));
			}
		}
		rep1(i,n)rep1(j,n){
			if(i == j){
				d[i][j] = 0.0;
				continue;
			}
			d[i][j] = 10000.0;
			rep(k,5)rep(h,5)d[i][j] = min( d[i][j] , dist(se(ver[i][k],ver[i][(k+1)%5]),se(ver[j][h],ver[j][(h+1)%5])) );
		}
		rep1(k,n)rep1(i,n)rep1(j,n)d[i][j] = min( d[i][j] , d[i][k]+d[k][j] );
		printf("%.20lf\n",(double)d[m][l]);
	}
}

