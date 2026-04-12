#include"bits/stdc++.h"
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define int long long
using vi=vector<int>;
using vvi=vector<vi>;

#define INF 0x3f3f3f3f

const double EPS = 1e-8;
const double PI = acos(-1);

struct Point {
	double x, y;
	Point() :x(0.0), y(0.0) {}
	Point(double x, double y) :x(x), y(y) {}

	Point& operator+=(const Point& p) { x += p.x; y += p.y; return *this; }
	Point& operator-=(const Point& p) { x -= p.x; y -= p.y; return *this; }

	double abs() { return sqrt(norm()); }
	double norm() { return x * x + y * y; }
};
Point operator+(const Point& p1, const Point& p2) { return Point(p1) += p2; }
Point operator-(const Point& p1, const Point& p2) { return Point(p1) -= p2; }

struct Vector :public Point {
	using Point::Point;
	Vector() {}
	Vector(const Point& P) { x = P.x; y = P.y; }
	Vector rotate(double rad) { return Vector(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)); }
	//Vector unit() { return *this / abs(); }
};

double dot(Vector a, Vector b) { return a.x* b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x* b.y - a.y * b.x; }

struct Line {
	Point p1, p2;
	Line() {}
	Line(Point p1, Point p2) :p1(p1), p2(p2) {}
};

struct Segment :public Line {
	using Line::Line;
	Segment() {}
	Segment(const Line& L) { p1 = L.p1; p2 = L.p2; }
	//Vector vec() { return p2 - p1; }
};

double rad(double deg) { return PI * deg / 180; }

enum { ONLINE_FRONT = -2, CLOCKWISE, ON_SEGMENT, COUNTER_CLOCKWISE, ONLINE_BACK };
int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if (cross(a, b) > EPS)return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS)return CLOCKWISE;
	if (dot(a, b) < -EPS)return ONLINE_BACK;
	if (a.norm(), b.norm())return ONLINE_FRONT;
	return ON_SEGMENT;
}

bool intersect(Segment a, Segment b) {
	Point p1 = a.p1, p2 = a.p2, p3 = b.p1, p4 = b.p2;
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

double get_distance(Line l, Point p) {
	return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs());
}

double get_distance(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0)return (p - s.p1).abs();
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0)return (p - s.p2).abs();
	return get_distance(Line(s), p);
}

double get_distance(Segment s1, Segment s2) {
	if (intersect(s1, s2))return 0.0;
	return min(
		min(get_distance(s1, s2.p1), get_distance(s1, s2.p2)),
		min(get_distance(s2, s1.p1), get_distance(s2, s1.p2))
	);
}

using Weight = double;
struct Edge {
	int s, d; Weight w;
	Edge() {};
	Edge(int s, int d, Weight w) :s(s), d(d), w(w) {};
};
bool operator<(const Edge & e1, const Edge & e2) {
	return e1.w == e2.w ? (e1.s == e2.s ? e1.d < e2.d : e1.s < e2.s) :
		e1.w < e2.w;
}

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;

void addArc(Graph & g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph & g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}

auto dijkstra = [&](const Graph & g, int s, Array & dist) {
	int n = g.size();
	vector<bool> vis(n);
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>;
	priority_queue<State, vector<State>, greater<State>> pq;
	pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, p; tie(d, v, p) = pq.top(); pq.pop();
		if (dist[v] < d)continue;
		vis[v] = true;
		prev[v] = p;
		for (auto& e : g[v]) {
			if (vis[e.d])continue;
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				pq.emplace(dist[e.d], e.d, v);
			}
		}
	}
	return prev;
};

signed main() {
	cout << fixed << setprecision(10);
	for (int N, M, L; cin >> N >> M >> L && N;) {
		M--, L--;

		vector<double> x(N), y(N), a(N), r(N);
		rep(i, 0, N) {
			cin >> x[i] >> y[i] >> a[i] >> r[i];
		}

		auto id = [&](int i, int j) {return 5 * i + j; };
		vector<Point> V(5 * N);
		rep(i, 0, N) {
			rep(j, 0, 5) {
				double d = a[i] + j * 360 / 5;
				double t = rad(d);
				V[id(i, j)] = Point(x[i] - r[i] * sin(t), y[i] + r[i] * cos(t));
			}
		}

		Graph g(5 * N);

		rep(i, 0, N)rep(j, 0, 5) {
			int a = id(i, j);
			int b = id(i, (j + 2) % 5);
			addEdge(g, a, b, 0);
		}

		rep(i, 0, N)rep(j, i + 1, N) {
			rep(k, 0, 5)rep(l, 0, 5) {
				Segment s1(Line(V[id(i, k)], V[id(i, (k + 2) % 5)])),
					s2(Line(V[id(j, l)], V[id(j, (l + 2) % 5)]));
				addEdge(g, id(i, k), id(j, l), get_distance(s1, s2));
				//cerr << id(i, k) << " " << id(j, l) << " " << get_distance(s1, s2) << endl;
			}
		}

		Array dist;
		dijkstra(g, id(M, 0), dist);
		cout << dist[id(L, 0)] << endl;

	}
	return 0;
}
