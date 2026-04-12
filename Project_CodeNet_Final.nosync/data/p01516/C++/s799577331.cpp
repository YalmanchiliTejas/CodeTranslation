#include<bits/stdc++.h>
using namespace std;


typedef complex<double> P; //Point
typedef pair<P,P> L; //Line, Segment

const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);

namespace std {
  bool operator < (const P& a, const P& b){
    return fabs(real(a)-real(b)) < EPS ? imag(a) < imag(b) : real(a) < real(b);
  }
}

/*
  ベクトルの内積
  a.real() * b.real() + a.imag() * b.imag()
*/
double dot(P a, P b){ return real(conj(a)*b); }


/*
  ベクトルの外積
  a.real() * b.imag() - a.imag() * b.real()
*/
double cross(P a, P b){ return imag(conj(a)*b); }

// 回転行列
P rotate(P p, double theta,double cx,double cy){
  theta = theta * M_PI / 180.0;
  p.real()-=cx; p.imag()-=cy;
  double x = real(p) * cos(theta) - imag(p) * sin(theta);
  double y = real(p) * sin(theta) + imag(p) * cos(theta);
  x+=cx; y+=cy;
  return P(x,y);
}

// ベクトル a,b の位置関係
int ccw(P a, P b, P c){
  b -= a;
  c -= a;
  if(cross(b,c) > EPS) return 1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < -EPS) return 2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}


// 線分と線分の交差判定（交差していたらtrue）
bool isIntersect(L s1, L s2){
  
  //ccw による判定だけだと, 二線分が同一直線上にあるときに間違うため、追加
  if(max(real(s1.first), real(s1.second)) + EPS < min(real(s2.first), real(s2.second)) ||
     max(imag(s1.first), imag(s1.second)) + EPS < min(imag(s2.first), imag(s2.second)) ||
     max(real(s2.first), real(s2.second)) + EPS < min(real(s1.first), real(s1.second)) ||
     max(imag(s2.first), imag(s2.second)) + EPS < min(imag(s1.first), imag(s1.second))) return false;

  return ( ccw(s1.first,s1.second,s2.first) * ccw(s1.first,s1.second,s2.second) <= 0 &&
           ccw(s2.first,s2.second,s1.first) * ccw(s2.first,s2.second,s1.second) <= 0 );
}

// 線分と点の距離
double getDistanceSP(L s, P p){
  if(dot(s.second - s.first, p - s.first) < -EPS) return abs(p - s.first);
  if(dot(s.first - s.second, p - s.second) < -EPS) return abs(p - s.second);
  return abs(cross(s.second - s.first, p - s.first) / abs(s.second - s.first));  //直線と点の距離
}

// 線分と線分の距離
double getDistanceSS(L s1, L s2){
  if(isIntersect(s1,s2)) return 0.0;
  return min( min(getDistanceSP(s1, s2.first), getDistanceSP(s1, s2.second)),
              min(getDistanceSP(s2, s1.first), getDistanceSP(s2, s1.second)));
}

double AngleToRad(double angle){
  return angle * M_PI / 180.0;
}

struct star{
  L line[5];
  void set(double x,double y,double a,double r){
    P p[5];
    double angle = 90;
    for(int i=0;i<5;i++){
      double rad = AngleToRad(angle);
      p[i] = P(x+r*cos(rad),y+r*sin(rad));
      p[i] = rotate(p[i],a,x,y);
      angle -= 72;
    }
    for(int i=0;i<5;i++)
      line[i] = L(p[i],p[(i+2)%5]);
  }

  double getDis(const star &s){
    double ret = 1e15;
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	ret = min( ret , getDistanceSS(line[i],s.line[j]) );
      }
    }
    return ret;
  }

};

typedef pair<double,int> PA;

int N,B,A;
star S[111];
double Dis[111];

int main(){
  while( (~scanf("%d%d%d",&N,&B,&A)) && (N||B||A) ){
    for(int i=0;i<N;i++){
      int x,y,a,r;
      scanf("%d%d%d%d",&x,&y,&a,&r);
      S[i].set(x,y,a,r);
    }
    --B;--A;
    priority_queue<PA,vector<PA>,greater<PA> > q;
    fill(Dis,Dis+N,1e15);
    q.push( PA(0.0,B) );
    Dis[B] = 0.0;
    while( !q.empty() ){
      PA  p = q.top(); q.pop();
      int now = p.second;
      double c = p.first;
      if( Dis[p.second] < p.first ) continue;
      for(int i=0;i<N;i++){
	if( now == i ) continue;
	double nc = c + S[now].getDis(S[i]);
	if( Dis[i] > nc+EPS ) {
	  Dis[i] = nc;
	  q.push( PA(nc,i) );
	}
      }
    }
    printf("%.9lf\n",Dis[A]);
  }
}