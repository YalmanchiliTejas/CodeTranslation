#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

const double eps=1e-10;
double add(double a,double b){
    if(abs(a+b)<eps*(abs(a)+abs(b)))return 0;
    return a+b;
}

typedef pair<double,double> P;
P operator+(const P& x,const P& y){
    return {add(x.first,y.first),add(x.second,y.second)};
}

P operator-(const P& x,const P& y){
    return {add(x.first,-y.first),add(x.second,-y.second)};

}

P operator*(const P& x,const double& y){
    return {x.first*y,x.second*y};
}
double dot(P x,P y){
    return add(x.first*y.first,x.second*y.second);


}

double det(P x,P y){
    return add(x.first*y.second,-x.second*y.first);
}

bool onseg(P p1,P p2,P q){
    return det(p1-q,p2-q)==0 &&dot(p1-q,p2-q)<=0; 
}

P intersection(P p1,P p2,P q1,P q2){
    return p1+(p2-p1)*(det(q2-q1,q1-p1)/det(q2-q1,p2-p1));
}

bool cross(P p1,P p2,P q1,P q2){
    if(det(p1-p2,q1-q2)==0)return onseg(p1,p2,q1)||onseg(p1,p2,q2)||onseg(q1,q2,p1)||onseg(q1,q2,p2);
    P ret=intersection(p1,p2,q1,q2);
    return onseg(p1,p2,ret)&&onseg(q1,q2,ret);
}

double dist(P p1,P p2,P q){
    if(dot(q-p1,p2-p1)<=0)return sqrt(dot(q-p1,q-p1));
    if(dot(q-p2,p1-p2)<=0)return sqrt(dot(q-p2,q-p2));
    P d=p1-p2;
    P ret=q+P{d.second,-d.first};
    P h=intersection(p1, p2, q, ret);
    return sqrt(dot(q-h,q-h));
}

const double pi=acos(-1);
int main(){
    int n,s,t;
    vector<double> ans;
    while(cin>>n>>s>>t){
        if(n==0)break;
        P x[n][5];
        rep(i,n){
            P c;
            cin>>c.first>>c.second;
            double a,b;
            cin>>a>>b;
            a*=pi/180;
            rep(j,5){
                P y;
                y={-sin(a+2.0/5.0*j*pi),cos(a+2.0/5.0*j*pi)};
                x[i][j]=c+y*b;
            }
        }
        double d[n][n];
        rep(i,n)rep(j,n)d[i][j]=inf;
        rep(i,n)d[i][i]=0;
        rep(i,n)rep(j,n){
            if(i==j)continue;
            rep(k,5)rep(l,5){
                d[i][j]=min(d[i][j],dist(x[i][k],x[i][(k+2)%5],x[j][l]));
                if(cross(x[i][k],x[i][(k+2)%5],x[j][l],x[j][(l+2)%5]))d[i][j]=0;
            }
        }
        rep(i,n)rep(j,n)d[i][j]=min(d[i][j],d[j][i]);
        rep(i,n)rep(j,n)rep(k,n)d[j][k]=min(d[j][k],d[i][j]+d[i][k]);
        cout<<fixed<<setprecision(12)<<d[s-1][t-1]<<endl;
    }
    return 0;
}
