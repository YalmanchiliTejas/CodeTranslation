#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<double, int> PD;
typedef pair<double, double> PDD;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001
#define pi acos(-1)

P vv[] = {P(0, 2), P(2, 4), P(4, 1), P(1, 3), P(3, 0)};

struct Star {
  PDD v[5];
};

PDD operator-(const PDD &a, const PDD &b) {
  return PDD(a.fi - b.fi, a.se - b.se);
}

double len(PDD p) {
  return sqrt(p.fi * p.fi + p.se * p.se);
}

double dot(PDD a, PDD b) {
  return a.fi * b.fi + a.se * b.se;
}

double cross(PDD a, PDD b) {
  return a.fi * b.se - a.se * b.fi;
}

double distance(PDD p1, PDD p2, PDD q1, PDD q2) {
  if (cross(p2 - p1, q1 - p1) * cross(p2 - p1, q2 - p1) < 0 && cross(q2 - q1, p1 - q1) * cross(q2 - q1, p2 - q1) < 0) {
    return 0;
  } else {
    double mini = INF;
    if (dot(p2 - p1, q1 - p1) < 1e-7) minch(mini, len(q1 - p1));
    else if (dot(p1 - p2, q1 - p2) < 1e-7) minch(mini, len(q1 - p2));
    else minch(mini, abs(cross(p2 - p1, q1 - p1)) / len(p2 - p1));

    if (dot(p2 - p1, q2 - p1) < 1e-7) minch(mini, len(q2 - p1));
    else if (dot(p1 - p2, q2 - p2) < 1e-7) minch(mini, len(q2 - p2));
    else minch(mini, abs(cross(p2 - p1, q2 - p1)) / len(p2 - p1));

    if (dot(q2 - q1, p1 - q1) < 1e-7) minch(mini, len(p1 - q1));
    else if (dot(q1 - q2, p1 - q2) < 1e-7) minch(mini, len(p1 - q2));
    else minch(mini, abs(cross(q2 - q1, p1 - q1)) / len(q2 - q1));

    if (dot(q2 - q1, p2 - q1) < 1e-7) minch(mini, len(p2 - q1));
    else if (dot(q1 - q2, p2 - q2) < 1e-7) minch(mini, len(p2 - q2));
    else minch(mini, abs(cross(q2 - q1, p2 - q1)) / len(q2 - q1));

    return mini;
  }
}

int main(){
  // cin.sync_with_stdio(false);
  int n, m, l;
  while(cin >> n >> m >> l, n) {
    m--, l--;
    Star s[n];
    rep(i, n) {
      double x, y, a, r;
      cin >> x >> y >> a >> r;
      a = a / 180.0 * pi;
      rep(j, 5) s[i].v[j] = PDD(x + (-1) * r * sin(a + 2 * j * pi / 5.0), y + r * cos(a + 2 * j * pi / 5.0));
    }

    priority_queue<PD, vector<PD>, greater<PD>> q;
    q.push(PD(0, m));
    bool visited[n] = {};
    double ans = -1;
    while(!q.empty()) {
      PD p = q.top(); q.pop();

      if (p.se == l) {
        ans = p.fi;
        break;
      }

      if (visited[p.se]) continue;
      else visited[p.se] = true;

      rep(i, n) {
        if (i == p.se) continue;
        if (!visited[i]) {
          double mini = INF;
          rep(j, 5)rep(k, 5) {
            minch(mini, distance(s[p.se].v[vv[j].fi], s[p.se].v[vv[j].se], s[i].v[vv[k].fi], s[i].v[vv[k].se]));
          }
          q.push(PD(p.fi + mini, i));
        }
      }
    }

    printf("%.10f\n", ans);
  }

  return 0;
}