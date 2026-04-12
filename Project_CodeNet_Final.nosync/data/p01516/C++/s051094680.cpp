#include<bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;
typedef complex<double> P;
typedef pair<P,P> L;
typedef pair<double,int> D;
const double EPS = 1e-8;

P p[100];
double r[100],d[100];
int n,s,g;

double dot(P a, P b){ return real(conj(a)*b); }

double cross(P a, P b){ return imag(conj(a)*b); }

int ccw(P a, P b, P c){
  b -= a;
  c -= a;
  if(cross(b,c) > EPS) return 1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < -EPS) return 2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}

bool isIntersect(L s1, L s2){
  return ( ccw(s1.first,s1.second,s2.first) * ccw(s1.first,s1.second,s2.second) <= 0 &&
           ccw(s2.first,s2.second,s1.first) * ccw(s2.first,s2.second,s1.second) <= 0 );
}

double getDistanceSP(L s, P p){
  if(dot(s.second - s.first, p - s.first) < -EPS) return abs(p - s.first);
  if(dot(s.first - s.second, p - s.second) < -EPS) return abs(p - s.second);
  return abs(cross(s.second - s.first, p - s.first) / abs(s.second - s.first)); }

double getDistanceSS(L s1, L s2){
  if(isIntersect(s1,s2)) return 0.0;
  return min( min(getDistanceSP(s1, s2.first), getDistanceSP(s1, s2.second)),
              min(getDistanceSP(s2, s1.first), getDistanceSP(s2, s1.second)));
}

double slv(){
  for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y>>d[i]>>r[i];
  
  priority_queue<D,vector<D>,greater<D> > Q;
  int used[100]={};
  Q.push(D(0,s-1));
  while(!Q.empty()){
    double cs=Q.top().first;
    int pos=Q.top().second;
    Q.pop();
    if(used[pos]++)continue;
    if(pos==g-1)return cs;
    
    for(int i=0;i<n;i++){
      if(i==pos)continue;

      for(int j=0;j<5;j++){
	
	double na=M_PI*(d[i]+72*j+90)/180;
	double na1=M_PI*(d[i]+72*(j+2)+90)/180;
	L S=L(P(r[i]*cos(na),r[i]*sin(na))+p[i],P(r[i]*cos(na1),r[i]*sin(na1))+p[i]);
	for(int k=0;k<5;k++){
	  double nb=M_PI*(d[pos]+72*k+90)/180;
	  double nb1=M_PI*(d[pos]+72*(k+2)+90)/180;
	  L G=L(P(r[pos]*cos(nb),r[pos]*sin(nb))+p[pos],P(r[pos]*cos(nb1),r[pos]*sin(nb1))+p[pos]);
	  Q.push(D(cs+getDistanceSS(S,G),i));
	}
      }
    }
  }
}

int main(){
  while(cin>>n>>s>>g,n)printf("%.8lf\n",slv());
  return 0;
}