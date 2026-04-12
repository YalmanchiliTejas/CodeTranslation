#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <utility>
#define llint long long
#define inf 1e9
#define eps 1e-8

using namespace std;
typedef pair<double, int> P;

struct vec2d{
  double x, y;
  vec2d(){}
  vec2d(double x, double y){
    this->x = x, this->y = y;
  }
  double add(double a, double b){
    if(fabs(a+b) < eps * (fabs(a) + fabs(b))) return 0.0;
    return a+b;
  }
  vec2d operator+(vec2d ope){
    return vec2d(add(x, ope.x), add(y, ope.y));
  }
  vec2d operator-(vec2d ope){
    return vec2d(add(x, -ope.x), add(y, -ope.y));
  }
  vec2d operator*(double t){
    return vec2d(x*t, y*t);
  }
  vec2d operator/(double t){
    return vec2d(x/t, y/t);
  }
  double dot(vec2d ope){
    return add(x*ope.x, y*ope.y);
  }
  double cross(vec2d ope){
    return add(x*ope.y, -y*ope.x);
  }
  double norm(){
    double d2 = dot(*this);
    if(d2 > 0) return sqrt(d2);
    return 0.0;
  }
};

double distPP(vec2d p, vec2d q){
  return (p-q).norm();
}
double distSP(vec2d p, vec2d q, vec2d x)
{
  if((x-p).dot(q-p)<=0) return distPP(p, x);
  if((x-q).dot(p-q)<=0) return distPP(q, x);
  return fabs((x-p).cross(q-p) / distPP(p,q));
}
bool isOnS(vec2d p, vec2d q, vec2d x)
{
  return (p-x).cross(q-x) == 0 && (p-x).dot(q-x) <= 0;
}
bool isCross(vec2d p, vec2d q, vec2d r, vec2d s)
{
  if((q-p).cross(s-r) == 0){
    return isOnS(p, q, r) || isOnS(p, q, s) || isOnS(r, s, p) || isOnS(r, s, q);
  }
  double t = (r-p).cross(s-r) / (q-p).cross(s-r);
  vec2d x = p + (q-p)*t;
  return isOnS(p, q, x) && isOnS(r, s, x);
}
double distSS(vec2d p, vec2d q, vec2d r, vec2d s)
{
  if(isCross(p, q, r, s)) return 0;
  double ret = distSP(p, q, r);
  ret = min(ret, distSP(p, q, s));
  ret = min(ret, distSP(r, s, p));
  ret = min(ret, distSP(r, s, q));
  return ret;
}

struct edge{
  int to;
  double cost;
  edge(){}
  edge(int a, double b){
    to = a, cost = b;
  }
};

int n, s, t;
vec2d l[505], r[505];
vector<edge> G[505];
int V;
double dist[505];

void dijkstra()
{
  for(int i = 0; i < V; i++) dist[i] = inf;
  dist[s*5] = 0;

  priority_queue<P, vector<P>, greater<P> > Q;
  Q.push(make_pair(0.0, s*5));

  int v; double d;
  while(Q.size()){
    d = Q.top().first;
    v = Q.top().second;
    Q.pop();
    if(dist[v] < d) continue;
    for(int i = 0; i < G[v].size(); i++){
      if(dist[G[v][i].to] > d + G[v][i].cost){
        dist[G[v][i].to] = d + G[v][i].cost;
        Q.push(make_pair(dist[G[v][i].to], G[v][i].to));
      }
    }
  }
}

int main(void)
{
  while(1)
  {
    cin >> n >> s >> t;
    if(n == 0 && s == 0 && t == 0) break;
    s--, t--;

    int x, y, a, R;
    for(int i = 0; i < n; i++){
      cin >> x >> y >> a >> R;
      a += 90;
      double ang = a * M_PI / 180.0, th = 72 * M_PI / 180.0;
      for(int j = 0; j < 5; j++){
        l[i*5+j] = vec2d(R * cos(ang+j*th), R * sin(ang+j*th)) + vec2d(x, y);
        r[i*5+j] = vec2d(R * cos(ang+(j+2)*th), R * sin(ang+(j+2)*th)) + vec2d(x, y);
      }
    }
    V = 5*n;
    for(int i = 0; i < V; i++){
      G[i].clear();
      for(int j = 0; j < V; j++){
        double dist = distSS(l[i], r[i], l[j], r[j]);
        //cout << dist << " ";
        G[i].push_back(edge(j, dist));
      }
      //cout << endl;
    }

    dijkstra();

    //for(int i = 0; i < 5*n; i++) cout << dist[i] << " "; cout << endl;

    double ans = dist[t*5];
    printf("%.11f\n", ans);
  }

  return 0;
}

