#include<bits/stdc++.h>

#define EQ(a,b) (abs((a)-(b)) < EPS)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define fs first
#define sc second
#define pb push_back
#define sz size()
#define all(a) (a).begin(),(a).end()

using namespace std;
typedef double D;
typedef complex<D> P;
typedef pair<P,P> L;

const D EPS = 1e-8;
const D PI = acos(-1);
//for vector
inline D dot(P x, P y){return real(conj(x)*y);}
inline D cross(P x, P y){return imag(conj(x)*y);}

//rotate a point counter-clockwise on the origin
inline P rotate(P v, D s){
  return P(real(v)*cos(s) - imag(v)*sin(s), real(v)*sin(s) + imag(v)*cos(s) );
}

inline int ccw(P a,P b,P c){
  b -= a;c -= a;
  if (cross(b,c)>EPS) return 1;   //counter clockwise
  if (cross(b,c)<-EPS) return -1; //clockwise
  if (dot(b, c)<-EPS) return 2;   //c--a--b on line
  if (abs(b)+EPS<abs(c)) return -2;   //a--b--c on line
  return 0;                       //on segment
}

inline bool is_cp(L a,L b){
  if(ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0)
    if(ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0)return true;
  return false;
}

inline D seg_p_dis(L a,P x){
  if(dot(a.sc-a.fs,x-a.fs)<EPS)return abs(x-a.fs);
  if(dot(a.fs-a.sc,x-a.sc)<EPS)return abs(x-a.sc);
  return abs(cross(a.sc-a.fs,x-a.fs))/abs(a.sc-a.fs);
}

inline D seg_seg_dis(L a,L b){
  D res = 1e10;
  res = min(res,seg_p_dis(a,b.fs));
  res = min(res,seg_p_dis(a,b.sc));
  res = min(res,seg_p_dis(b,a.fs));
  res = min(res,seg_p_dis(b,a.sc));
  return res;
}

D g[111][111],d[111];
L starl[111][5];
P starv[111][5],c,p;
int n,m,l,x,y,a,r;
bool use[111];

int main(){
  while(scanf("%d%d%d",&n,&m,&l), n){
    for(int i=0;i<n;i++){
      scanf("%d%d%d%d",&x,&y,&a,&r);
      c = P(x,y), p = P(0,r);
      for(int j=0;j<5;j++)starv[i][j] = c+rotate(p,PI*(a+j*72)/180);
      for(int j=0;j<5;j++)starl[i][j] = L(starv[i][j],starv[i][(j+2)%5]);
    }

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
	D dis = 1e9;
	for(L a : starl[i]){
	  for(L b : starl[j]){
	    if(is_cp(a,b))dis = 0;
	  }
	}
	if(dis>EPS){
	  for(P a : starv[i]){
	    for(L b : starl[j])dis = min(dis, seg_p_dis(b,a));
	  }
	  for(P a : starv[j]){
	    for(L b : starl[i])dis = min(dis, seg_p_dis(b,a));
	  }
	}
	g[i][j] = g[j][i] = dis;
      }
      g[i][i] = 0;
    }

    for(int i=0;i<n;i++)d[i] = 1e9;
    d[m-1] = 0;
    memset(use,0,sizeof(use));

    for(;;){
      int v = -1;
      for(int u=0;u<n;u++){
	if(!use[u] && (v<0 || d[v] > d[u]))v = u;
      }

      if(v<0 || v==l-1)break;
      use[v] = 1;

      for(int u=0;u<n;u++){
	d[u] = min(d[u],d[v]+g[u][v]);
      }
    }

    printf("%.9lf\n",d[l-1]);
  }
}	