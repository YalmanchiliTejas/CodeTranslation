#include <bits/stdc++.h>
using namespace std;

typedef complex<double> P;
typedef pair<P,P> L;

const double INF = 1e+12;
const double EPS = 1e-8;

double dot(P a, P b){ return real(conj(a)*b); }

double cross(P a, P b){ return imag(conj(a)*b); }

P rotate(P p, double rad){
  double x = real(p) * cos(rad) - imag(p) * sin(rad);
  double y = real(p) * sin(rad) + imag(p) * cos(rad);
  return P(x,y);
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
  if(max(real(s1.first), real(s1.second)) + EPS < min(real(s2.first), real(s2.second)) ||
     max(imag(s1.first), imag(s1.second)) + EPS < min(imag(s2.first), imag(s2.second)) ||
     max(real(s2.first), real(s2.second)) + EPS < min(real(s1.first), real(s1.second)) ||
     max(imag(s2.first), imag(s2.second)) + EPS < min(imag(s1.first), imag(s1.second))) return false;

  return ( ccw(s1.first,s1.second,s2.first) * ccw(s1.first,s1.second,s2.second) <= 0 &&
           ccw(s2.first,s2.second,s1.first) * ccw(s2.first,s2.second,s1.second) <= 0 );
}

double getDistanceSP(L s, P p){
  if(dot(s.second - s.first, p - s.first) < -EPS) return abs(p - s.first);
  if(dot(s.first - s.second, p - s.second) < -EPS) return abs(p - s.second);
  return abs(cross(s.second - s.first, p - s.first) / abs(s.second - s.first));
}

double getDistanceSS(L s1, L s2){
  if(isIntersect(s1,s2)) return 0.0;
  return min( min(getDistanceSP(s1, s2.first), getDistanceSP(s1, s2.second)),
              min(getDistanceSP(s2, s1.first), getDistanceSP(s2, s1.second)));
}

vector<P> getStar(double x, double y, double a, double r){
  vector<P> res;
  P p = P(0,r);
  a *= M_PI / 180.0;
  for(int i=0;i<5;i++){
    res.push_back(p);
    p = rotate(p, 2.0 / 5.0 * (M_PI * 2.0));    
  }
  for(int i=0;i<5;i++){
    res[i] = rotate(res[i], a);
    res[i] += P(x,y);
  }
  return res;
}

int n,be,al;
vector<vector<P> > v;

void solve(){
  double G[100][100];

  fill(G[0],G[n],INF);
  for(int i=0;i<n;i++) G[i][i] = 0;

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      for(int k=0;k<5;k++)
        for(int l=0;l<5;l++)
          G[i][j] = G[j][i] = min(G[i][j], getDistanceSS(L(v[i][k],v[i][(k+1)%5]), L(v[j][l],v[j][(l+1)%5])));

  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

  printf("%.10f\n",G[be][al]);
}

int main(){
  while(cin >> n >> be >> al && (n|be|al)){
    v.clear();
    be--;
    al--;
    for(int i=0;i<n;i++){
      double x,y,a,r;
      cin >> x >> y >> a >> r;
      v.push_back(getStar(x,y,a,r));
    }
    solve();
  }
}