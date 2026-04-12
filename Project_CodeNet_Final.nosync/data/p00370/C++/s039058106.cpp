#include<bits/stdc++.h>
#define double long double 
using namespace std;
typedef complex<double> P;
typedef pair<P,P> L;
typedef pair<P,bool> PP;

const double EPS = 1e-8;

namespace std {
  bool operator < (const P& a, const P& b){
    return fabs(real(a)-real(b)) < EPS ? imag(a) < imag(b) : real(a) < real(b);
  }
}

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

vector<PP> convex_hull(vector<PP> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<PP> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k-2].first, ch[k-1].first, ps[i].first) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k-2].first, ch[k-1].first, ps[i].first) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

bool isIntersect(L s1, L s2){
  return ( ccw(s1.first,s1.second,s2.first) * ccw(s1.first,s1.second,s2.second) <= 0 &&
           ccw(s2.first,s2.second,s1.first) * ccw(s2.first,s2.second,s1.second) <= 0 );
}

bool check(vector<PP> v,P s,P g){
  bool res=0;
  int n=v.size();
  for(int i=0;i<n;i++)res|=isIntersect(L(v[i%n].first,v[(i+1)%n].first),L(s,g));
  return res;
}

double ref(P a,P b,P s,P g){
  double l=0,r=abs(a-b);
  int cnt=100;
  b-=a,s-=a,g-=a,b/=abs(b);
  while(cnt--){
    double m=(l+r)/2;
    P p1=m*b,p2=(m+EPS)*b;
    if(abs(s-p1)+abs(g-p1)<abs(s-p2)+abs(g-p2))r=m;
    else l=m;
  }
  b*=l;
  return abs(b-s)+abs(b-g);
}

int main(){
  double x,y;
  P s,g;
  cin>>x>>y;
  s=P(x,y);
  cin>>x>>y;
  g=P(x,y);
  int n;
  cin>>n;
  vector<PP> v;
  for(int i=0;i<n;i++)cin>>x>>y,v.push_back(PP(P(x,y),0));
  double ans=1e9;
  if(check(v,s,g)){
    v.push_back(PP(s,1));
    v.push_back(PP(g,1));
    v=convex_hull(v);
    int n=v.size();
    double sum=1e9;
    for(int i=0;i<2*n;i++){
      if(v[i%n].second)ans=min(ans,sum),sum=0;
      sum+=abs(v[i%n].first-v[(i+1)%n].first);
    }
  }
  else{
    for(int i=0;i<n;i++)
      ans=min(ans,ref(v[i].first,v[(i+1)%n].first,s,g));
  }
  printf("%.8Lf\n",ans);
  return 0;
}