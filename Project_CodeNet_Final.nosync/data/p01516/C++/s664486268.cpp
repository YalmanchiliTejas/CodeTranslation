#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

#include <complex>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

#define INF (1<<29)

const double PI = acos(-1.0);
const double EPS = 1e-9;
typedef complex<double> Point;

struct Line {
  Point pos,dir; // position, direction
  Line(){}
  Line(const Point& pos, const Point& dir){
    this->pos = pos; this->dir = dir;
  }
};

double convertD2R(double deg){
  return (deg * PI) / 180.0;
}

double dot(const Point& a, const Point& b){
  return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(const Point& a, const Point& b){
  return (a.real() * b.imag() - a.imag() * b.real());
}

int ccw(Point a, Point b, Point c){
  b -= a; c -= a;
  if(cross(b,c) > 0) return +1;    // counter clock wise
  if(cross(b,c) < 0) return -1;    // clock wise
  if(dot(b,c) < 0) return +2;      // c--a--b
  if(norm(b) < norm(c)) return -2; // a--b--c
  return 0;                        // a--c--b || b == c
}

Point projection(const Line& l, const Point& p){
  double t = dot(p - l.pos, l.pos - l.dir) / norm(l.pos - l.dir);
  return l.pos + t * (l.pos - l.dir);
}

bool intersectSP(const Line& s, const Point& p){
  return (abs(s.pos - p) + abs(s.dir - p) - abs(s.dir - s.pos) < EPS);
}

bool intersectSS(const Line& a, const Line& b){
  return (ccw(a.pos,a.dir,b.pos) * ccw(a.pos,a.dir,b.dir) <= 0 && ccw(b.pos,b.dir,a.pos) * ccw(b.pos,b.dir,a.dir) <= 0);
}

double distanceSP(const Line& s, const Point& p){
  Point r = projection(s,p);
  if(intersectSP(s,r)) return abs(r - p);
  return min(abs(s.pos - p), abs(s.dir - p));
}

double distanceSS(const Line& a, const Line& b){
  if(intersectSS(a,b)) return 0;
  return min(min(distanceSP(a,b.pos), distanceSP(a,b.dir)), min(distanceSP(b,a.pos), distanceSP(b,a.dir)));
}

struct Star {
  Line s[5]; // segment

  Star(){}
  Star(double x, double y, double a, double r){
    int i;
    REP(i,5){
      double theta1 = convertD2R(a) + i * 2*PI/5.0 + PI/2.0; // a + 72 + 90
      double theta2 = convertD2R(a) + (i+2) * 2*PI/5.0 + PI/2.0; // a + 72 + 90
      s[i] = Line(polar(r,theta1) + Point(x,y), polar(r,theta2) + Point(x,y));
    }
  }
};

int V; // vertex
Star star[110]; // x,y,a,r

priority_queue< pair<double,int> > q;
bool used[110];
double dist[110];

void add(int x, double d){
  if(d < dist[x]){
    dist[x] = d;
    q.push(make_pair(-d,x));
  }
}

void dijkstra(int start){
  int next,i,j;

  REP(i,V) used[i] = false;
  REP(i,V) dist[i] = INF;
  add(start,0.0);

  while(!q.empty()){
    double d = -q.top().first; int now = q.top().second; q.pop();
    if(used[now]) continue;
    used[now] = true;
    REP(next,V) if(now != next){
      double d2 = INF;
      REP(i,5) REP(j,5) d2 = min(d2, distanceSS(star[now].s[i],star[next].s[j]));
      add(next, d+d2);
    }
  }
}

int main(){
  int start,goal,i;

  while(1){
    cin >> V >> start >> goal;
    if(V == 0 && start == 0 && goal == 0) break;
    start--; goal--;

    REP(i,V){
      double x,y,a,r;
      cin >> x >> y >> a >> r;
      star[i] = Star(x,y,a,r);
    }

    dijkstra(start);
    printf("%.17lf\n",dist[goal]);
  }

  return 0;
}