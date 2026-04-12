#include <cmath>
#include <queue>
#include <vector>
#include <complex>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef complex<double> point;
typedef vector<point> polygon;

struct line : public vector<point> {
	line() {}
	line(const point& a, const point& b) { push_back(a); push_back(b); }
};

namespace std {
	bool operator<(const point& a, const point& b) {
		return a.real()!=b.real() ? a.real()<b.real() : a.imag()<b.imag();
	}
}

class Edge
{
public:
	int src,dst;
	double cst;
	Edge(int src, int dst, double cst)
		:src(src),dst(dst),cst(cst)
	{}
};

class State
{
public:
	int p;
	double c;
	State(int p, double c)
		:p(p),c(c)
	{}

	bool operator<(const State& s) const
	{
		return c > s.c;
	}
};

typedef vector<vector<Edge> > Graph;
typedef vector<line> Obstacle;

const double pi  = 3.141592653589793;
const double inf = 1e10;
const double eps = 1e-10;
point  unit (const point& v)                 { return v/abs(v);     }
point  ortho(const point& v)                 { return v*point(0,1); }
inline point  vec  (const line&  l)                 { return l[1]-l[0];    }
bool   equal(const double a, const double b) { return abs(a-b)<eps; }
bool   equal(const point& a, const point& b) { return abs(a-b)<eps; }
inline double dot  (const point& a, const point& b) { return (a*conj(b)).real(); }
inline  double cross(const point& a, const point& b) { return (conj(a)*b).imag(); }

inline int ccw(const point& a, const point& b, const point& c) {
	point u=b-a, v=c-a;
	if(cross(u,v) > 0 ) return +1; // ccw
	if(cross(u,v) < 0 ) return -1; // cw
	if(  dot(u,v) < 0 ) return +2; // cab
	if(abs(u) < abs(v)) return -2; // abc
	return 0;                      // acb
}

inline int ccw(const line& s, const point& p) {
	return ccw(s[0], s[1], p);
}

