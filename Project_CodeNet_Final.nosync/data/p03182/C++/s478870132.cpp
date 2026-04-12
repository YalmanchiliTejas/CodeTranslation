#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define ph push
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (300006)
ll n, m;
struct event {
	ll x, op, i;
	bool operator < (const event &e) const {
		return pi(x, op) < pi(e.x, e.op);
	}
};
struct node {
	int s,e,m;
	ll v,add;
	node *l,*r;
	node(ll _S,ll _E){
		s=_S,e=_E,m=(s+e)>>1;
		v=0, add=0;
		if(s^e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	void update(ll x,ll y,ll nval) {
		if(s==x&&e==y) { add += nval; return; }
		if(x>m) r->update(x,y,nval);
		else if(y<=m) l->update(x,y,nval);
		else l->update(x,m,nval), r->update(m+1,y,nval);
		v=max(l->value(),r->value());
	}
	ll value() {
		v+=add;
		if(s^e){
			l->add+=add;
			r->add+=add;
		}
		add=0;
		return v;
	}
}*seg;
int main()
{
	FAST
	cin>>n>>m;
	vector<spi> A(m);
	FOR(i,0,m-1) cin>>A[i].s.f>>A[i].s.s>>A[i].f;
	vector<event> v;
	FOR(i,0,m-1) v.pb({A[i].s.f, 0, i}), v.pb({A[i].s.s, 1, i});
	sort(all(v)); reverse(all(v));
	ll sum=0;
	vector<ll> dp(n+1, 0); seg=new node(1,n);
	FOR(i,1,n) {
		while(v.size() && v.back().x == i && v.back().op == 0) {
			sum += A[v.back().i].f;
			v.pop_back();
		}
		dp[i]=max(0ll, seg->value()) + sum;
		seg->update(i, i, dp[i] - sum);
		while(v.size() && v.back().x == i && v.back().op == 1) {
			seg->update(A[v.back().i].s.f,A[v.back().i].s.s,A[v.back().i].f);
			sum -= A[v.back().i].f;
			v.pop_back();
		}
	}
	cout<<*max_element(all(dp))<<'\n';
}
