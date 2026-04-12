#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define eb emplace_back

int in(){int x;cin>>x;return x;}

using Real = double;
using Point = complex<Real>;
const Real EPS = 1e-8,PI = acos(-1);
inline bool eq(Real a,Real b){ return fabs(b-a) < EPS;}
Point rotate(Real _theta,const Point &p){
    Real theta = (_theta*PI/180);
    return Point(cos(theta)*p.real()-sin(theta)*p.imag(),sin(theta)*p.real()+cos(theta)*p.imag());
}
struct Segment {
    Point a,b;
    Segment()=default;
    Segment(Point a,Point b):a(a),b(b){}
};
Real dot(const Point &a,const Point &b){
    return real(a)*real(b)+imag(a)*imag(b);
}

Point projection(const Segment &l,const Point &p){
    double t = dot(p-l.a,l.a-l.b)/norm(l.a-l.b);
    return l.a+(l.a-l.b)*t;
}
Real cross(const Point &a, const Point &b) {
    return real(a) * imag(b) - imag(a) * real(b);
}
int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return +1;  
    if(cross(b, c) < -EPS) return -1;
    if(dot(b, c) < 0) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}
bool intersect(const Segment &s,const Point &p){
    return ccw(s.a,s.b,p) == 0;
}
bool intersect(const Segment &s, const Segment &t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
Real distance(const Segment &s,const Point &p){
    Point r = projection(s,p);
    if(intersect(s,r)) return abs(r-p);
    return min(abs(s.a-p),abs(s.b-p));
}
Real distance(const Segment &a, const Segment &b) {
    if(intersect(a, b)) return 0;
    return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}
struct Star{
    Point center;
    Real r;
    Real theta;
    Point p[5];
    Segment s[5];
    Star(int x,int y,int a,int r):r(r),theta(a){
        center=Point(x,y);
        rep(i,5){
            Point P(0,r);
            P = rotate(a+72*i,P);
            p[i] = Point(center+P);
        }
        rep(i,5){
            s[i] = Segment(p[i],p[(i+2)%5]);
        }
    }
};
Real distance(Star &x,Star &y){
    Real d = 1e10;
    rep(i,5){
        rep(j,5){
            d = min(d,distance(x.s[i],y.s[j]));
        }
    }
    return d;
}
    

main(){
    while(1){
        int n=in(),m=in(),l=in();
        if(!n)exit(0);
        vector<Star> v;
        rep(i,n){
            int x=in(),y=in(),a=in(),r=in();
            v.emplace_back(x,y,a,r);
        }
        Real mat[n][n];
        rep(i,n){
            rep(j,n){
                if(i==j)mat[i][j]=0;
                else mat[i][j] = distance(v[i],v[j]);
            }
        }
        rep(k,n){
            rep(i,n){
                rep(j,n){
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        cout << setprecision(15) << fixed << mat[m-1][l-1] << endl;
    }
}