point projection(const line &l, const point &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

bool intersectLP(const line& l, const point& p) {
	return abs(cross(l[1]-p, l[0]-p)) < eps;
}

inline bool intersectSP(const line& s, const point& p) {
	return abs(s[0]-p)+abs(s[1]-p) < abs(s[1]-s[0])+eps;
}

bool intersectLL(const line& l, const line& m) {
	return cross(vec(l), vec(m))    > eps
	    || cross(vec(l), m[0]-l[0]) < eps;
}

bool intersectLS(const line& l, const line& s) {
	return cross(vec(l),s[0]-l[0])
	     * cross(vec(l),s[1]-l[0]) <= 0;
}

inline bool intersectSS(const line& s, const line& t) {
	return ccw(s,t[0])*ccw(s,t[1]) <= 0 
	    && ccw(t,s[0])*ccw(t,s[1]) <= 0;
}

point crosspoint(const line& l, const line& m) {
	double A = cross(vec(l), vec(m));
	double B = cross(vec(l), l[1]-m[0]);
	if(abs(A)<eps) {			// parallel
		assert(abs(B)<eps);
		return m[0];			// sameline
	}
	return m[0] + B/A*vec(m);
}

line generateSP(const line &s, const point &p) {
  const point r = projection(s, p);
  if (intersectSP(s, r)) return line(r, p);
  else {
	if(abs(s[0]-p) < abs(s[1] - p)) return line(s[0], p);
	else return line(s[1], p);
  }

  return s;
}

double distanceSP(const line &s, const point &p) {
  const point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
//hogepiyo
bool isSameLine(const point& a, const point& b, const line& l)
{
	double x = distanceSP(l, a);
	double y = distanceSP(l, b);
	
	return x < eps && y < eps;
}

bool comp(const point& a, const point& b)
{
	return abs(a-b) < eps;
}

vector<point> crosspointSO(const line& sight, const vector<line>& obstacle)
{
	vector<point> res;
	for(int i=0; i<obstacle.size(); i++) {
		if(intersectSS(sight, obstacle[i]))
			res.push_back(crosspoint(sight, obstacle[i]));
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end(), comp), res.end());

	if(res.size() <= 1) return vector<point>();
	if(res.size() > 2) { assert(false); }

	for(int i=0; i<obstacle.size(); i++) {
		if(isSameLine(res[0], res[1], obstacle[i])) return vector<point>();
	}

	return res;
}

line calcSight(const line& sight, const vector<Obstacle>& obstacles)
{
	vector<pair<double, point> > res;

	for(int i=0; i<obstacles.size(); i++) {
		vector<point> xp = crosspointSO(sight, obstacles[i]);
		
		for(int j=0; j<xp.size(); j++) {
			res.push_back(make_pair(abs(xp[j]-sight[0]), xp[j]));
		}
	}

	sort(res.begin(), res.end());

	if(res.size() == 0) return sight;

	return line(sight[0], res[0].second);
}


bool canMove(const line& sight, const vector<Obstacle>& obstacles)
{
	for(int i=0; i<obstacles.size(); i++) {
		vector<point> xp = crosspointSO(sight, obstacles[i]);
		
		if(xp.size() != 0) return false;
	}

	return true;
}

void makeEdge(int u, int v, double cst, Graph& graph)
{
	graph[u].push_back(Edge(u, v, cst));
	graph[v].push_back(Edge(v, u, cst));
}

bool vis[10000];

double dijkstra(int S, int N, Graph& graph)
{
	memset(vis, 0, sizeof(vis));
	priority_queue<State> q;
	q.push(State(S, 0));

	while(!q.empty()) {
		State s = q.top(); q.pop();
		if(vis[s.p]) continue;
		vis[s.p] = true;

		if(s.p > 4*N) return s.c;

		for(int i=0; i<graph[s.p].size(); i++) {
			Edge& e = graph[s.p][i];
			if(vis[e.dst]) continue;

			q.push(State(e.dst, s.c + e.cst));
		}
	}

	return -1;
}

double solve(int N, vector<point>& vertex, vector<Obstacle>& obstacles, Graph& graph, const point& alice, const point& bob)
{
	if(canMove(line(alice, bob), obstacles)) return 0;

	for(int i=0; i<vertex.size(); i++) {
		line l = line(alice, vertex[i]);
		if(canMove(l, obstacles)) {
			makeEdge(i, 4*N, abs(alice-vertex[i]), graph);
		}
	}

	for(int i=0; i<vertex.size(); i++)
	for(int j=i+1; j<vertex.size(); j++) {
		if(i/4 == j/4) continue;

		if(canMove(line(vertex[i], vertex[j]), obstacles)) {
			makeEdge(i, j, abs(vertex[i]-vertex[j]), graph);
		}
	}

	int M = vertex.size();
	vertex.push_back(alice);
	for(int i=0; i<M; i++) {
		line l = line(bob, vertex[i]);
		if(abs(l[1]-l[0]) > eps) {
			l[1] = l[1] + 50000.0*unit(l[1]-l[0]);
		}
		l = calcSight(l, obstacles);

		for(int j=0; j<M+1; j++) {
			line r = generateSP(l, vertex[j]);

			if(canMove(r, obstacles)) {
				makeEdge(j, 4*N+1+i, abs(r[1]-r[0]), graph);
			}
		}
	}

	return dijkstra(4*N, N, graph);
}

int main()
{

	int N;
	while(scanf("%d", &N), N) {
		Graph graph(4*N + 4*N + 1);
		vector<point> points;
		points.reserve(4*N + 5);

		vector<Obstacle> obstacles(N);
		for(int i=0; i<N; i++) {
			double x,y,a,b;
			scanf("%lf%lf%lf%lf", &x, &y, &a, &b);

			points.push_back(point(x, y));
			points.push_back(point(a, y));
			points.push_back(point(a, b));
			points.push_back(point(x, b));

			makeEdge(4*i + 0, 4*i + 1, abs(points[4*i + 0] - points[4*i + 1]), graph);
			makeEdge(4*i + 1, 4*i + 2, abs(points[4*i + 1] - points[4*i + 2]), graph);
			makeEdge(4*i + 2, 4*i + 3, abs(points[4*i + 2] - points[4*i + 3]), graph);
			makeEdge(4*i + 3, 4*i + 0, abs(points[4*i + 3] - points[4*i + 0]), graph);

			Obstacle obstacle(4);
			obstacle[0] = line(points[4*i + 0], points[4*i + 1]);
			obstacle[1] = line(points[4*i + 1], points[4*i + 2]);
			obstacle[2] = line(points[4*i + 2], points[4*i + 3]);
			obstacle[3] = line(points[4*i + 3], points[4*i + 0]);

			obstacles[i] = obstacle;
		}

		double x,y,a,b;
		point alice, bob;
		scanf("%lf%lf%lf%lf", &x, &y, &a, &b);
		alice = point(x, y);
		bob = point(a, b);

		printf("%.20lf\n", solve(N, points, obstacles, graph, alice, bob));

	}
}