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
#define MAXN (200006)
ll n;
pi A[MAXN];
ll ans=LLINF;
void part1() {
	pi R=pi(LLINF, -LLINF);
	pi B=R;
	FOR(i,0,n-1) {
		R.f=min(A[i].f, R.f);
		R.s=max(A[i].f, R.s);
		B.f=min(A[i].s, B.f);
		B.s=max(A[i].s, B.s);
	}
	
	ans = min(ans, (R.s - R.f) * (B.s - B.f));
}
void part2() {
	ll maxi=-LLINF, mini=LLINF;
	FOR(i,0,n-1) maxi=max(maxi, A[i].s), mini=min(mini, A[i].f);
	vector<ll> o; 
	multiset<ll> ms;
	FOR(i,0,n-1) {
		ms.ins(A[i].f);
		o.pb(i);
	}
	sort(all(o), [&](ll x,ll y){return A[x].f<A[y].f;});
	ans = min(ans, (maxi - mini) * ((*--ms.end()) - *ms.begin()));
	FOR(i,0,n-1) {
		ms.erase(ms.find(A[o[i]].f)), ms.ins(A[o[i]].s);
		ans = min(ans, (maxi - mini) * ((*--ms.end()) - *ms.begin()));
	}
}
int main()
{
	FAST
	cin>>n;
	FOR(i,0,n-1) { cin>>A[i].f>>A[i].s; if(A[i].f > A[i].s) swap(A[i].f, A[i].s); }
	part1();
	part2();
	cout<<ans<<'\n';
}
