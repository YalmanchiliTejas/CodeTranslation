#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>

using namespace std;

typedef complex<double> Point;
typedef pair<double, int> P;

struct Segment{
  Point p1, p2;
};

typedef Segment Line;

class ST{
public:
  double x, y, a, r;
  ST(){}
  ST(double x, double y, double a, double r) : x(x), y(y), a(a), r(r) {}
};

const int N = 100;
const double INF = 10000000.0;
const double EPS = 1e-8;

int n, s, t;
vector<ST> input;
double dist[N][N];

double dot(Point a, Point b){
  return a.real() * b.real() + a.imag() * b.imag();
}

double cross(Point a, Point b){
  return a.real() * b.imag() - a.imag() * b.real();
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
  Point a = p1 - p0;
  Point b = p2 - p0;
  if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a, b) < -EPS) return CLOCKWISE;
  if(dot(a, b) < -EPS) return ONLINE_BACK;
  if(norm(a) < norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4){
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool isIntersect(Segment s1, Segment s2){
  return isIntersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistanceLP(Line s, Point p){
  return abs(cross(s.p2 - s.p1, p - s.p1) / abs(s.p2 - s.p1));
}

double getDistanceSP(Segment s, Point p){
  if(dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if(dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2){
  if(isIntersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
             min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

Point rotate(Point p, Point o, double dir){
  Point res;
  dir = M_PI * dir / 180.0;
  p -= o;
  res.real() = p.real() * cos(dir) - p.imag() * sin(dir);
  res.imag() = p.real() * sin(dir) + p.imag() * cos(dir);
  res += o;
  return res;
}

void get_seg(ST st, vector<Segment>& vec){
  vector<Point> data;
  Point o = Point(st.x, st.y);
  Point p = Point(st.x, st.y + st.r);
  for(int i=0;i<5;i++){
    data.push_back(rotate(p, o, st.a+72.0*i));
  }
  int idx[2][5] = {{0, 0, 1, 1, 2}, {2, 3, 3, 4, 4}};
  for(int i=0;i<5;i++){
    vec.push_back((Segment){data[idx[0][i]], data[idx[1][i]]});
  }
}

double calc_dist(ST pa, ST pb){
  vector<Segment> a, b;
  get_seg(pa, a);
  get_seg(pb, b);
  double res = INF;
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      res = min(res, getDistance(a[i], b[j]));
    }
  }
  return res;
}

void make_graph(){
  fill(dist[0], dist[N], INF);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dist[i][j] = dist[j][i] = calc_dist(input[i], input[j]);
    }
  }
}

double solve(){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist[s][t];
}

main(){
  while(cin >> n >> s >> t && (n|s|t)){
    input.clear();
    s--;
    t--;
    for(int i=0;i<n;i++){
      double x, y, a, r;
      cin >> x >> y >> a >> r;
      input.push_back(ST(x, y, a, r));
    }
    make_graph();
    printf("%.15f\n", (double)solve());
  }
}