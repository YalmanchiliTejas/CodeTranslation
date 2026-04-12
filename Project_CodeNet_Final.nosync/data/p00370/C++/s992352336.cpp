#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

typedef double D;
typedef complex<D>Point;
typedef vector<Point>Polygon;

const D EPS=1e-5;

const int COUNTER_CLOCKWISE=1;
const int CLOCKWISE=-1;
const int ONLINE_FRONT=2;
const int ONLINE_BACK=-2;
const int ON_SEGMENT=0;

struct Segment{
    Point p1,p2;
    Segment(const Point &p1=Point(),const Point &p2=Point()):p1(p1),p2(p2){}
};

istream& operator>>(istream &is,Point &a){
    D x,y;
    is>>x>>y;
    a=Point(x,y);
    return is;
}

D dot(const Point &a,const Point &b){
    return real(a)*real(b)+imag(a)*imag(b);
}
D cross(const Point &a,const Point &b){
    return real(a)*imag(b)-real(b)*imag(a);
}

Point projection(const Point &a,const Point &b){
    return a*real(b/a);
}

Point projection(const Segment &s,const Point &a){
    return s.p1+projection(s.p2-s.p1,a-s.p1);
}

Point reflection(const Segment &s,const Point &a){
    Point p=projection(s,a);
    return 2.0*p-a;
}

int ccw(Point a,Point b,Point c){
    b-=a;c-=a;
    if(cross(b,c)>EPS)return COUNTER_CLOCKWISE;
    if(cross(b,c)<-EPS)return CLOCKWISE;
    if(dot(b,c)<-EPS)return ONLINE_BACK;
    if(norm(b)+EPS<norm(c))return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(const Point &a1,const Point a2,const Point &b1,const Point &b2){
    return ccw(a1,a2,b1)*ccw(a1,a2,b2)<=0&&
    ccw(b1,b2,a1)*ccw(b1,b2,a2)<=0;
}

signed main(){
    Point A,B;
    cin>>A>>B;

    int N;cin>>N;
    Polygon G(N);
    rep(i,N)cin>>G[i];

    double ans=1e18;

        rep(i,N){
            if(ccw(G[i],G[(i+1)%N],A)==CLOCKWISE&&ccw(G[i],G[(i+1)%N],B)==CLOCKWISE){
                Point p=reflection(Segment(G[i],G[(i+1)%N]),B);
                if(intersect(G[i],G[(i+1)%N],A,p))chmin(ans,abs(p-A));
            }
        }

        vint okA(N),okB(N);
        rep(i,N){
            if(ccw(G[(i-1+N)%N],G[i],A)!=COUNTER_CLOCKWISE||ccw(G[i],G[(i+1)%N],A)!=COUNTER_CLOCKWISE)okA[i]=true;
            if(ccw(G[(i-1+N)%N],G[i],B)!=COUNTER_CLOCKWISE||ccw(G[i],G[(i+1)%N],B)!=COUNTER_CLOCKWISE)okB[i]=true;
        }

        rep(i,N){
            if(!okA[i])continue;
            rep(j,N){
                if(!okB[j])continue;
                double tmp=abs(G[i]-A)+abs(G[j]-B);
                int v=i;
                while(v!=j){
                    tmp+=abs(G[v]-G[(v+1)%N]);
                    v=(v+1)%N;
                }
                chmin(ans,tmp);


                tmp=abs(G[i]-A)+abs(G[j]-B);
                v=i;
                while(v!=j){
                    tmp+=abs(G[v]-G[(v-1+N)%N]);
                    v=(v-1+N)%N;
                }
                chmin(ans,tmp);
            }
        }



    printf("%.20f\n",ans);
    return 0;
}