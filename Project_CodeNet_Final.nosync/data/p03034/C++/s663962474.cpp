#define LOCAL
#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos((ld)-1.0))
#define MAXN (100006)
#define ll long long int 
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < (ll)ee; ++ii)
#define space " "
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define ph push
#define btinpct(x) __builtin_popcountll((x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss
string to_string(char c) {string s(1,c);return s;}string to_string(bool b){return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void degug_out() { cerr << endl; }template <typename Head, typename... Tail>void degug_out(Head H, Tail... T) {cerr << " " << to_string(H);degug_out(T...);}
#ifdef LOCAL
#define degug(...) cerr << "[" << #__VA_ARGS__ << "]:", degug_out(__VA_ARGS__)
#else
#define degug(...) 42
#define cerr if(0)cout
#endif
ll n,A[MAXN],ans;
vector<ll>sumf[MAXN],sumb[MAXN];
void addf(ll c) {
	if(sumf[c].size())return;
	ll sum=0;
	for(ll i=0;i<n;i+=c){
		sum+=A[i];sumf[c].pb(sum);
	}
	return;
}
void addb(ll c) {
	if(sumb[c].size())return;
	ll sum=0;
	for(ll i=n-1;i>=0;i-=c){
		sum+=A[i];sumb[c].pb(sum);
	}
	return;
}
void solve(ll a, ll b, ll k) {
	if(b>=a||b<=0)return; 
	ll C=a-b; if((a%C==0&&a/C<=k))return;
	addf(C); // k
	addb(C); // k
	// cerr<<k<<'\n';// cerr<<sumf[C][k-1]<<' '<<sumb[C][k]<<'\n';
	ans=max(ans,sumf[C][k]+sumb[C][k]);
	return;
}
int main()
{	
	FAST
	cin>>n;
	FOR(i,0,n)cin>>A[i];assert(A[0]==0&&A[n-1]==0);
	FOR(a,1,n+1){
		for(ll k=1;k*k<=(n-1-a);++k){
			if((n-1-a)%k)continue;
			solve(a,a-(n-1-a)/k,k);
			solve(a,a-(n-1-a)/((n-1-a)/k),((n-1-a)/k));
		}
	}
	cout<<ans;
}
