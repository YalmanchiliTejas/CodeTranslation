#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF (1e9+1)
#define dINF (1LL<<59)
//#define INF (1LL<<59)

#define OUT 0
#define ON 1
#define IN 2
#define EPS (1e-10)
class P{                    //テァツつケ
public:
    double x,y;
    
    P(double _x=0,double _y=0):x(_x),y(_y){};
    P operator + (const P &p     )const{ return P( x+p.x , y+p.y ); }  //テ・ツ環?ァツョツ?
    P operator - (const P &p     )const{ return P( x-p.x , y-p.y ); }  //テヲツクツ崚ァツョツ?
    P operator * (const double k )const{ return P( x*k   , y*k    ); } //テ、ツケツ療ァツョツ?
    P operator / (const double k )const{ return P( x/k   , y/k    ); } //テゥツ卍、テァツョツ?
    
    bool operator == (const P &p){ return ( fabs(x-p.x)<EPS && fabs(y-p.y)<EPS ); }
    bool operator < (const P &p) const{ return ( x!=p.x ? x<p.x:y<p.y ); }
    
    double norm(){ return x*x+y*y; }        //テ」ツδ偲」ツδォテ」ツδ?
    double abs() { return sqrt(norm()); }   //テ・ツ、ツァテ」ツ?催」ツ??
    void normalize() {double d = sqrt(x*x+y*y); x /= d; y /= d;}	//テヲツュツ」ティツヲツ湘・ツ個?
};
struct C{P p;double r;};    //テ・ツ??
struct S{P p1,p2;};         //テァツキツ堙・ツ按?
typedef vector<P> Polygon;  //テ・ツ、ツ堙ィツァツ津・ツスツ「
typedef P Vector;           //テ」ツδ凖」ツつッテ」ツδ暗」ツδォ
typedef S L;                //テァツ崢エテァツキツ?

double norm (P p)               { return p.norm(); }
double abs  (P p)               { return p.abs(); }
double dot  (Vector a,Vector b) { return a.x*b.x+a.y*b.y; }
double cross(Vector a,Vector b) { return a.x*b.y-a.y*b.x; }
double sqDist(P a, P b)         {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
double dist (P a, P b)          {return sqrt(sqDist(a,b));}
Vector vec(S a)                 {return P(a.p2.x-a.p1.x,a.p2.y-a.p1.y);}

int ccw(P p0,P p1,P p2){    //AOJ_BOOK_P386 verified
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    
    if( cross(a,b) > EPS  ) return 1 ;      //COUNTER_CLOCKWISE
    if( cross(a,b) < -EPS ) return -1;      //CLOCKWISE
    if( dot(a,b)   < -EPS ) return 2;       //ONLINE_BACK
    if( a.norm()   < b.norm() ) return -2;  //ONLINE_FRONT
    
    return 0;                               //ON_SEGMENT;
}

//テァツキツ堙・ツ按?、ツコツ、テ・ツキツョテ・ツ按、テ・ツョツ?
bool intersect(P p1,P p2,P p3,P p4){ return ( ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 && ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0 ); }


struct star{
    vector<P> ep;
    vector<S> ss;
};


double toRad( int a ){
    return a*3.14159265358/180.0;
}

vector<P> getEp(int x,int y,int a,int r){
    vector<P> ret;
    
    int theta = a;
    rep(i,5){
        double xx = x, yy = y;
        xx -= r*sin(toRad(a));
        yy += r*cos(toRad(a));
        
        ret.pb({xx,yy});
        
        a+=72;
    }
    return ret;
}

bool isCross(star a,star b){
    rep(i,5){
        rep(j,5){
            if( intersect(a.ss[i].p1, a.ss[i].p2, b.ss[j].p1, b.ss[j].p2) ){
                return true;
            }
        }
    }
    return false;
}

//テァツキツ堙・ツ按?」ツ?ィテァツつケテ」ツ?ョティツキツ敕ゥツ崢「 verified ARC042-B
double dLP(S l, P p) { return abs(cross(l.p2-l.p1, p-l.p1)) /(l.p2-l.p1).abs(); }

//テァツキツ堙・ツ按?」ツ?ィテァツつケテ」ツ?ョティツキツ敕ゥツ崢「 verified QUPC-G
double dSP(S s, P p){
    if(dot((s.p2-s.p1)   , p-s.p1) <= EPS) return (p - s.p1).abs();
    if(dot((s.p2-s.p1)*-1, p-s.p2) <= EPS) return (p - s.p2).abs();
    return dLP(s, p);
}

double dSS(S s, S t){return  min({dSP(s, t.p1), dSP(s, t.p2), dSP(t, s.p1), dSP(t, s.p2)});}


double getMinDist(star a,star b){
    vector<S> c = a.ss, d = b.ss;
    double ret = dINF;
    rep(i,c.size()){
        rep(j,d.size()){
            double res = dSS(c[i],d[j]);
            ret = min(ret,res);
        }
    }
    return ret;
}

int main(){
    int v,s,g;
    while(cin>>v>>s>>g&&(v||s||g)){
        s--,g--;
        vector<star> vs;
        rep(i,v){
            int x,y,a,r;
            cin>>x>>y>>a>>r;
            vector<P> tp = getEp(x,y,a,r);
            assert(tp.size()==5);
            vector<S> ts;
            rep(i,tp.size()){
                int d1 = (i+2)%5, d2 = (i+3)%5;
                if(i<d1)ts.pb(S{tp[i],tp[d1]});
                if(i<d2)ts.pb(S{tp[i],tp[d2]});
            }
            assert(ts.size()==5);
            vs.pb(star{tp,ts});
        }
        
        double d[101][101];
        rep(i,101)rep(j,101)d[i][j] = dINF;
        rep(i,101)d[i][i] = 0.0;
        
        
        rep(i,vs.size()){
            rep(j,vs.size()){
                if(i==j)continue;
                if(isCross(vs[i],vs[j])){
                    d[i][j]=0.0;
                    continue;
                }else{
                    double res = getMinDist(vs[i],vs[j]);
                    d[i][j] = res;
                }
            }
        }
        rep(k,v){
            rep(i,v){
                rep(j,v){
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        
        printf("%.20lf\n",d[s][g]);
    }
}