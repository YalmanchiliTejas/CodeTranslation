#include <bits/stdc++.h>
#include <cxxabi.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
#define rep(i,n) range(i,0,n)
#define range(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define LINF    ((ll)1ll<60)
#define INF     ((int)1<<30)
#define EPS     (1e-9)
#define MOD     (1000000007)
template<class S,class T>ostream& operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool b=1;for(auto s:t)os<<(exchange(b,0)||strlen(abi::__cxa_demangle(typeid(S).name(),0,0,0))>20?"":" ")<<s;return os<<endl;}
typedef double D;      // 座標値の型。doubleかlong doubleを想定
typedef complex<D> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define PI 3.14159265358

// 内積　dot(a,b) = |a||b|cosθ
D dot(P a, P b) {
  return (conj(a)*b).X;
}
// 外積　cross(a,b) = |a||b|sinθ
D cross(P a, P b) {
  return (conj(a)*b).Y;
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

/* 交差判定　直線・線分は縮退してはならない。接する場合は交差するとみなす。isecはintersectの略 */

// 直線と点
bool isecLP(P a1, P a2, P b) {
  return abs(ccw(a1, a2, b)) != 1;  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(P a1, P a2, P b1, P b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}

// 直線と線分
bool isecLS(P a1, P a2, P b1, P b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 線分と線分
bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(P a1, P a2, P b) {
  return !ccw(a1, a2, b);
}


/* 距離　各直線・線分は縮退してはならない */

// 点pの直線aへの射影点を返す
P proj(P a1, P a2, P p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
P reflection(P a1, P a2, P p) {
  return 2.0*proj(a1, a2, p) - p;
}

D distLP(P a1, P a2, P p) {
  return abs(proj(a1, a2, p) - p);
}

D distLL(P a1, P a2, P b1, P b2) {
  return isecLL(a1, a2, b1, b2) ? 0 : distLP(a1, a2, b1);
}

D distLS(P a1, P a2, P b1, P b2) {
  return isecLS(a1, a2, b1, b2) ? 0 : min(distLP(a1, a2, b1), distLP(a1, a2, b2));
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


vector<P> getStar(P c,double a,double r){
	const static P rot(cos(72*PI/180),sin(72*PI/180));
	vector<P> ret(5);
	ret[0]=c+P(0,r)*P(cos(a*PI/180),sin(a*PI/180));
	range(i,1,5){
		ret[i]=(ret[i-1]-c)*rot+c;
	}
	swap(ret[1],ret[2]);
	swap(ret[1],ret[4]);
	swap(ret[1],ret[3]);
	return ret;
}

double getDist(vector<P> &a,vector<P> &b){
	double r=1e8;
	rep(i,5)rep(j,5){
		r=min(r,distSS(a[i],a[(i+1)%5],b[j],b[(j+1)%5]));
	}
	return r;
}

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
	int n,m,l;
	while(cin>>n>>m>>l,n){
		vector<vector<P>> star(n);
		rep(i,n){
			double x,y,a,r;
			cin>>x>>y>>a>>r;
			star[i]=getStar(P(x,y),a,r);
		}
		
		vector<vector<double>> dist(n,vector<double>(n));
		rep(i,n)rep(j,n){
			dist[i][j]=getDist(star[i],star[j]);
		}
		rep(k,n)rep(i,n)rep(j,n)
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		cout<<setprecision(14)<<fixed<<dist[m-1][l-1]<<endl;	
	}
	return 0;
}

