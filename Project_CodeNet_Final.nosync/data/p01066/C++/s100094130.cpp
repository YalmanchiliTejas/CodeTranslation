#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double EPS = 1e-8, INF = 1e12, PI = acos(-1.0);
typedef complex<double> P;
namespace std{
	bool operator<(const P& a, const P& b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
inline double cross(const P& a, const P& b){ return imag(conj(a)*b); }
inline double dot(const P& a, const P& b){ return real(conj(a)*b); }
struct L : public vector<P>{
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};
typedef vector<P> G;

inline int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if(cross(b, c) > 0)   return +1;		// counter clockwise
	if(cross(b, c) < 0)   return -1;		// clockwise
	if(dot(b, c) < 0)     return +2;		// c--a--b on line
	if(norm(b) < norm(c)) return -2;		// a--b--c on line
	return 0;
}

int n, x[8], y[8];
vector<pi> t[8][8];
map<vi, int> dp;

int root(vi &p, int x){
	return x == p[x] ? x : p[x] = root(p, p[x]);
}

int rec(vi v){
	if(dp.count(v)) return dp[v];
	
	int &res = dp[v];
	int fin = 0;
	rep(i, n) fin = max(fin, v[i]);
	if(fin == 0) return 0;
	
	res = inf;
	rep(i, n) rep(j, i){
		vi uf, to(n, -1);
		rep(k, fin + 1) uf.pb(k);
		
		for(pi p : t[i][j]){
			int a = root(uf, v[p.first]), b = root(uf, v[p.second]);
			if(a != b) uf[b] = a;
		}
		int sz = 0;
		rep(k, n) if(to[root(uf, v[k])] < 0) to[root(uf, v[k])] = sz++;
		
		vi nxt;
		rep(k, n) nxt.pb(to[root(uf, v[k])]);
		
		if(v != nxt) res = min(res, rec(nxt) + 1);
	}
	return res;
}
int main(){
	cin >> n;
	rep(i, n) cin >> x[i] >> y[i];
	rep(i, n) rep(j, i){
		P p((x[i] + x[j]) / 2.0, (y[i] + y[j]) / 2.0), q(x[j] - x[i], y[j] - y[i]);
		q *= P(0, 1);
		t[i][j].pb(mp(i, j));
		rep(k, n) rep(l, k) if(k != i || l != j){
			P r((x[k] + x[l]) / 2.0, (y[k] + y[l]) / 2.0), s(x[l] - x[k], y[l] - y[k]);
			s *= P(0, 1);
			if(abs(cross(q, s)) < EPS && abs(cross(p - r, q)) < EPS){
				
				t[i][j].pb(mp(k, l));
			}
		}
	}
	vi init;
	rep(i, n) init.pb(i);
	cout << rec(init) << endl;
	return 0;
}