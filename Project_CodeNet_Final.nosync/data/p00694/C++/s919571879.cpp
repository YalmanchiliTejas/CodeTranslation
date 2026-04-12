#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define dump(a) (cerr << #a << " = " << (a) << endl)
#define REP(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) REP(i, 0, n)
#define ALL(x) begin(x), end(x)

struct point {
  int x, y, z;
  explicit point(int x_ = 0, int y_ = 0, int z_ = 0):x(x_), y(y_), z(z_) {}

  point operator+(const point &p) const {
	return point(x + p.x, y + p.y, z + p.z);
  }

  point operator-(const point &p) const {
	return point(x - p.x, y - p.y, z - p.z);
  }

  point operator-() const {
	return point(-x, -y, -z);
  }

  bool operator<(const point &p) const {
	if(x != p.x) return x < p.x;
	if(y != p.y) return y < p.y;
	return z < p.z;
  }

  bool operator==(const point &p) const {
	return x == p.x && y == p.y && z == p.z;
  }
};

ostream &operator<<(ostream &os, const point &p) {
  return os << '(' << p.x << ", " << p.y << ", " << p.z << ')';
}

struct segment {
  point a, b;
  segment(const point &a_, const point &b_):a(a_), b(b_) {
	if(b < a) swap(a, b);
  }

  bool operator<(const segment &s) const {
	if(a < s.a || s.a < a) return a < s.a;
	return b < s.b;
  }

  bool operator==(const segment&s) const {
	return a == s.a && b == s.b;
  }
};

point rotate_x(const point &p) {
  return point(p.x, p.z, -p.y);
}

point rotate_y(const point &p) {
  return point(p.z, p.y, -p.x);
}

point rotate_z(const point &p) {
  return point(p.y, -p.x, p.z);
}

bool input(set<segment> &segs) {
  int n;
  cin >> n;

  if(n == 0) return false;

  point move_d[128];
  move_d['x'] = point(1, 0, 0);
  move_d['y'] = point(0, 1, 0);
  move_d['z'] = point(0, 0, 1);
  
  const point move_x(1, 0, 0), move_y(0, 1, 0), move_z(0, 0, 1);

  point current(0, 0, 0);
  map<int, point> label;

  rep(i, n) {
	string s;
	cin >> s;

	if(isdigit(s[0])) { // label
	  const int idx = stoi(s);
	  if(!label.count(idx)) {
		label[idx] = current;
	  }
	  else {
		current = label[idx];
	  }
	}
	else { // move
	  point d = move_d[s[1]];
	  if(s[0] == '-') d = -d;
	  const point next = current + d;
	  segs.insert(segment(current, next));
	  current = move(next);
	}
  }

   return true;
}

bool match(const set<segment> &a, const set<segment> &b) {
  if(a.size() != b.size()) return false;
  auto it_a = a.cbegin();
  auto it_b = b.cbegin();

  const point offset = a.cbegin()->a - b.cbegin()->a;

  while(it_a != a.end()) {
	const segment &s_a = *it_a;
	const segment s_b(it_b->a + offset, it_b->b + offset);
	if(!(s_a == s_b)) return false;

	++it_a;
	++it_b;
  }

  return true;

}

set<segment> rotate_points(const set<segment> &segs, const function<point(const point&)> &convert) {
  set<segment> res;
  for(const auto &seg : segs) {
	res.insert(segment(convert(seg.a), convert(seg.b)));
  }
  return res;
}

bool valid(const set<segment> &a, set<segment> b) {
  rep(loop_x, 4) {
	b = rotate_points(b, rotate_x);
	rep(loop_y, 4) {
	  b = rotate_points(b, rotate_y);
	  rep(loop_z, 4) {
		b = rotate_points(b, rotate_z);
		if(match(a, b)) return true;
	  }
	}
  }

  return false;
}

int main() {
  set<segment> a, b;
  while(input(a)) {
	assert(input(b));
	cout << (valid(a, b) ? "SAME" : "DIFFERENT") << endl;
	a.clear();
	b.clear();
  }

  return 0;
}