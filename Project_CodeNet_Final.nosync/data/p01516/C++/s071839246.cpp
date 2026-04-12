#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>
#include<iomanip>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

typedef double Real;

struct edge {
    int v;
    Real w;
    edge() {}
    edge(int v, Real w) : v(v), w(w) {};
};

vector<Real> dijkstra(int n, vector<vector<edge> >& G, int s) {
    vector<Real> d(n, LLONG_MAX/10); d[s] = 0;
    priority_queue<pair<Real, int> > que;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        auto p = que.top(); que.pop();
        int u = p.second;
        ll dist = -p.first;
        if (dist > d[u]) continue;
        for (edge e : G[u]) {
            if (d[e.v] > d[u]+e.w) {
                d[e.v] = d[u] + e.w;
                que.push(make_pair(-d[e.v], e.v));
            }
        }
    }
    return d;
}


Real eps = 1e-9;

Real add(Real a, Real b) {
    if (abs(a+b) < eps * (abs(a)+abs(b))) return 0;
    return a+b;
}

bool equal(Real a, Real b) {
    return add(a, -b) == 0;
}

struct P {
    Real x, y;
    P() {}
    P(Real x, Real y) : x(x), y(y) {}
    P operator+(P p) const {return P(add(x, p.x), add(y, p.y));}
    P operator-(P p) const {return P(add(x, -p.x), add(y, -p.y));}
    P operator*(Real d) const {return P(x*d, y*d);}
    Real dot(P p) const {return add(x*p.x, y*p.y);} // ??????
    Real det(P p) const {return add(x*p.y, -y*p.x);} // ??????
    Real dist(P p) const {return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));} // ?????¢
    void normalize() {Real d = sqrt(x*x+y*y); x /= d; y /= d;} // ??£??????
    bool operator<(const P& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
    bool operator==(const P& rhs) const {
        return equal(x, rhs.x) && equal(y, rhs.y);
    }
};

// ??????p1-p2?????????q???????????????????????????
bool on_seg(P p1, P p2, P q) {
    return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}

// ??´???p1-p2??¨??´???q1-q2??????????????????????????????
bool parallel(P p1, P p2, P q1, P q2) {
    P a = p2-p1;
    P b = q2-q1;
    return a.det(b) == 0;
}

// ??´???p1-p2??¨??´???q1-q2?????????
P intersection(P p1, P p2, P q1, P q2) {
    return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}

inline Real square(Real x) {return x*x;}
// ??´???p1-p2??¨???q????????¢
Real dist(P p1, P p2, P q) {
    q = q-p1;
    p2 = p2-p1;
    return sqrt((q.dot(q)*p2.dot(p2) - square(q.dot(p2))) / p2.dot(p2));
}
// ??????p1-p2??¨???q????????¢
Real distSeg(P p1, P p2, P q) {
    Real d = (q-p1).dot(p2-p1) / p2.dist(p1);
    if (d < 0) return q.dist(p1);
    if (d > p2.dist(p1)) return q.dist(p2);
    return dist(p1, p2, q);
}

// ??????p1-p2??¨??????q1-q2????????¢
Real distSeg(P p1, P p2, P q1, P q2) {
    if (p1==p2 && q1==q2) return q1.dist(p1);
    if (p1==p2) return distSeg(q1, q2, p1);
    if (q1==q2) return distSeg(p1, p2, q1);
    if (!parallel(p1, p2, q1, q2)) {
        P r = intersection(p1, p2, q1, q2);
        if (on_seg(p1, p2, r) && on_seg(q1, q2, r)) return 0;
    }
    Real ret = min(distSeg(p1, p2, q1), distSeg(p1, p2, q2));
    ret = min(ret, min(distSeg(q1, q2, p1), distSeg(q1, q2, p2)));
    return ret;
}

const int MAXN = 111;
const Real pi = acos(-1);
int N, M, L;
vector<P> stars[MAXN];

Real calc(int a, int b) {
	Real ans = 1e9;
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
		int ni = (i+2)%5, nj = (j+2)%5;
		ans = min(ans, distSeg(stars[a][i], stars[a][ni], stars[b][j], stars[b][nj]));
	}
	return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (cin >> N >> M >> L) {
    	if (N==0) break;
    	M--; L--;
    	for (int i = 0; i < N; i++) {
    		int x, y, a, r;
    		cin >> x >> y >> a >> r;
    		stars[i].resize(5);
    		for (int j = 0; j < 5; j++) {
    			Real angle = (90 + a + j*72) * pi / 180;
    			stars[i][j] = P(x, y) + P(cos(angle), sin(angle)) * r;
    		}
    	}
    	vector<vector<edge> > G(N);
    	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
    		Real dist = calc(i, j);
    		G[i].emplace_back(j, dist);
    		G[j].emplace_back(i, dist);
    	}
    	auto d = dijkstra(N, G, M);
    	cout << setprecision(12) << d[L] << endl;
    }
    return 0;
}