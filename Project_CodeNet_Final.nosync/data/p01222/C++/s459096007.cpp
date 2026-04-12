#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define double long double
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef pair<int,int> pii;
typedef long long ll;

typedef double Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};

bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;


// テゥツ?禿ァツィツ凝」ツ?古」ツ??」ツつ嘉」ツ?ェテ」ツ??・ツ?エテ・ツ青?
vector<Weight> dijkstra(const Graph &g, int s) {
  vector<Weight> dist(g.size(), INF);
  dist[s] = 0;
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (dist[e.dst] < e.weight) continue;
    FOR(f,g[e.dst]) {
      if (dist[f->dst] > e.weight+f->weight) {
        dist[f->dst] = e.weight+f->weight;
        Q.push(Edge(f->src, f->dst, e.weight+f->weight));
      }
    }
  }
  return dist;
}


typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    if (abs(a-b)<EPS) return 0;
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
  L() {resize(2);}
};
ostream &operator<<(ostream &os, const L &a) {
  os << a[0] << " -> " << a[1];
  return os;
}

typedef vector<P> G;
#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > EPS)   return +1;       // counter clockwise
  if (cross(b, c) < -EPS)   return -1;       // clockwise
  if (dot(b, c) < -EPS)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

P rotate(const P &p, double ang) {
  return p * P(cos(ang), sin(ang));
}

P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
P reflection(const L &l, const P &p) {
  return p + P(2,0) * (projection(l, p) - p);
}

double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}

bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}
bool intersectLL(const L &l, const L &m) {
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
         abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
bool intersectLS(const L &l, const L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
         cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
bool intersectLP(const L &l, const P &p) {
  return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSS2(const L &s, const L &t) {
  if (intersectSP(s,t[0]) || intersectSP(s,t[1]) ||
      intersectSP(t,s[0]) || intersectSP(t,s[1])) return 0;
  return intersectSS(s,t);
}
bool intersectHS(const L &h, const L &s) {
  if (intersectLP(h,s[0]) || intersectLP(h,s[1]) ||
      intersectLP(s,h[0]) || intersectLP(s,h[1])) return 0;
  if (intersectSS(h,s)) return 1;
  if (!intersectLS(h,s)) return 0;
  return (ccw(s[0],s[1],h[0]) == 1) ^ (cross(s[1]-s[0], h[1]-h[0]) > 0);
}

P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

bool EQ(double a, double b) {
  return abs(a-b) < EPS;
}
bool EQP(const P &a, const P &b) {
  return norm(a-b) < EPS*EPS;
}

Graph segmentArrangement(const vector<L> &ss, vector<P> &ps, P start, P end) {
  for (int i = 0; i < ss.size(); ++i) { // O(n^2)
    ps.push_back( ss[i][0] );
    ps.push_back( ss[i][1] );
    if (intersectSP(ss[i], start)) ps.push_back(start);
    if (intersectSP(ss[i], end)) ps.push_back(end);
    for (int j = i+1; j < ss.size(); ++j)
      if (intersectSS(ss[i], ss[j]))
        ps.push_back( crosspoint(ss[i], ss[j]) );
  }
  sort(ALL(ps)); ps.erase(unique(ALL(ps)), ps.end());

  Graph g(ps.size());
  for (int i = 0; i < ss.size(); ++i) {
    vector< pair<double, int> > list;
    for (int j = 0; j < ps.size(); ++j)
      if (intersectSP(ss[i], ps[j]))
        list.push_back(make_pair(norm(ss[i][0]-ps[j]), j));
    sort(ALL(list));
    for (int j = 0; j+1 < list.size(); ++j) {
      int a = list[j].second, b = list[j+1].second;
      g[a].push_back( Edge(a, b, abs(ps[a]-ps[b])) );
      g[b].push_back( Edge(b, a, abs(ps[a]-ps[b])) );
    }
  }
  return g;
}


vector<P> graham(vector<P> v) {
  if (v.size()<=2) return v;
  int n = v.size(), k = 0;
  sort(ALL(v));
  vector<P> ret(2*n);
  for (int i = 0; i < n; ret[k++] = v[i++])
    while (k >= 2 && ccw(ret[k-2],ret[k-1],v[i]) < 0) k--;
  for (int i = n-2, t = k+1; i >= 0; ret[k++] = v[i--])
    while (k >= t && ccw(ret[k-2],ret[k-1],v[i]) < 0) k--;
  ret.resize(k-1);
  return ret;
}

typedef valarray<double> point;
struct line : public vector<point> {
  line() {}
  line(point a, point b) { push_back(a); push_back(b); }
};
point Point(double x, double y, double z) {
  point p(3);
  p[0]=x;p[1]=y;p[2]=z;
  return p;
}
double dot(const point& a, const point& b) {
  return (a * b).sum();
}
point cross(const point& a, const point& b) {
  return a.cshift(+1)*b.cshift(-1)
       - a.cshift(-1)*b.cshift(+1);
}
double norm(const point &a) {
  return dot(a,a);
}
double length(const point &a) {
  return sqrt(dot(a,a));
}
double angle(const point &a, const point &b) {
  return acos( dot(a,b)/length(a)/length(b) );
}
point input() {
  double a[3];
  REP(i,3) cin >>a[i];
  return point(a,3);
}
ostream &operator<<(ostream &os, const point &a) {
  char str[200];
  snprintf(str, 199, "(%.2Lf, %.2Lf, %.2Lf)", a[0], a[1], a[2]);
  os << str;
  return os;
}

point projection(const line &l, const point &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t * (l[0]-l[1]);
}
bool intersectSP(const line &s, const point &p) {
  return length(s[0]-p) + length(s[1]-p) - length(s[1]-s[0]) < EPS;
}
double distanceSP(const line &s, const point &p) {
  const point r = projection(s, p);
  if (intersectSP(s, r)) { return length(r-p); }
  return min(length(s[0]-p), length(s[1]-p));
}
// テ」ツδ凖」ツつッテ」ツδ暗」ツδォテ」ツ?セテ」ツつ湘」ツつ甘」ツ?ョテ・ツ崢榲ィツサツ「 * axis : テ・ツ崢榲ィツサツ「ティツサツクテ」ツ?ョテ・ツ債佚、ツスツ催」ツδ凖」ツつッテ」ツδ暗」ツδォ
point rotate(point axis, double ang, point a) {
  return a * cos(ang) + (1.0 - cos(ang)) * dot(a, axis) * axis + cross(axis, a) * sin(ang);
}
// テァツオツ古・ツコツヲテ」ツ?ィテァツキツッテ・ツコツヲテ」ツ?凝」ツつ嘉・ツコツァテヲツィツ凖」ツつ津ィツィツ暗ァツョツ療」ツ?づァツ青ε」ツ?ョテ、ツクツュテ・ツソツε」ツ?古・ツ篠淌ァツつケテ」ツ??
// lon : テッツシツ静・ツコツヲテ」ツ?凝」ツつ嘉ヲツ敖アテ」ツ?セテ」ツつ湘」ツつ甘」ツ??ッツシツ静」ツ?愿ッツシツ禿ッツシツ姪ッツシツ?
// lat : テ・ツ個療ヲツ・ツオテ」ツ?凝」ツつ嘉・ツ債療ヲツ・ツオテヲツ鳴ケテ・ツ青妥」ツ??ッツシツ静」ツ?愿ッツシツ妥ッツシツ佚ッツシツ?
// lon=0,lat=90 テ」ツ?古ッツスツ佚ィツサツクテ」ツ?〕on=90,lat=90 テ」ツ?古ッツスツ凖ィツサツクテ」ツ??・ツ個療ヲツ・ツオテ」ツ?古ッツスツ堙ィツサツク
point coord(double R, double lon, double lat) {
  point res(3);
  res[0] = R*cos(lon)*sin(lat);
  res[1] = R*sin(lon)*sin(lat);
  res[2] = R*cos(lat);
  return res;
}

// xyテ・ツケツウテゥツ敖「テ」ツ?クテ」ツ?ョテ・ツーツ?・ツスツア
P projection(const point &p, const point &ray) {
  double k = - p[2] / ray[2];
  assert(k>0);
  double x = p[0] + k * ray[0];
  double y = p[1] + k * ray[1];
  return P(x,y); 
}

bool convex_contain(const G &g, const P &p) { // テ・ツ債甘ヲツ卍づィツィツ暗・ツ崢榲」ツつ甘」ツつ津、ツサツョテ・ツョツ?
  REP(i,g.size())
    if (ccw(g[i], next(g, i), p) == -1) return 0;
  return 1;
}

G shadows[15];
int n,m;

double sunshine(const L &seg) {
  vector<double> v;
  double len = abs(seg[1]-seg[0]);  
  v.push_back(0);
  v.push_back(len);
  REP(i,n) {
    REP(j,shadows[i].size()) {
      L l(shadows[i][j], shadows[i][(j+1)%shadows[i].size()]);
      if (intersectSS(seg,l)) {
        v.push_back(abs(crosspoint(seg,l)-seg[0]));
      }
    }
  }
  sort(ALL(v));
  v.erase(unique(ALL(v)), v.end());
  double ans = 0;
  REP(i,v.size()-1) {
    double ss = (v[i]+v[i+1])*0.5 / len;
    P p = (1-ss)*seg[0] + ss*seg[1];
    // cout << p << endl;
    bool in = 0;    
    REP(j,n) {
      if (convex_contain(shadows[j],p)) {
        in = 1;
        break;
      }
    }
    if (in) {
    } else {
      ans += v[i+1]-v[i];
    }
  }
  return ans;
}

double h[15];
G buil[15];

int main() {
  while(cin>>n>>m,n||m) {
    REP(i,n) {
      int nv; cin >> nv;
      cin >> h[i];
      buil[i].clear();
      REP(j,nv) {
        P p;
        cin >> p.real() >> p.imag();
        buil[i].push_back(p);
      }
    }
    vector<L> segs;
    REP(i,m) {
      P a,b;
      cin >> a.real() >> a.imag();
      cin >> b.real() >> b.imag();
      segs.push_back(L(a,b));
    }
    double theta, phi;
    cin >> theta >> phi;
    theta = theta*PI/180;
    phi = phi*PI/180;
    point ray(-coord(1,theta,PI/2-phi));

    // cout << ray << endl;
    
    REP(i,n) {
      vector<P> vp;
      REP(j,buil[i].size()) {
        double x = buil[i][j].real();
        double y = buil[i][j].imag();
        vp.push_back(P(x,y));
        P p = projection(Point(x,y,h[i]), ray);
        // cout << Point(x,y,h[i]) << " " << ray <<  "   - > " << p << endl;
        vp.push_back(p);
      }
      shadows[i] = graham(vp);
      // REP(j,shadows[i].size()) {
      //   cout << shadows[i][j] << endl;
      // }
    }
    
    P start, end;
    cin >> start.real() >> start.imag() >> end.real() >> end.imag();
    // REP(i,n) {
    //   if (intersectSP(segs[i],start)) {
    //     segs.push_back(L(segs[i][0],start));
    //     segs.push_back(L(start,segs[i][1]));
    //   }
    //   if (intersectSP(segs[i],end)) {
    //     segs.push_back(L(segs[i][0],end));
    //     segs.push_back(L(end,segs[i][1]));        
    //   }
    // }
    vector<P> pv;
    Graph g = segmentArrangement(segs,pv,start,end);
    int sid = -1, eid = -1;
    REP(i,pv.size()) {
      if (abs(pv[i]-start) < 1e-6) sid = i;
      if (abs(pv[i]-end) < 1e-6) eid = i;
    }
    assert(sid != -1 && eid != -1);
    int N = g.size();
    REP(i,N) {
      FOR(it, g[i]) {
        int a = it->src;
        int b = it->dst;
        L seg(pv[a],pv[b]);
        it->weight = sunshine(seg);
        
        // cout << pv[a] << " -> " << pv[b] << "  : " << it->weight << endl;
      }
    }
    // cout << "OK" << endl;    
    double ans = dijkstra(g,sid)[eid];
    printf("%.10Lf\n", ans);
  }
}