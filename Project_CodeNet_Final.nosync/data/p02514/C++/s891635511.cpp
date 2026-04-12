#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define DEC(i, s) for (int i = (s); i >= 0; i--)

#define SIZE(v) (int)((v).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define FIND(m, w) ((m).find(w) != (m).end())

#include <complex>
#include <vector>

typedef complex<double> Point;
typedef vector<Point> Polygon;

static const double INF = 1e+10;

#define CURR(P, i) (P[i])
#define NEXT(P, i) (P[(i + 1) % P.size()])

struct Line : public vector<Point> {
  Line() {;}
  Line(Point a, Point b) { push_back(a); push_back(b); }
};

struct Circle {
  Point p;
  double r;
  Circle() {;}
  Circle(Point p, double r) : p(p), r(r) {;}
};

namespace std {
  bool operator<(const Point &lhs, const Point &rhs) {
    return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
  }
}

inline double cross(const Point &a, const Point &b) {
  return imag(conj(a) * b);
}

inline double dot(const Point &a, const Point &b) {
  return real(conj(a) * b);
}

inline int ccw(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) { return 1; }
  if (cross(b, c) < 0) { return -1; }
  if (dot(b, c) < 0) { return 2; }
  if (norm(b) < norm(c)) { return -2; }
  return 0;
}


struct Rectangle {
  Point a, b;
  string next;
  Rectangle() {;}
  Rectangle(Point a, Point b, string next) : a(a), b(b), next(next) {
  }
  bool in(Point p) {
    return a.real() <= p.real() && p.real() <= b.real() &&
           a.imag() <= p.imag() && p.imag() <= b.imag();
  }
};

struct Page {
  string name;
  vector<Rectangle> button;
};

int n;
int w, h;
Page page[1000];
map<string, int> mapfrom;

int main() {
  while (cin >> n, n) {
    mapfrom.clear();
    cin >> w >> h;
    REP(i, n) {
      int size;
      cin >> page[i].name >> size;
      mapfrom.insert(make_pair(page[i].name, i));
      page[i].button.resize(size);
      REP(j, size) {
        int l, t, r, b;
        string str;
        cin >> l >> t >> r >> b >> str;
        page[i].button[j] = Rectangle(Point(l, t), Point(r, b), str);
      }
    }
    int m;
    cin >> m;
    vector<int> st;
    st.push_back(0);
    int head = 0;
    REP(iter, m) {
      int p = st[head];
      string command;
      cin >> command;
      if (command == "click") {
        int x, y;
        cin >> x >> y;
        REP(i, page[p].button.size()) {
          if (page[p].button[i].in(Point(x, y))) {
            head++;
            st.resize(head);
            st.push_back(mapfrom[page[p].button[i].next]);
            break;
          }
        }
      } else if (command == "back") {
        head = max(0, head - 1);
      } else if (command == "forward") {
        head = min((int)st.size() - 1, head + 1);
      } else {
        cout << page[st[head]].name << endl;
      }
    }
  }
}