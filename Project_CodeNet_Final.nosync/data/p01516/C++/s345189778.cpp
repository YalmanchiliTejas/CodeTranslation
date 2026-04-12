#include <bits/stdc++.h>
#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef long double ld;
typedef complex<ld> Point;

const ld eps = 1e-9, pi = acos(-1.0);

namespace std {
  bool operator<(const Point &lhs, const Point &rhs) {
    if (lhs.real() < rhs.real() - eps) return true;
    if (lhs.real() > rhs.real() + eps) return false;
    return lhs.imag() < rhs.imag();
  }
}

Point input_point() {
  ld x, y;
  cin >> x >> y;
  return Point(x, y);
}

bool eq(ld a, ld b) {
  return (abs(a - b) < eps);
}

ld dot(Point a, Point b) {
  return real(conj(a) * b);
}

ld cross(Point a, Point b) {
  return imag(conj(a) * b);
}

class Line {
public:
  Point a, b;
  Line () : a(Point(0, 0)), b(Point(0, 0)) {}
  Line (Point a, Point b) : a(a), b(b) {}
};

class Circle {
public:
  Point p;
  ld r;
  Circle () : p(Point(0, 0)), r(0) {}
  Circle (Point p, ld r) : p(p), r(r) {}
};

int ccw (Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b, c) > eps) return 1;
  if (cross(b, c) < -eps) return -1;
  if (dot(b, c) < 0) return 2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

bool isis_ll (Line l, Line m) {
  return !eq(cross(l.b - l.a, m.b - m.a), 0);
}

bool isis_ls (Line l, Line s) {
  return isis_ll(l, s) &&
    (cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}

bool isis_ss(Line s, Line t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
    ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool isis_lp (Line l, Point p) {
  return (abs(cross(l.b - p, l.a - p)) < eps);
}

bool isis_sp (Line s, Point p) {
  return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

Point proj (Line l, Point p) {
  ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + t * (l.a - l.b);
}

Point is_ll (Line s, Line t) {
  Point sv = s.b - s.a, tv = t.b - t.a;
  assert(cross(sv, tv) != 0);
  return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

ld dist_lp (Line l, Point p) {
  return abs(p - proj(l, p));
}

ld dist_ll (Line l, Line m) {
  return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

ld dist_ls (Line l, Line s) {
  return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

ld dist_sp (Line s, Point p) {
  Point r = proj(s, p);
  return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss (Line s, Line t) {
  if (isis_ss(s, t)) return 0;
  return min({dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b)});
}


typedef ld Weight;
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

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

const Weight INF =1e14;

void shortestPath(const Graph &g, int s,
		  vector<Weight> &dist, vector<int> &prev) {
  int n = g.size();
  dist.assign(n, INF); dist[s] = 0;
  prev.assign(n, -1);
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (prev[e.dst] != -1) continue;
    prev[e.dst] = e.src;
    for(auto f=g[e.dst].begin(); f!=g[e.dst].end();f++) {
      if (dist[f->dst] > e.weight+f->weight) {
	dist[f->dst] = e.weight+f->weight;
	Q.push(Edge(f->src, f->dst, e.weight+f->weight));
      }
    }
  }
}


int main(){
  int N,M,L;
  while(cin >> N >> M >> L,N){
    M--;
    L--;
    Graph g(5*N);
    vector<Line> ls(5*N);
    for(int i=0;i<N;i++){
      ld x,y,a,r;
      cin >> x >> y >> a >> r;
      vector<Point> ps(5);
      for(int j=0;j<5;j++){
	ld b=a+j*72;
	b=b*pi/180;
	ps[j]=Point(x-r*sin(b), y+r*cos(b));
      }
      for(int j=0;j<5;j++)
	ls[i*5+j]=Line(ps[j], ps[(j+2)%5]);
    }
    for(int from=0;from<5*N;from++){
      for(int to=from+1;to<5*N;to++){
	g[from].push_back(Edge(from,to,dist_ss(ls[to],ls[from])));
	g[to].push_back(Edge(to,from,dist_ss(ls[to],ls[from])));
      }
    }
    vector<Weight> dist;
    vector<int> prev;
    shortestPath(g,M*5,dist,prev);
    printf("%.10Lf\n",dist[L*5]);
  }
  return 0;
}