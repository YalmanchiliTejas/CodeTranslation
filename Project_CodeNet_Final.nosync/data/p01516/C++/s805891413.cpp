#include <bits/stdc++.h>
#define inf (long double)1e18
using namespace std;

using CP = complex<long double>;
#define X real()
#define Y imag()
const long double PI = acos(-1);
const long double EPS = 1e-10;
// conj(x) : complex conjugate,(0,1)->(0,-1)
// abs(x) : dist between(0,0) and x
// norm(x) : abs(x) * abs(x)
// arg(x) : argment
long double dot(CP a, CP b) { return (a * conj(b)).X; }
long double cross(CP a, CP b) { return (a * conj(b)).Y; }
long double corner(CP a, CP b) {
  //[0,pi]
  return acos(dot(a, b) / (abs(a) * abs(b)));
}

CP intersection(CP a, CP b, CP c, CP d) {
  return a + (b - a) * (cross(d - c, c - a) /
                        cross(d - c, b - a));
}

// p on (a,b)?
bool on_seg(CP a, CP b, CP p) {
  // if not use end point, dot(a - p, b - p) < 0
  return abs(cross(a - p, b - p)) <= 1e-10 &&
         dot(a - p, b - p) <= 0;
}

// crossing lines? (a,b) and (c,d)
bool iscross(CP a, CP b, CP c, CP d) {
  // parallel
  if(abs(cross(a - b, c - d)) <= 1e-10) {
    return on_seg(a, b, c) || on_seg(a, b, d) ||
           on_seg(c, d, a) || on_seg(c, d, b);
  }
  CP isp = intersection(a, b, c, d);
  return on_seg(a, b, isp) && on_seg(c, d, isp);
}

long double distLP(CP a, CP b, CP p) {
  return abs(cross(b - a, p - a) / abs(b - a));
}

// segmentver.
long double distSP(CP a, CP b, CP p) {
  if(dot(b - a, p - a) < 0) return abs(p - a);
  if(dot(a - b, p - b) < 0) return abs(p - b);
  return distLP(a, b, p);
}

struct line {
  CP s, t;
};

struct data {
  long double x, y, a, r;
  line l[5];
};

struct dijk {
  long long p;
  long double dis;
};
bool operator<(const dijk &l, const dijk &r) {
  return l.dis > r.dis;
}

CP memo[5];
long long n, st, go;
vector<vector<long double>> dis;
vector<long double> dp;
vector<data> v;
priority_queue<dijk> pq;

long double solve();
long double calc(line &x, line &y);
long double linedis(line &now, CP &p);

int main() {
  cout << fixed << setprecision(10);
  for(int i = 1; i <= 5; ++i) {
    long double nowrad = PI / 2 + 2 * i * PI / 5;
    memo[i - 1] = CP(cos(nowrad), sin(nowrad));
    memo[i - 1] /= abs(memo[i - 1]);
  }
  while(1) {
    cin >> n >> st >> go;
    if(n + st + go == 0) break;
    --st, --go;
    v.resize(n);
    for(int i = 0; i < n; ++i) {
      cin >> v[i].x >> v[i].y >> v[i].a >> v[i].r;
      v[i].a *= PI / 180;
      CP rot(cos(v[i].a), sin(v[i].a));
      rot /= abs(rot);
      for(int j = 0; j < 5; ++j) {
        v[i].l[j].s = memo[j] * rot;
        v[i].l[j].s *= v[i].r;
        v[i].l[j].s += CP(v[i].x, v[i].y);

        v[i].l[j].t = memo[(j + 2) % 5] * rot;
        v[i].l[j].t *= v[i].r;
        v[i].l[j].t += CP(v[i].x, v[i].y);
      }
    }
    cout << solve() << endl;
  }
  return 0;
}

long double solve() {
  dis.assign(n, vector<long double>(n, 0));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if(i != j) {
        dis[i][j] = inf;
        for(int k = 0; k < 5; ++k)
          for(int l = 0; l < 5; ++l)
            dis[i][j] =
                min(dis[i][j], calc(v[i].l[k], v[j].l[l]));
      }
  dp.assign(n, inf);
  dp[st] = 0;
  pq.push({st, 0});
  while(!pq.empty()) {
    dijk now = pq.top();
    pq.pop();
    if(dp[now.p] != now.dis) continue;
    for(int i = 0; i < n; ++i)
      if(now.p != i) {
        dijk nextp = now;
        nextp.p = i;
        nextp.dis += dis[now.p][nextp.p];
        if(dp[nextp.p] > nextp.dis) {
          dp[nextp.p] = nextp.dis;
          pq.push(nextp);
        }
      }
  }
  return dp[go];
}

long double calc(line &x, line &y) {
  if(iscross(x.s, x.t, y.s, y.t)) return 0;
  long double res = inf;
  res = min(res, distSP(x.s, x.t, y.s));
  res = min(res, distSP(x.s, x.t, y.t));
  res = min(res, distSP(y.s, y.t, x.s));
  res = min(res, distSP(y.s, y.t, x.t));
  return res;
}
