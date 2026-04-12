#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

typedef long double ld;
const ld PI = acos(-1.0);
bool eq(ld a, ld b) { return abs(a - b) < EPS; }
typedef complex<ld> Point;
typedef vector<Point> Polygon;

namespace std
{
	bool operator < (const Point& a, const Point& b)
	{
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}

struct Line
{
	Point a, b;
	Line(Point p, Point q) :a(p), b(q) {};
	Line(ld x1, ld y1, ld x2, ld y2) :a(Point(x1, y1)), b(Point(x2, y2)) {};
};

struct Circle
{
	Point p; ld r;
	Circle(Point a, ld b) :p(a), r(b) {};
};

ld dot(Point a, Point b)
{
	return real(conj(a)*b);
}

ld cross(Point a, Point b)
{
	return imag(conj(a)*b);
}

int ccw(Point a, Point b, Point c)
{
	b -= a; c -= a;
	if (cross(b, c) > EPS) return 1;    //counter cloclwise
	if (cross(b, c) < -EPS) return -1;  //cloclwise
	if (dot(b, c) < 0) return 2;        //c--a--b on line 
	if (norm(b) < norm(c)) return -2;   //a--b--c on line
	return 0;                           //a--c--b on line
}

bool isis_ll(Line l, Line m)
{
	return abs(cross(l.b - l.a, m.b - m.a)) > EPS;
}

bool isis_ls(Line l, Line s)
{
	return cross(l.b - l.a, s.a - l.a)*cross(l.b - l.a, s.b - l.a) < EPS;
}

bool isis_ss(Line s, Line t)
{
	return (ccw(s.a, s.b, t.a)*ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a)*ccw(t.a, t.b, s.b) <= 0);
}

bool isis_lp(Line l, Point p)
{
	return (abs(cross(l.b - p, l.a - p)) < EPS);
}

bool isis_sp(Line s, Point p)
{
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a)) < EPS;
}

Point projection(Line l, Point p)
{
	Point base = l.b - l.a;
	ld r = dot(p - l.a, base) / norm(base);
	return l.a + base*r;
}

Point mirror(Line l, Point p)
{
	return Point(2, 0)*projection(l, p) - p;
}

ld dist_lp(Line l, Point p)
{
	return abs(p - projection(l, p));
}

ld dist_ll(Line l, Line m)
{
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

ld dist_ls(Line l, Line s)
{
	if (isis_ls(l, s)) return 0;
	return min(dist_lp(l, s.a), dist_lp(l, s.b));
}

ld dist_sp(Line s, Point p)
{
	Point r = projection(s, p);
	if (isis_sp(s, r)) return abs(r - p);
	return min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss(Line s, Line t)
{
	if (isis_ss(s, t)) return 0;
	return min(min(dist_sp(s, t.a), dist_sp(s, t.b)), min(dist_sp(t, s.a), dist_sp(t, s.b)));
}

Point is_ll(Line s, Line t)
{
	ld a = cross(s.b - s.a, t.b - t.a);
	ld b = cross(s.b - s.a, s.b - t.a);
	return t.a + b / a*(t.b - t.a);
}

typedef vector<Line> star;
const ld rot = 144.0 / 180.0 * PI;

vector<Point> make_star(ld x, ld y, ld a, ld r)
{
	vector<Point> res(5);
	Point p(0, r);
	p = p * (Point(cos(a / 180.0 * PI), sin(a / 180.0 * PI)));
	res[0] = p;
	REP(i, 4) res[i + 1] = res[i] * (Point(cos(rot), sin(rot)));
	REP(i, 5) res[i] += Point(x, y);
	return res;
}

typedef ld Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}

void dijkstra(Graph &g, int s, Array &d)
{
	d.assign(g.size(), INF);
	d[s] = 0;
	typedef pair<Weight, int> P;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (!que.empty())
	{
		Weight dist = que.top().first;
		int v = que.top().second;
		que.pop();
		if (d[v] < dist) continue;
		REP(i, g[v].size())
		{
			Edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

ld dist_star(star a, star b)
{
	ld res = INF;
	REP(i, 5)REP(j, 5)
	{
		chmin(res, dist_ss(a[i], b[j]));
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(false);
	int n, src, dst;
	while (cin >> n >> src >> dst, n)
	{
		src--, dst--;
		vector<star> stars(n);
		REP(i, n)
		{
			ld x, y, a, r; cin >> x >> y >> a >> r;
			vector<Point> ps = make_star(x, y, a, r);
			REP(j, 5)
			{
				stars[i].push_back(Line((ps[j % 5]), ps[(j + 1) % 5]));
			}
		}
		Graph g(n);
		REP(i, n)REP(j, n)
		{
			add_edge(g, i, j, dist_star(stars[i], stars[j]));
		}
		Array dist;
		dijkstra(g, src, dist);
		cout << D10 << dist[dst] << endl;
	}
	return 0;
}