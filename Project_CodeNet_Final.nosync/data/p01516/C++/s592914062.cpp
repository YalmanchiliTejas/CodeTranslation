#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<complex>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define pb(a) push_back(a)
const double EPS = 1e-8;
using namespace std;
const double INF = 1e12;
typedef complex<double> P;
namespace std{
	bool operator<(const P& a,const P& b){
		return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
	}
}
double cr(const P& a, const P& b){
	return imag(conj(a)*b);
}	
double dt(const P& a, const P& b){
	return real(conj(a)*b);
}
struct L : public vector<P>{
	L(const P &a,const P& b){
		pb(a);pb(b);
	}
};
typedef vector<P> G;

struct C{
	P p;double r;
	C(const P &p,double r) : p(p),r(r){}
};

int ccw(P a,P b,P c){
	b -= a;
	c -= a;
	if(cr(b,c) > EPS)return 1;
	if(cr(b,c)<-EPS)return -1;
	if(dt(b,c)<-EPS)return 2;
	if(norm(b)<norm(c) -EPS)return -2;
	return 0;
}
P pro(const L &l,const P &p){
	double t=dt(p-l[0],l[0]-l[1])/norm(l[0]-l[1]);
	return l[0]+t*(l[0]-l[1]);
}

bool itSP(const L &s, const P &p){
	return abs(s[0]-p)+abs(s[1]-p)-abs(s[0]-s[1]) < EPS;
}

bool itSS(const L &s, const L &t){
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
		ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

double dstSP(const L &s,const P &p){
	const P r = pro(s,p);
	if(itSP(s,r))return abs(r-p);
	return min(abs(s[0]-p),abs(s[1]-p));
}
double dstSS(const L &s,const L &t){
	if(itSS(s,t))return 0;
	return min(min(dstSP(s,t[0]),dstSP(s,t[1])),min(dstSP(t,s[0]),dstSP(t,s[1])));
}
#define rep(i,j) for(int i=0;i<j;i++)
vector<L> hoge(int x,int y,int r,int th_){
	double th=th_*1.*2*M_PI/360+M_PI/2;
	vector<P> ps(5);
	rep(i,5){
		double a=th+i*2*M_PI/5;
		ps[i].real()=x+r*cos(a);
		ps[i].imag()=y+r*sin(a);
	}
	vector<L> re;
	rep(i,5){
		re.pb(L(ps[i],ps[(i+2)%5]));
	}
	return re;
}
int main(){
	int n,m,l;
	while(cin >> n >> m >> l&&n){
	vector<vector<L> > st;
	rep(i,n){
		int x,y,a,r;
		cin >> x >> y >> a >> r;
		st.pb(hoge(x,y,r,a));
	}
	double dst[100][100];
	fill_n(dst[0],sizeof(dst)/sizeof(double),INF);
	rep(i,n){
		rep(j,n){
			double d = INF;
			vector<L> t = st[i];
			vector<L> u = st[j];
			rep(k,5){
				rep(kk,5){
					//cout <<"dst "<< dstSS(t[k],u[kk]) << endl;
					d = min(dstSS(t[k],u[kk]),d);
				}
			}
			//cout << endl;
			dst[i][j]=d;
		}
	}
	rep(k,n)rep(i,n)rep(j,n){
		dst[i][j] = min(dst[i][j],dst[i][k]+dst[k][j]);
	}
	cout <<fixed << setprecision(10)<< dst[m-1][l-1] << endl;
	}
	//vector<L> tt = hoge(5,5,5,0);
		
	//rep(i,5) cout << tt[i][0].real() << "," <<tt[i][0].imag() << endl;
	return 0;
}