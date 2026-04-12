#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
#include <complex>
typedef complex<double> Point;
typedef vector<Point> Polygon;
struct Line : public vector<Point> {
  Line() {;}
  Line(Point a, Point b) { push_back(a); push_back(b); }
};

inline double cross(const Point& a, const Point& b){
  return imag(conj(a) * b);
}

inline double dot(const Point& a, const Point& b){
  return real(conj(a) * b);
}

int ccw(Point a, Point b, Point c){
  b -= a; c -= a;
  double len = abs(b) * abs(c);
  if(cross(b, c) > +EPS * len) return +1; // counter-clockwise
  if(cross(b, c) < -EPS * len) return -1; // clockwise
  if(dot(b, c) < 0) return +2; // c--a--b
  if(norm(b) < norm(c)) return -2; // a--b--c
  return 0; // a--c--b 
}

bool intersectSS(const Line &s, const Line &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
    ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

bool intersectSP(const Line &s, const Point &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

Point projection(const Line &l, const Point &p) {
  double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

double distanceSP(const Line &s, const Point &p) {
  const Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

double distanceSS(const Line &s, const Line &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
typedef pair<double, int> P;
int main(){
  int N, M, L;
  while(cin>>N>>M>>L && N){
    M--; L--;
    double x[100], y[100], a[100], r[100];
    REP(i, N){
      cin>>x[i]>>y[i]>>a[i]>>r[i];
    }
    vector<Line> lines(N * 5);
    REP(i, N){
      Point ps[5];
      REP(j, 5) ps[j] = Point(x[i] + r[i] * cos(M_PI*(90.0 + a[i] + 72 * j)/180.0), y[i] + r[i] * sin(M_PI*(90.0 + a[i] + 72 * j)/180));
      REP(j, 5) lines[5 * i + j] = Line(ps[j], ps[(j + 2) % 5]);
    }
    vector<double> dist(N * 5, INF);
    priority_queue<P, vector<P>, greater<P> > que;
    REP(i, 5){
      dist[5 * M + i] = 0;
      que.push(P(0, 5 * M + i));
    }
    double distance[500][500];
    REP(i, 5 * N) REP(j, 5 * N) distance[i][j] = distanceSS(lines[i], lines[j]);
    while(!que.empty()){
      P p = que.top(); que.pop();
      int u = p.second;
      if(dist[u] != p.first) continue;
      REP(i, N * 5){
        double next = dist[u] + distance[u][i];
        if(next < dist[i]){
          dist[i] = next;
          que.push(P(next, i));
        }
      }
    }
    printf("%.10f\n", dist[5*L]);
  }
  return 0;
}