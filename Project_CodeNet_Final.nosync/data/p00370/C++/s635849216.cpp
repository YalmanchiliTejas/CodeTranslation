#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;
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
	if(cross(b, c) >  EPS)   return +1;      // counter clockwise
	if(cross(b, c) < -EPS)   return -1;      // clockwise
	if(dot(b, c)   < -EPS)   return +2;      // c--a--b on line
	if(norm(b)+EPS <norm(c)) return -2;      // a--b--c on line
	return 0;                                   // c is between a and b (inclusive)
}
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) < 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) < 0;
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	P s, t;
	G ps;
	int x, y, n;
	cin >> x >> y; s = P(x, y);
	cin >> x >> y; t = P(x, y);
	cin >> n;
	rep(i, n){
		cin >> x >> y;
		ps.emplace_back(x, y);
	}
	vector<vector<double>> d(n, vector<double>(n, INF));
	rep(i, n){
		d[i][i] = 0;
		d[(i + 1) % n][i] = d[i][(i + 1) % n] = abs(ps[i] - ps[(i + 1) % n]);
	}
	rep(k, n) rep(i, n) rep(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	auto ok = [&](const P &a, const P &b){
		const L l(a, b);
		rep(i, n){
			if(intersectSS(l, L(ps[i], ps[(i + 1) % n]))) return 0;
			if(ccw(ps[i], l[0], l[1]) == 2) return 0;
		}
		return 1;
	};
	
	double ans = INF;
	rep(i, n) rep(j, n){
		if(!ok(s, ps[i])) continue;
		if(!ok(t, ps[j])) continue;
		ans = min(ans, abs(s - ps[i]) + d[i][j] + abs(t - ps[j]));
	}
	#if 1
	int cnt = 0;
	rep(i, n){
		P a = ps[i], b = ps[(i + 1) % n];
		if(!(ok(s, a) && ok(s, b) && ok(t, a) && ok(t, b))) continue;
		double lo = 0, hi = 1, l, r;
		rep(it, 100){
			l = (2 * lo + hi) / 3;
			r = (lo + 2 * hi) / 3;
			P p1 = a * (1 - l) + b * l;
			P p2 = a * (1 - r) + b * r;
			if(abs(p1 - s) + abs(p1 - t) < abs(p2 - s) + abs(p2 - t)) hi = r;
			else lo = l;
		}
		P p = a * (1 - lo) + b * lo;
		ans = min(ans, abs(p - s) + abs(p - t));
		//assert(++cnt <= 2);
	}
	#endif
	printf("%.20f\n", ans);
	
	return 0;
}
