#include<cstdio>
#include<complex>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<iostream>

#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b)) < EPS)
#define fs first
#define sc second

using namespace std;

typedef pair<double,int> Pd;
typedef complex<double> P;
typedef pair<P,P> L;

const double PI = acos(-1);

double dot(P x,P y){return real(conj(x)*y);}
double cross(P x,P y){return imag(conj(x)*y);}

P rotate(P v,double s){
  return P(real(v)*cos(s) - imag(v)*sin(s), real(v)*sin(s) + imag(v)*cos(s) );
}

int ccw(P a,P b,P c){
  b -= a; c -= a;
  if(cross(b,c)>EPS)return 1;
  if(cross(b,c)<-EPS)return -1;
  if(dot(b,c)<-EPS)return 2;
  if(abs(b)<abs(c))return -2;
  return 0;
}

bool is_cp(L a,L b){
  if(ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0)
    if(ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0)return true;
  return false;
}

double seg_p_dis(L a,P x){
  if(dot(a.sc-a.fs,x-a.fs)<EPS)return abs(x-a.fs);
  if(dot(a.fs-a.sc,x-a.sc)<EPS)return abs(x-a.sc);
  return abs(cross(a.sc-a.fs,x-a.fs))/abs(a.sc-a.fs);
}

double seg_seg_dis(L a,L b){
  double res = 1e10;
  res = min(res,seg_p_dis(a,b.fs));
  res = min(res,seg_p_dis(a,b.sc));
  res = min(res,seg_p_dis(b,a.fs));
  res = min(res,seg_p_dis(b,a.sc));
  return res;
}

int n,m,l;
double xi[110],yi[110],ai[110],ri[110];
vector<Pd> g[110];
L s[110][5];
double d[110];

void make_star(int x){
  P p[5];
  P tmp = P(0.0,ri[x]);
  p[0] = rotate(tmp,ai[x]*PI/180);
  for(int i=1;i<5;i++)p[i] = rotate(p[i-1],72*PI/180);
  for(int i=0;i<5;i++)p[i] += P(xi[x],yi[x]);
  for(int i=0;i<5;i++)s[x][i] = L(p[i],p[(i+2)%5]);
}
 
void make_graph(void){
  for(int i=0;i<n;i++)make_star(i);
  
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      bool f = false;
      for(int k1=0;k1<5;k1++){
	for(int k2=0;k2<5;k2++){
	  f |= is_cp(s[i][k1],s[j][k2]);
	  if(f)break;
	}
      }
      if(f){
	g[i].push_back(Pd(0.0,j));
	g[j].push_back(Pd(0.0,i));
      }else{
	double dis = 1e10;
	for(int k1=0;k1<5;k1++){
	  for(int k2=0;k2<5;k2++){
	    dis = min(dis,seg_seg_dis(s[i][k1],s[j][k2]));
	  }
	}	
	g[i].push_back(Pd(dis,j));
	g[j].push_back(Pd(dis,i));
      }
    }
  }
}

int main(){
  while(scanf("%d%d%d",&n,&m,&l), (n||m||l)){
    for(int i=0;i<n;i++)scanf("%lf%lf%lf%lf",&xi[i],&yi[i],&ai[i],&ri[i]);

    for(int i=0;i<n;i++)g[i].clear();
    make_graph();

    for(int i=0;i<n;i++)d[i] = 1e10; d[m-1] = 0.0;
    priority_queue<Pd,vector<Pd>,greater<Pd> >q;
    q.push(Pd(0.0,m-1));

    while(q.size()){
      Pd p = q.top(); q.pop();
      double cost = p.fs;
      int pos = p.sc;

      if(pos == l-1)break;

      for(int i=0;i<g[pos].size();i++){
	double dis = cost + g[pos][i].fs;
	int next = g[pos][i].sc;
	if(dis+EPS < d[next]){
	  d[next] = dis;
	  q.push(Pd(dis,next));
	}
      }
    }

    printf("%.10lf\n",d[l-1]);
  }
}