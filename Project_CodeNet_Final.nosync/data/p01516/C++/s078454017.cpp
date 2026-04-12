#include<bits/stdc++.h>
#define EPS (1e-7)
#define INF (1e9)
#define N 105
using namespace std;
typedef pair<double,int> P1;
typedef complex<double> P;
typedef pair<P,P> L;
vector<vector<P> > Stars;
int n,m,l,x,y,a,r;
double d[N];

P Rot_P(P p,int sita){
  return P(p.real()*cos(sita*M_PI/180.0)-p.imag()*sin(sita*M_PI/180.0),
	   p.real()*sin(sita*M_PI/180.0)+p.imag()*cos(sita*M_PI/180.0));
}

void Make_Star(){
  P p=P(0,r);
  p=Rot_P(p,a);
  vector<P> Star;
  for(int i=0;i<5;i++){
    Star.push_back(P(p.real()+x,p.imag()+y));
    p=Rot_P(p,216);
  }
  Stars.push_back(Star);
}

double dot(P a, P b){ return real(conj(a)*b); }

double cross(P a, P b){ return imag(conj(a)*b); }

double getDistanceSP(L s, P p){
  if(dot(s.second - s.first, p - s.first) < -EPS) return abs(p - s.first);
  if(dot(s.first - s.second, p - s.second) < -EPS) return abs(p - s.second);
  return abs(cross(s.second - s.first, p - s.first) / abs(s.second - s.first));
}

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

double getDistanceSS(L s1, L s2){
  if(isIntersect(s1,s2)) return 0.0;
  return min( min(getDistanceSP(s1, s2.first), getDistanceSP(s1, s2.second)),
              min(getDistanceSP(s2, s1.first), getDistanceSP(s2, s1.second)));
}

double get_d(int A,int B){
  double res=INF;
  for(int i=0;i<5;i++){
    L l1=L(Stars[A][i],Stars[A][(i+1)%5]);
    for(int j=0;j<5;j++){
      L l2=L(Stars[B][j],Stars[B][(j+1)%5]);
      res=min(res,getDistanceSS(l1,l2));
    }
  }
  return res;
}

double dijkstra(){
  priority_queue<P1,vector<P1>,greater<P1> > q;
  for(int i=0;i<n;i++)d[i]=INF;
  q.push(P1(0,m));
  d[m]=0;
  while(!q.empty()){
    P1 t=q.top(); q.pop();
    double cost=t.first;
    int node=t.second;
    if(d[node]+EPS<cost)continue;
    if(node==l)return cost;
    for(int i=0;i<n;i++){
      if(node==i)continue;
      double ncost=cost+get_d(node,i);
      if(d[i]>ncost+EPS){
	d[i]=ncost;
	q.push(P1(ncost,i));
      }
    }
  }
  return INF;
}

int main(){
  while(1){
    cin>>n>>m>>l;
    if(!n&&!m&&!l)break;
    m--; l--;
    for(int i=0;i<n;i++){
      cin>>x>>y>>a>>r;
      Make_Star();
    }
    printf("%.20f\n",dijkstra());
    for(int i=0;i<n;i++)Stars.clear();
  }
  return 0;
}