#include<cmath>
#include<cstdio>
#include<algorithm>
 
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;
 
const double INF=1e77;
const double EPS=1e-8;
const double PI=acos(-1);
 
template<class T>
struct point{
    T x,y;
    point operator+(const point &a)const{ point t = {x+a.x,y+a.y}; return t; }
    point operator-(const point &a)const{ point t = {x-a.x,y-a.y}; return t; }
};
 
template<class T>
point<T> operator*(T c,const point<T> &a){
	point<T> p = {c*a.x,c*a.y};
    return p;
}
 
point<double> rot(const point<double> &a,double theta){
	point<double> p = {a.x*cos(theta)-a.y*sin(theta),a.x*sin(theta)+a.y*cos(theta)};
	return p;
}
 
template<class T>
struct segment{
    point<T> a,b;
};
 
struct star{
    point<double> c;
    double a,r;
    point<double> p[5];
};
 
template<class T>
T dot(const point<T> &a,const point<T> &b){ return a.x*b.x+a.y*b.y; }
 
template<class T>
T cross(const point<T> &a,const point<T> &b){ return a.x*b.y-a.y*b.x; }
 
enum{CCW=1,CW=-1,ON=0};
int ccw(const point<double> &a,const point<double> &b,const point<double> &c){
    double rdir=cross(b-a,c-a);
    if(rdir> EPS) return CCW;
    if(rdir<-EPS) return CW;
    return ON;
}
 
bool intersect(const segment<double> &S1,const segment<double> &S2){
    if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
    || max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
    || max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
    || max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
    return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
        && ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}
 
template<class T>
T dist2(const point<T> &a,const point<T> &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
 
template<class T>
double dist2(const segment<T> &S,const point<T> &p){
    if(dot(S.b-S.a,p-S.a)<=0) return dist2(p,S.a);
    if(dot(S.a-S.b,p-S.b)<=0) return dist2(p,S.b);
    return (double)cross(S.b-S.a,p-S.a)*cross(S.b-S.a,p-S.a)/dist2(S.a,S.b);
}
 
template<class T>
double dist(const segment<T> &S1,const segment<T> &S2){
    if(intersect(S1,S2)) return 0;
    return sqrt(min(min(dist2(S1,S2.a),dist2(S1,S2.b)),
                    min(dist2(S2,S1.a),dist2(S2,S1.b))));
}
 
int main(){
    for(int n,m,l;scanf("%d%d%d",&n,&m,&l),n||m||l;){
        m--;
        l--;
 
        star S[100];
        rep(i,n){
            scanf("%lf%lf%lf%lf",&S[i].c.x,&S[i].c.y,&S[i].a,&S[i].r);
        }
 
        rep(i,n){
            S[i].p[0].x = 0, S[i].p[0].y = S[i].r;
            S[i].p[0]=rot(S[i].p[0],S[i].a/180*PI);
            for(int j=1;j<5;j++){
                S[i].p[j]=rot(S[i].p[j-1],2*PI/5);
            }
            rep(j,5) S[i].p[j]=S[i].p[j]+S[i].c;
        }
 
        int f1[]={0,2,4,1,3,0};
 
        double d[100][100];
        rep(i,n){
			rep(j,n) {
            d[i][j]=INF;
            rep(a,5) rep(b,5){
				segment<double> s = {S[i].p[f1[a]],S[i].p[f1[a+1]]};
				segment<double> t = {S[j].p[f1[b]],S[j].p[f1[b+1]]};
				d[i][j]=min(d[i][j],dist(s,t));
			}
			}
        }
 
        rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
 
        printf("%.15f\n",d[m][l]);
    }
 
    return 0;
}