#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef complex<double> P;
typedef pair<P,P> L;
const double EPS = 1e-8;
double dot(P a, P b){ return real(conj(a)*b); }
double cross(P a, P b){ return imag(conj(a)*b); }

int ccw(P a, P b, P c){
  b -= a;
  c -= a;
  if(cross(b,c) > EPS) return 1;   // ????????????(b-a)????????´???????????????(c-a)????????¨?????????
  if(cross(b,c) < -EPS) return -1; // ????????????(b-a)????????´???????????????(c-a)????????¨?????????
  if(dot(b,c) < -EPS) return 2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}

bool isIntersect(L s1, L s2){
  return ( ccw(s1.first,s1.second,s2.first) * ccw(s1.first,s1.second,s2.second) <= 0 &&
           ccw(s2.first,s2.second,s1.first) * ccw(s2.first,s2.second,s1.second) <= 0 );
}


vector<P> get_p(P a,double d,double r){
  vector<P> res(5);
  d=(d/360)*2*M_PI;
  P p=P(0,r)*P(cos(d),sin(d));
  res[0]=p+a;
  d=2*M_PI/5;
  for(int i=1;i<=4;i++){
    p=p*P(cos(d),sin(d));
    res[i]=p+a;
  }
  return res;
}
double getDistanceSP(L s, P p){
  if(dot(s.second - s.first, p - s.first) < -EPS) return abs(p - s.first);
  if(dot(s.first - s.second, p - s.second) < -EPS) return abs(p - s.second);
  return abs(cross(s.second - s.first, p - s.first) / abs(s.second - s.first));  }

double getDistanceSS(L s1, L s2){
  if(isIntersect(s1,s2)) return 0.0;
  return min( min(getDistanceSP(s1, s2.first), getDistanceSP(s1, s2.second)),
              min(getDistanceSP(s2, s1.first), getDistanceSP(s2, s1.second)));
}


double G[N][N],x[N],y[N],d[N],r[N];
double get_dis(int a,int b){
  vector<P> A=get_p(P(x[a],y[a]),d[a],r[a]);
  vector<P> B=get_p(P(x[b],y[b]),d[b],r[b]);
  double res=1e9;
  for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
      res=min(res,getDistanceSS(L(A[i],A[(i+2)%5]),L(B[j],B[(j+2)%5])));
  return res;
}

int main(){
  while(1){
  int n,s,g;
  cin>>n>>s>>g;
  if(!n&&!s&&!g)break;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)G[i][j]=1e9*(i!=j);
  for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>d[i]>>r[i];
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)if(i!=j) G[i][j]=get_dis(i,j);
  
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
	G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

  printf("%.20f\n",G[s-1][g-1]);
  }
  return 0;
}