#include<bits/stdc++.h>
using namespace std;

namespace Geometry{
    using namespace std;
    using ld=long double;
    using Point=complex<ld>;
    const ld PI=acos(-1);
    struct Line{
        Point a,b;
    };

    struct Circle{
        Point p;
        ld r;
    };
    const ld EPS=1e-8;
    inline bool EQ(Point a,Point b){return abs(a-b)<EPS;}
    ld dot(Point a,Point b){return real(a)*real(b)+imag(a)*imag(b);}
    ld cross(Point a,Point b){return real(a)*imag(b)-imag(a)*real(b);}

    const int CCW=1;
    const int CW=-1;
    const int BAC=2;
    const int ACB=-2;
    const int ABC=0;
    int ccw(Point a,Point b,Point c){
        b-=a,c-=a;
        if(cross(b,c)>EPS) return CCW; // counter clockwise
        if(cross(b,c)<-EPS) return CW; //clockwise
        if(dot(b,c)<-EPS) return BAC; //b-a-c
        if(abs(b)<abs(c)) return ACB; //a-c-b
        return ABC; //a-b-c (abs(b)>abs(c))
    }
    ld dist_lp(Line l,Point p){
        Point x=l.b-l.a;
        Point y=p-l.a;
        return abs(cross(x,y))/abs(x);
    }
    ld dist_sp(Line l,Point p){
        if(dot(p-l.a,l.b-l.a)<EPS) return abs(p-l.a);
        if(dot(p-l.b,l.a-l.b)<EPS) return abs(p-l.b);
        return dist_lp(l,p);
    }
    bool isis_ss(Line x,Line y){
        return ccw(x.a,x.b,y.a)*ccw(x.a,x.b,y.b)<=0 && ccw(y.a,y.b,x.a)*ccw(y.a,y.b,x.b)<=0;
    }
    ld dist_ss(Line x,Line y){
        if(isis_ss(x,y)) return 0;
        ld a=min(dist_sp(x,y.a),dist_sp(x,y.b));
        ld b=min(dist_sp(y,x.a),dist_sp(y,x.b));
        return min(a,b);
    }
}

using namespace Geometry;

ld solve(int n,int m,int l){
    vector<array<Line,5>> stars(n);
    for(int i=0;i<n;i++){
        ld x,y,a,r;
        cin>>x>>y>>a>>r;
        ld theta=(a+90.)/180.*PI;
        ld delta=ld(72)/180.*PI;
        for(int j=0;j<5;j++){
            Point p0={x+r*cos(theta+j*delta),y+r*sin(theta+j*delta)};
            Point p1={x+r*cos(theta+(j+2)*delta),y+r*sin(theta+(j+2)*delta)};
            stars[i][j]=Line{p0,p1};
        }
    }
    const ld INF=1e18;
    vector<vector<ld>> dist(n,vector<ld>(n,INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                dist[i][j]=0;
                continue;
            }
            for(int ki=0;ki<5;ki++){
                for(int kj=0;kj<5;kj++){
                    dist[i][j]=min(dist[i][j],dist_ss(stars[i][ki],stars[j][kj]));
                }
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    return dist[m][l];
}
int main(){
    int n,m,l;
    cout<<setprecision(10)<<fixed;
    while(cin>>n>>m>>l,n){
        m--,l--;
        cout<<solve(n,m,l)<<endl;
    }
    return 0;
}
