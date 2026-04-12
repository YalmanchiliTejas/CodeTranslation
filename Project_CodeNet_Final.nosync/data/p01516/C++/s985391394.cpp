#include <bits/stdc++.h>
#define range(i,x,y) i=(x);i<(y);i++
#define rep(i,n) for(int i=0,i##_len=n;i<i##_len;i++)
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;

typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);

bool eq(ld a, ld b) {
  return (abs(a - b) < eps);
}

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

vector<Line> make_star(ld x, ld y, ld a, ld r){
  int d = 5;
  ld rad = 4 * pi / 5;
  Point p(x, y);
  Point v(0, r);
  ld aa = a / 180.0 * pi;
  v *= Point(cos(aa), sin(aa));
  Point rot(cos(rad), sin(rad));
  vector<Line> res;
  rep(i, d){
    res.emplace_back(v + p,v * rot + p);
    v *= rot;
  }
  return res;
}

template <typename Cost>
struct CEdge {
  int from, to;
  Cost cost;
  CEdge(int s, int t, Cost c) : from(s), to(t), cost(c) {}
};

template<typename Cost> using CGraph = vector<vector<CEdge<Cost>>>;

template <typename Cost>
void add_edge(CGraph<Cost> &g, int from, int to, Cost cost) {
  g[from].emplace_back(from, to, cost);
}

const int inf = 1e9;

template <typename Cost>
vector<Cost> dijkstra(const CGraph<Cost> &g, int s, Cost zero = 0) {
  vector<Cost> d(g.size(), inf);
  d[s] = zero;
  using P = pair<Cost,int>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(zero, s));
  while (!que.empty()) {
    Cost dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e: g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}

ld dist_stars (vector<Line> s, vector<Line> t){
  ld res = 1e30l;
  for(auto&& ss: s){
    for(auto&& tt: t){
      res = min(res, dist_ss(ss, tt));
    }
  }
  return res;
}

void svg(){
cerr << "<?xml version='1.0' standalone='no'?>" << endl;
cerr << "<svg  width='1000px' height='1000px' viewBox='0 -400 400 400' xmlns='http://www.w3.org/2000/svg'>" << endl;
cerr << "<style>line { stroke: black; }</style>" << endl;
cerr << "<line x1='100' y1='0' x2='0' y2='-100'/>" << endl;

}
void gvs(){
cerr << "</svg>" << endl;
}

void draw_line(Line l){
  const ld z = 10;
  cerr << "<line x1='" << real(l.a) * z << "' y1='" << -imag(l.a) * z
    << "' x2='" << real(l.b) * z << "' y2='" << -imag(l.b) * z<< "' />" << endl;
}


signed main(){
  int n, m, l;
  while(cin >> n >> m >> l, n != 0){
    vector<vector<Line>> stars(n);
    rep(i, n){
      int x, y, a, r; cin >> x >> y >> a >> r;
      stars[i] = make_star(x, y, a, r);
    }
    CGraph<ld> g(n);
    vector<vector<ld>> dp(n, vector<ld>(n, inf));

    rep(i, n){
      rep(j, n){
        dp[i][j] = dist_stars(stars[i], stars[j]);
      }
    }
    rep(k, n)rep(i,n)rep(j,n){
      dp[i][j]=min(dp[i][k]+dp[k][j], dp[i][j]);
    }
    cout << std::setprecision(24) << dp[m-1][l-1] << endl;
  }
}