#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) begin(a),end(a)
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> P;
typedef long long ll;
const int INF = 114514810;
const int MOD = 1000000007;
const double EPS = 1e-10;
typedef double weight;
struct edge
{
	int to; weight cost;
	bool operator < (const edge& e) const { return cost < e.cost; }
	bool operator >(const edge& e) const { return cost > e.cost; }
};
typedef vector<vector<edge>> Graph;
int dx[] = { -1, 0, 0, 1 }; int dy[] = { 0, -1, 1, 0 };
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
bool valid(int x, int y, int h, int w) { return (x >= 0 && y >= 0 && x < h&&y < w); }
int place(int x, int y, int w) { return w*x + y; }
///*************************************************************************************///
///*************************************************************************************///
///*************************************************************************************///

const double PI = acos(-1.0);
bool eq(double a, double b) { return fabs(a - b) < EPS; }
typedef complex<double> Point;
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
	Line(double x1, double y1, double x2, double y2) :a(Point(x1, y1)), b(Point(x2, y2)) {};
};

struct Circle
{
	Point p; double r;
	Circle(Point a, double b) :p(a), r(b) {};
};

double dot(Point a, Point b)
{
	return real(conj(a)*b);
}

double cross(Point a, Point b)
{
	return imag(conj(a)*b);
}

int ccw(Point a, Point b, Point c)
{
	b -= a; c -= a;
	if (cross(b, c) > EPS) return 1;	//counter cloclwise
	if (cross(b, c) < -EPS) return -1;  //cloclwise
	if (dot(b, c) < 0) return 2;		//c--a--b on line 
	if (norm(b) < norm(c)) return -2;   //a--b--c on line
	return 0;							//a--c--b on line
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
	double r = dot(p - l.a, base) / norm(base);
	return l.a + base*r;
}

Point mirror(Line l, Point p)
{
	return 2.0*projection(l, p) - p;
}

double dist_lp(Line l, Point p)
{
	return abs(p - projection(l, p));
}

double dist_ll(Line l, Line m)
{
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

double dist_ls(Line l, Line s)
{
	if (isis_ls(l, s)) return 0;
	return min(dist_lp(l, s.a), dist_lp(l, s.b));
}

double dist_sp(Line s, Point p)
{
	Point r = projection(s, p);
	if (isis_sp(s, r)) return abs(r - p);
	return min(abs(s.a - p), abs(s.b - p));
}

double dist_ss(Line s, Line t)
{
	if (isis_ss(s, t)) return 0;
	return min(min(dist_sp(s, t.a), dist_sp(s, t.b)), min(dist_sp(t, s.a), dist_sp(t, s.b)));
}

Point is_ll(Line s, Line t)
{
	Point sv = s.b - s.a, tv = t.b - t.a;
	return s.a + sv*cross(tv, t.a - s.a) / cross(tv, sv);
}


void dijkstra(Graph &g, vector<weight> &d, int s)
{
	d.assign(g.size(), INF);
	d[s] = 0;
	typedef pair<weight, int> P;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (!que.empty())
	{
		weight dist = que.top().first;
		int v = que.top().second;
		que.pop();
		if (d[v] < dist) continue;
		REP(i, g[v].size())
		{
			edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}



int main()
{
	int n, m, l;
	while (cin >> n >> m >> l, n)
	{
		m--; l--;
		vector<Line> ls;
		REP(i, n)
		{
			double x, y, a, r;
			cin >> x >> y >> a >> r;
			vector<Point> p(5);
			REP(i, 5) p[i] = (Point(x, y) + Point(0, r) * Point(cos((a + i * 72) / 180 * PI), sin((a + i * 72) / 180 * PI)));
			REP(i, 5)
			{
				ls.push_back(Line(p[i], p[(i + 2) % 5]));
			}
		}
		vector<weight> d(ls.size());
		Graph g(ls.size());
		REP(i, ls.size())REP(j, i)
		{
			g[i].push_back(edge{ j, dist_ss(ls[i], ls[j]) });
			g[j].push_back(edge{ i, dist_ss(ls[i], ls[j]) });
		}
		dijkstra(g, d, m * 5);
		cout << D10 << d[l * 5] << endl;
	}
	return 0;
}