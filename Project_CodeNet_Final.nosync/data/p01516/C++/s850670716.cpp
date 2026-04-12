/*
x' = xcos - ysin
y' = xsin + ycos
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const double EPS = 1e-8;
const double INF = 1e12;
const double PI = atan2(0, -1);

//point
typedef complex<double> P;
namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
}
// line
struct L : public vector<P> {
	L(const P& a, const P& b) {
		push_back(a); push_back(b);
	}
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;								  // a--c--b on line
}

//S?????????????????AL??????????????
bool intersectLL(const L &l, const L &m) {
  return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || // non-parallel
         abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;   // same line
}
bool intersectLS(const L &l, const L &s) {
  return cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l
         cross(l[1]-l[0], s[1]-l[0]) < EPS; // s[1] is right of l
}
bool intersectLP(const L &l, const P &p) {
  return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

P projection(const L &l, const P &p) {
	double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
	return l[0] + t*(l[0]-l[1]);
}
P reflection(const L &l, const P &p) {
	return p + (double)2 * (projection(l, p) - p);
}
double distanceLP(const L &l, const P &p) {
	return abs(p - projection(l, p));
}
double distanceLL(const L &l, const L &m) {
	return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double distanceLS(const L &l, const L &s) {
	if (intersectLS(l, s)) return 0;
	return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP(const L &s, const P &p) {
	const P r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const L &s, const L &t) {
	if (intersectSS(s, t)) return 0;
		return min({distanceSP(s, t[0]), distanceSP(s, t[1]), distanceSP(t, s[0]), distanceSP(t, s[1])});
}
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0]; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

struct edge{
  int to;
  double cost;
};

vector<L> l[105];
vector<edge> G[105];
double d[105];
int main() {
  //cout << PI << endl;
  while(true) {
  int n, s, g;
  cin >> n >> s >> g;
  if(!n && !s && !g) break;
  for(int i=0; i<n; ++i) {
    int x, y, a, r;
    cin >> x >> y >> a >> r;
    P p[5];
    for(int j=0; j<5; ++j) {
      p[j] = {x + r*cos(j*2*PI/5+a*2*PI/360+PI/2), y + r*(sin(j*2*PI/5+a*2*PI/360+PI/2))};
      //cout << j*2*PI/5+a*2*PI/360+PI/2 << " " << p[j].real() << " " << p[j].imag() << endl;
    }
    l[i].clear();
    l[i].push_back(L{p[0], p[2]});
    l[i].push_back(L{p[0], p[3]});
    l[i].push_back(L{p[1], p[3]});
    l[i].push_back(L{p[1], p[4]});
    l[i].push_back(L{p[2], p[4]});
  }

  //cout << "in" << endl;
  for(int i=0; i<n; ++i) G[i].clear();
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      //l[i]??¨l[j]????????¢????±???????????????????
      if(i == j) continue;
      double mi = INF;
      for(int k=0; k<5; ++k) {
        for(int k2=0; k2<5; ++k2) {
          mi = min(mi, distanceSS(l[i][k], l[j][k2]));
        }
      }
      G[i].push_back({j, mi});
      G[j].push_back({i, mi});
    }
  }
  /*for(int i=0; i<n; ++i) {
    cout << i << ":";
    for(edge e: G[i]) {
      cout << "(" << e.to << " " << e.cost << ")";
    }
    cout << endl;
  }
  cout << "edge" << endl;*/

  s--; g--;
  priority_queue<PII, vector<PII>, greater<PII>> que;
  fill(d, d+n, INF);
  d[s] = 0;
  que.push(PII(0, s));

  while(que.size()) {
    PII p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i=0; i<G[v].size(); ++i) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(PII(d[e.to], e.to));
      }
    }
  }
  cout << fixed << setprecision(15) << d[g] << endl;
}
}