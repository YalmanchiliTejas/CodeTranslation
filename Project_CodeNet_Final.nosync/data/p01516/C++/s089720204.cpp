#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#define X real()
#define Y imag()
#define EPS 1e-10
#define INF 1e8
using namespace std;
typedef complex<double> P;
typedef pair<P, P> L;
typedef vector<P> Poly;
static const double pi = acos(-1.0);

double dot(P a, P b){
  return a.X*b.X + a.Y*b.Y;
}

double cross(P a, P b){
  return a.X*b.Y - a.Y*b.X;
}

int ccw(P a, P b, P c){
  if(cross(b-a,c-a) > EPS) return 1;
  if(cross(b-a,c-a) < -EPS) return -1;
  if(dot(b-a,c-a) < -EPS) return 2;
  if(norm(b-a)+EPS < norm(c-a))return -2;
  return 0;
}

bool is_cross(L a, L b){
  if(ccw(a.first,a.second,b.first)*ccw(a.first,a.second,b.second) <= 0 &&
     ccw(b.first,b.second,a.first)*ccw(b.first,b.second,a.second) <= 0) return true;
  return false;
}

double p_to_s_dist(P p, L s){
  if(dot(p-s.first,s.second-s.first) >= 0 &&
     dot(p-s.second,s.first-s.second) >= 0) return abs(cross(p-s.first,s.second-s.first))/abs(s.second-s.first);
  return min(abs(p-s.first),abs(p-s.second));
}

double s_to_s_dist(L a, L b){
  if(is_cross(a,b)) return 0;
  return min(min(p_to_s_dist(a.first,b),p_to_s_dist(a.second,b)),
	     min(p_to_s_dist(b.first,a),p_to_s_dist(b.second,a)));
}

double Poly_to_Poly_dist(Poly a, Poly b){
  double dist = INF;
  int na = a.size(), nb = b.size();
  a.push_back(a[0]);
  b.push_back(b[0]);
  for(int i = 0; i < na; ++i){
    for(int j = 0; j < na; ++j){
      dist = min(dist,s_to_s_dist(L(a[i],a[i+1]),L(b[j],b[j+1])));
    }
  }
  return dist;
}

Poly star(P p, double r, double a){
  Poly ret;
  for(int i = 0; i < 5; ++i){
    ret.push_back(P(polar(r,(a+90+144*i)/360*2*pi)+p));
  }
  return ret;
}

int main(){
  int N, M, L;
  double x, y, a, r;
  while(cin >> N >> M >> L, N){
    vector<Poly> stars(N);
    for(int i = 0; i < N; ++i){
      cin >> x >> y >> a >> r;
      stars[i] = star(P(x,y),r,a);
    }
    vector< vector<double> > WF(N, vector<double>(N, INF));
    for(int i = 0; i < N; ++i){
      for(int j = i; j < N; ++j){
	if(i == j) WF[i][j] = 0;
	else{
	  WF[i][j] = Poly_to_Poly_dist(stars[i],stars[j]);
	  WF[j][i] = WF[i][j];
	}
      }
    }
    for(int k = 0; k < N; ++k){
      for(int i = 0; i < N; ++i){
	for(int j = 0; j < N; ++j){
	  WF[i][j] = min(WF[i][j], WF[i][k] + WF[k][j]);
	}
      }
    }
    printf("%.10lf\n", WF[M-1][L-1]);
  }
  return 0;
}