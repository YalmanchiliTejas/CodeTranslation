#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define R(i,a,n) for(int i=a;i<n;i++)
typedef complex<double> P;
struct seg{P p1,p2;};
double eps=1e-10;
bool eq(double a,double b){return (b-a<eps&&a-b<eps);}
double dot(P a,P b){return real(b*conj(a));}
double cross(P a,P b){return imag(b*conj(a));}
int ccw(P a,P b,P c){
  b-=a,c-=a,a=c*conj(b);
  if(a.imag()>eps)return 1;
  if(a.imag()<-eps)return -1;
  if(a.real()<-eps)return 2;
  if(abs(b)+eps<abs(c))return -2;
  return 0;
}
double dist(P a,P b,P c){
  if(dot(b-a,c-a)<0)return abs(c-a);
  if(dot(a-b,c-b)<0)return abs(c-b);
  return abs(cross(b-a,c-a))/abs(b-a);
}
bool isintersect(P a,P b,P c,P d){
  return ((ccw(a,b,c)*ccw(a,b,d)<=0)&&(ccw(c,d,a)*ccw(c,d,b)<=0));
}
double dist(P a,P b,P c,P d){
  if(isintersect(a,b,c,d))return 0;
  double ab=min(dist(a,b,c),dist(a,b,d));
  double cd=min(dist(c,d,a),dist(c,d,b));
  return min(ab,cd);
}
int main(){
  double a,b,c,d;
  int n,ve,al;
  while(cin>>n>>ve>>al,n){
    P p[n][5];
    seg D[n][5];
    r(i,n){
      cin>>a>>b>>c>>d;
      r(j,5)p[i][j]=P(a-d*sin(M_PI/180*(72*j+c)),b+d*cos(M_PI/180*(72*j+c)));
      r(j,5)D[i][j].p1=p[i][j%5],D[i][j].p2=p[i][(j+2)%5];
    }
    double w[n][n];
    r(i,n)r(j,n)w[i][j]=i==j?0:1000000000;
    r(i,n)R(j,i+1,n){
      double t=1000000000;
      r(k,5)r(l,5)t=min(t,dist(D[i][k].p1,D[i][k].p2,D[j][l].p1,D[j][l].p2));
      w[i][j]=w[j][i]=t;
    }
    r(k,n)r(i,n)r(j,n)w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
    printf("%.11f\n",w[ve-1][al-1]);
  }
}