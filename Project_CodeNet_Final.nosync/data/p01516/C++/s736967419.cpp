
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define each(i, c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

typedef pair<int, int> pi;
typedef complex<double> P;

const double EPS = 1e-8, INF = 1e12;
double cross(const P &a, const P &b){
	return imag(conj(a) * b);
}
double dot(const P &a, const P &b){
	return real(conj(a) * b);
}
struct L : public vector<P> {
	L(const P &a, const P &b){
		pb(a); pb(b);
	}
};
typedef vector<P> G;
int ccw(P a, P b, P c){
	b -= a; c -= a;
	if(cross(b, c) > EPS) return 1;
	if(cross(b, c) < -EPS) return -1;
	if(dot(b, c) < -EPS) return 2;
	if(norm(b) < norm(c)) return -2;
	return 0;
}

bool intersectSP(const L &s, const P &p){
	return ccw(p, s[0], s[1]) == 2;
}
bool intersectSS(const L &s, const L &t){
	return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
	ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
P projection(const L &l, const P &p){
	double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
	return l[0] + t * (l[0] - l[1]);
}
double distanceSP(const L &s, const P &p){
	const P r = projection(s, p);
	if(intersectSP(s, r)) return abs(r - p);
	return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const L &s, const L &t){
	if(intersectSS(s, t)) return 0;
	return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
		min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
const double PI = acos(-1);
int n, m, l;
int x[100], y[100], a[100], r[100];
double dist[100][100];

int main(){
	while(cin >> n >> m >> l, n){
		rep(i, n) cin >> x[i] >> y[i] >> a[i] >> r[i];
		vector<G> stars;
		rep(i, n){
			double t = a[i] * PI / 180;
			G star;
			rep(j, 5){
				double tt = PI / 2 + t + PI * 0.4 * j;
				star.pb(P(cos(tt), sin(tt)) * (double)r[i] + P(x[i], y[i]));
			}
			stars.pb(star);
		}
		rep(i, n) rep(j, i){
			double mn = INF;
			rep(l, 5) rep(k, 5){
				L la(stars[i][l], stars[i][(l + 2) % 5]);
				L lb(stars[j][k], stars[j][(k + 2) % 5]);
				mn = min(mn, distanceSS(la, lb));
			}
			dist[i][j] = dist[j][i] = mn;
		}
		priority_queue<pair<double, int> > q;
		q.push(mp(0, m - 1));
		set<int> s;
		while(!q.empty()){
			int c = q.top().second;
			double cc = q.top().first;
			q.pop();
			
			if(s.count(c)) continue;
			s.insert(c);
			
			if(c == l - 1){
				printf("%.9f\n", abs(cc));
				break;
			}
			
			rep(i, n) q.push(mp(cc - dist[c][i], i));
		}
	}
	return 0;
}