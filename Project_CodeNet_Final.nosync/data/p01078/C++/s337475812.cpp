#include<iostream>
#include<cstdio>
#include<complex>
#include<vector>
using namespace std;
typedef complex<double> P;
typedef vector<P> G;
#define rep(i,a) for(int i=0;i<a;i++)
struct L:public vector<P>{
  L(const P &a,const P &b){
    push_back(a);push_back(b);
  }
};
const double EPS=1e-8;
const double PI=acos(-1);
double cross(P a,P b){
  return imag(conj(a)*b);
}
double area(const G &g){
  double S=0;
  for(int i=0;i<g.size();i++){
    S+=(cross(g[i],g[(i+1)%g.size()]));
  }
  return abs(S/2.0);
}
P crosspointLL(const L &l,const L &m){
  double A=cross(l[1]-l[0],m[1]-m[0]);
  double B=cross(l[1]-l[0],l[1]-m[0]);
  if(abs(A)<EPS&&abs(B)<EPS)return m[0];
  return m[0]+B/A*(m[1]-m[0]);
}
P turn(P p,double t){
  return p*exp(P(.0,t*PI/180.0));
}
int main(){
  int n,k;
  cin>>n>>k;
  G g(n);
  g[0]=P(1,0);
  rep(i,n-1)g[i+1]=turn(g[i],360./n);
  double out=area(g);
  //  cout<<out<<endl;
  P p=crosspointLL(L(g[0],g[k]),L(g[1],g[(1-k+n)%n]));
  G t(3);
  t[0]=g[0];
  t[1]=g[1];
  t[2]=p;
  out-=n*area(t);
  printf("%.9f\n",out);
}