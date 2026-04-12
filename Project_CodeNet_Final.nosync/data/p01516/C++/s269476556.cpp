#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

inline double add(double a, double b){
    return abs(a+b)<(1e-10)*(abs(a)+abs(b)) ? 0.0 : a+b;
}

struct vec{
    double x,y;
    vec(){}
    vec(double x, double y){
        this->x=x; this->y=y;
    }
    vec operator-(vec b){
        return (vec){add(x,-b.x),add(y,-b.y)};
    }
    vec operator+(vec b){
        return (vec){add(x,b.x),add(y,b.y)};
    }
    vec operator*(double d){
        return (vec){x*d,y*d};
    }
    double dot(vec v){
        return add(x*v.x,y*v.y);
    }
    double cross(vec v){
        return add(x*v.y,-y*v.x);
    }
    double norm(){
        return sqrt(x*x+y*y);
    }
};

const double eps = 0.0000001;

int ccw(vec& a, vec& b, vec& c){
    vec ab = b-a, ac = c-a;
    double o = ab.cross(ac);
    if(o>0) return 1; //CCW
    if(o<0) return -1; //CW
    if(ab.dot(ac)<0){
        return 2; //C-A-B
    }else{
        if(ab.dot(ab)<ac.dot(ac)){
            return -2; //A-B-C
        }else{
            return 0; //A-C-B
        }
    }
}

bool isInterSection(vec (&p)[4]){
    switch(ccw(p[0],p[1],p[2])*ccw(p[0],p[1],p[3])){
        case -1:
        case -4:
        case 0:
            break;
        default:
            return false;
    }
    switch(ccw(p[2],p[3],p[0])*ccw(p[2],p[3],p[1])){
        case -1:
        case -4:
        case 0:
            break;
        default:
            return false;
    }
   return true;
}

vec interSection(vec (&p)[4]){
    vec p23=p[3]-p[2],p02=p[2]-p[0],p01=p[1]-p[0];
    double k = p23.cross(p02)/p23.cross(p01);
    return p[0]+p01*k;
}

double dist(vec (&p)[4]){
    if(isInterSection(p)) return 0;
    double dist =1e5;
    vec P;
    P=p[0]+(p[1]-p[0])*((p[1]-p[0]).dot(p[2]-p[0])/(p[1]-p[0]).dot(p[1]-p[0]));
    if(!ccw(p[0],p[1],P)){
        dist = min(dist,(P-p[2]).norm());
    }
    P=p[0]+(p[1]-p[0])*((p[1]-p[0]).dot(p[3]-p[0])/(p[1]-p[0]).dot(p[1]-p[0]));
    if(!ccw(p[0],p[1],P)){
        dist = min(dist,(P-p[3]).norm());
    }
    P=p[2]+(p[3]-p[2])*((p[3]-p[2]).dot(p[0]-p[2])/(p[3]-p[2]).dot(p[3]-p[2]));
    if(!ccw(p[2],p[3],P)){
        dist = min(dist,(P-p[0]).norm());
    }
    P=p[2]+(p[3]-p[2])*((p[3]-p[2]).dot(p[1]-p[2])/(p[3]-p[2]).dot(p[3]-p[2]));
    if(!ccw(p[2],p[3],P)){
        dist = min(dist,(P-p[1]).norm());
    }
    dist = min(dist,(p[2]-p[0]).norm());
    dist = min(dist,(p[2]-p[1]).norm());
    dist = min(dist,(p[3]-p[0]).norm());
    dist = min(dist,(p[3]-p[1]).norm());
    return dist;
}

typedef vector<vec> star;

double dist(star& a, star& b){
    vec p[4];
    double d=1e8;
    for(int i=0;i<5;i++){
        p[0]=a[i];
        p[1]=a[(i+2)%5];
        for(int j=0;j<5;j++){
            p[2]=b[j];
            p[3]=b[(j+2)%5];
            d=min(d,dist(p));
        }
    }
    return d;
}

vector<star> S;
typedef pair<double,int> P;
double D[100][100];

int main(){
    int N,M,L;
    while(cin>>N>>M>>L,N){
        S.clear();
        M--;L--;
        for(int i=0;i<N;i++){
            S.emplace_back();
            star& s=S.back();
            int x,y,a,r;
            cin>>x>>y>>a>>r;
            for(int i=0;i<5;i++){
                double Px,Py;
                Px=x+r*cos((90+a+72*i)/180.0*M_PI);
                Py=y+r*sin((90+a+72*i)/180.0*M_PI);
                s.emplace_back(Px,Py);
            }
        }
        fill(D[0],D[100],1e8);
        for(int i=0;i<N;i++){
            D[i][i]=0;
            for(int j=i+1;j<N;j++){
                D[i][j]=D[j][i]=dist(S[i],S[j]);
            }
        }
        priority_queue<P,vector<P>,greater<P>> que;//cost,to
        double minimum[100];
        fill(minimum,minimum+100,1e8);
        que.emplace(0,M);
        while(!que.empty()){
            P p=que.top();que.pop();
            double cost=p.first;
            int v=p.second;
            if(cost>minimum[v])continue;
            if(v==L){
                cout.precision(10);
                cout<<fixed;
                cout<<cost<<endl;
                break;
            }
            for(int i=0;i<N;i++){
                if(minimum[i]>cost+D[v][i]){
                    minimum[i]=cost+D[v][i];
                    que.emplace(minimum[i],i);
                }
            }
        }
    }
}