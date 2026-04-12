#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<n;++i)

using namespace std;

typedef complex<double> P;
typedef pair<double,int>pdi;

const int MAX_N = 102;

struct edge{
    int to;
    double cost;
};

namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

double d[MAX_N];
vector<edge> G[MAX_N];
int n;

void dijkstra(int s)
{
	priority_queue<pdi,vector<pdi>,greater<pdi> > que;
	d[s] = 0;
	que.push(pdi(0.0,s));
	while(!que.empty()){
		pdi p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		vector<edge>::iterator it = G[v].begin();
		rep(i,G[v].size()){
			if(d[G[v][i].to] > d[v] + G[v][i].cost){
				d[G[v][i].to] = d[v] + G[v][i].cost;
				que.push(pdi(d[G[v][i].to],G[v][i].to));
			}
		}
	}
}

double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

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
  return p + (projection(l, p) - p)*2.0;
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
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

int main()
{
    while(1){
        int s,t;
    	scanf("%d%d%d",&n,&s,&t);
        if(n == 0 && s == 0 && t == 0){
            break;
        }
        vector<L> star[MAX_N];
        rep(i,n){
            G[i].clear();
        }
    	rep(i,n){
            vector<P> star_pos;
            int x,y,a,r;
            scanf("%d%d%d%d",&x,&y,&a,&r);
            rep(j,5){
                star_pos.push_back(P(-sin((a+72.0*j)*M_PI/180.0)*r + x,cos((a+72.0*j)*M_PI/180.0)*r + y));
            }
            rep(j,5){
                star[i].push_back(L(star_pos[j],star_pos[(j+2)%5]));
            }
    	}
        rep(i,n){
            rep(j,n){
                if(i != j){
                    double mn = INF;
                    rep(k,star[i].size()){
                        rep(l,star[j].size()){
                            mn = min(mn,distanceSS(star[i][k],star[j][l]));
                        }
                    }
                    G[i].push_back((edge){j,mn});
                }
            }
        }
        fill(d,d+n,INF);
        dijkstra(s-1);
        printf("%.12lf\n",d[t-1]);
    }
	return 0;
}