#include<bits/stdc++.h>
using namespace std;

using D = double;
struct Point {
  D x, y;
  Point(const D d = 0.0) : x(d), y(d) {}
  Point(const D x, const D y) : x(x), y(y) {}
};
struct Segment {
  Point ab, to;
  Segment(const Point& ab, const Point& to) : ab(ab), to(to) {}
  Segment(const D x1, const D y1, const D x2, const D y2) : ab(x1, y1), to(x2, y2) {}
};
using Polygon = vector<Point>;

const D EPS = 1e-9;
enum POSITION {ONLINE_FRONT = -2, CLOCKWISE, ON_SEGMENT, COUNTER_CLOCKWISE, ONLINE_BACK};

bool relative_equal(const D d1, const D d2) {return d1 == 0 ? std::abs(d2) < EPS : std::abs((d1 - d2) / d1) < EPS;}
bool operator==(const Point& lhs, const Point& rhs) {return relative_equal(lhs.x, rhs.x) && relative_equal(lhs.y, rhs.y);}
bool operator<(const Point& lhs, const Point& rhs) {return relative_equal(lhs.x, rhs.x) ? lhs.y < rhs.y : lhs.x < rhs.x;}
bool operator>(const Point& lhs, const Point& rhs) {return relative_equal(lhs.x, rhs.x) ? lhs.y > rhs.y : lhs.x > rhs.x;}
bool operator!=(const Point& lhs, const Point& rhs) {return !(lhs == rhs);}
bool operator<=(const Point& lhs, const Point& rhs) {return !(lhs > rhs);}
bool operator>=(const Point& lhs, const Point& rhs) {return !(lhs < rhs);}
const Point operator+(const Point& lhs, const Point& rhs) {return Point(lhs.x + rhs.x, lhs.y + rhs.y);}
const Point operator-(const Point& lhs, const Point& rhs) {return Point(lhs.x - rhs.x, lhs.y - rhs.y);}
const Point operator*(const Point& lhs, const Point& rhs) {return Point(lhs.x * rhs.x, lhs.y * rhs.y);}
const Point operator/(const Point& lhs, const Point& rhs) {return Point(lhs.x / rhs.x, lhs.y / rhs.y);}
D abs(const Point& p) {return hypot(p.x, p.y);}
D norm(const Point& p) {return p.x * p.x + p.y * p.y;}
D dot(const Point& a, const Point& b) {return a.x * b.x + a.y * b.y;}
D cross(const Point& a, const Point& b) {return a.x * b.y - a.y * b.x;}
POSITION ccw(const Point& a, const Point& b, const Point& p) {
  Point v1 = b - a;
  Point v2 = p - a;
  if(cross(v1, v2) >= EPS) return COUNTER_CLOCKWISE;
  if(cross(v1, v2) <= -EPS) return CLOCKWISE;
  if(dot(v1, v2) <= -EPS) return ONLINE_BACK;
  if(norm(v1) < norm(v2)) return ONLINE_FRONT;
  return ON_SEGMENT;
}
ostream& operator<<(ostream& os, const Point& p) {os<<"point: "; os<<"("<<p.x<<","<<p.y<<")"; return os;}

bool intersect(Segment s, Segment t) {return ccw(s.ab, s.to, t.ab)*ccw(s.ab, s.to, t.to) <= 0 && ccw(t.ab, t.to, s.ab)*ccw(t.ab, t.to, s.to) <= 0;}

bool intersect(Polygon P, Segment S) {
  for(auto i = 0; i < P.size(); ++i) {
    Segment T(P[i], P[(i+1) % P.size()]);
    if(intersect(S, T)) return true;
  }
  return false;
}

D tsearch(auto S, auto G, auto P) {
  auto d = [&](auto p) {return abs(p - S) + abs(G - p);};
  auto point = [&](auto p, auto q, auto x) {return p + (q - p) * x;};
  D r = 1e9;
  for(auto i = 0; i < P.size(); ++i) {
    auto s = P[i], g = P[(i+1) % P.size()];
    D l = 0, h = 1;
    for(auto j = 0; j < 1000; ++j) {
      auto m1 = (h + 2 * l) / 3;
      auto m2 = (2 * h + l) / 3;
      auto d1 = d(point(s, g, m1));
      auto d2 = d(point(s, g, m2));
      if(d1 < d2) h = m2;
      else        l = m1;
    }
    r = min(r, d(point(s, g, h)));
  }
  return r;
}

D chull(auto S, auto G, auto P) {
  if(S > G) swap(S, G);
  P.emplace_back(S);
  P.emplace_back(G);
  sort(begin(P), end(P));
  P.insert(end(P), P.rbegin() + 1, P.rend());
  Polygon ch;
  for(const auto& p: P) {
    while(ch.size() >= 2 && ccw(ch[ch.size() - 2], ch.back(), p) == CLOCKWISE) ch.pop_back();
    ch.emplace_back(p);
  }
  ch.pop_back();

  auto solve = [&](auto b, auto e) {
    D res = 0;
    auto pass = false;
    for(auto i = 0; i < 2 * ch.size(); ++i) {
      auto p = ch[i % ch.size()], q = ch[(i + 1) % ch.size()];
      if(p == b) pass = true;
      if(!pass) continue;
      res += abs(p - q);
      if(q == e) return res;
    }
    return 1e9;
  };
  return min(solve(S, G), solve(G, S));
}

int main() {
  Point S, G;
  int N;
  cin >> S.x >> S.y >> G.x >> G.y >> N;

  Polygon P(N);
  for(auto& i: P) cin >> i.x >> i.y;

  if(intersect(P, Segment{S, G})) cout << setprecision(8) << fixed << chull(S, G, P) << endl;
  else                            cout << setprecision(8) << fixed << tsearch(S, G, P) << endl;
}