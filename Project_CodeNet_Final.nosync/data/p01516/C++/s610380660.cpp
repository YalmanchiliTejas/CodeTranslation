#include <cstdio>
#include <iostream>
#include <complex>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
using P = complex<double>;
using L = pair<P,P>;
using Poly = vector<P>;
#define X real()
#define Y imag()
const double EPS = 1e-10, pi = acos(-1), INF = 1e9;

double dot(const P a, const P b){ return a.X*b.X+a.Y*b.Y;}
double cross(const P a, const P b){ return a.X*b.Y-a.Y*b.X;}

int ccw(P a, P b, P c){
  b -= a, c -= a;
  if(cross(b,c) > EPS) return +1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < 0) return 2;
  if(norm(b) + EPS < norm(c)) return -2;
  return 0;
}

bool is_cross(L a, L b){
  P af = a.first, as = a.second, bf = b.first, bs = b.second;
  return (ccw(af,as,bf)*ccw(af,as,bs) <= 0 and ccw(bf,bs,af)*ccw(bf,bs,as) <= 0);
}

double ps_dist(P a, L s){
  P sf = s.first, ss = s.second;
  if(dot(ss-sf,a-sf) >= 0 and dot(sf-ss,a-ss) >= 0)
    return abs(cross(sf-ss,a-ss))/abs(sf-ss);
  return min(abs(a-sf),abs(a-ss));
}

double ss_dist(L a, L b){
  if(is_cross(a,b)) return 0;
  P af = a.first, as = a.second, bf = b.first, bs = b.second;
  return min({ps_dist(af,b),ps_dist(as,b),ps_dist(bf,a),ps_dist(bs,a)});
}

double polpol_dist(Poly a, Poly b){
  int N = a.size(), M = b.size();
  double ret = INF;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      ret = min(ret,ss_dist(L(a[i],a[(i+1)%N]),L(b[j],b[(j+1)%M])));
    }
  }
  return ret;
}

int main(){
  int N, M, L;
  while(cin >> N >> M >> L, N){
    --M,--L;
    vector<Poly> S(N);
    Poly star;
    P s(0,1);
    star.push_back(s);
    for(int i = 0; i < 4; ++i){
      s *= P(cos(pi*0.8),sin(pi*0.8));
      star.push_back(s);
    }
    //for(auto c : star) cerr << c << endl;
    //return 0;
    for(int i = 0; i < N; ++i){
      double x, y, a, r;
      cin >> x >> y >> a >> r;
      P t(r*cos(a/180*pi),r*sin(a/180*pi));
      for(int j = 0; j < 5; ++j){
        S[i].push_back(t*star[j] + P(x,y));
      }
    }
    vector<vector<double>> D(N,vector<double>(N,INF));
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        D[i][j] = polpol_dist(S[i],S[j]);
      }
    }
    for(int k = 0; k < N; ++k){
      for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
          D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
        }
      }
    }
    printf("%.12f\n",D[M][L]);
  }
}

