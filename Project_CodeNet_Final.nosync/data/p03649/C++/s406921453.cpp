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
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (56)
ll n, sum, ans;
ll A[MAXN];
void reduce(ll x) { if(x<=0) return;
	ans += x;
	FOR(i,1,n) A[i] += x;
	ll st=-1, en=*max_element(A+1,A+n+1), mid=0;
	while(en-st>1) {
		mid=(st+en)>>1;
		ll T = 0;
		FOR(i,1,n) T += max((A[i]-mid)/(n+1), 0ll);
		if(T <= x) en=mid;
		else st=mid;
	}
	ll T=0; FOR(i,1,n) T += max((A[i]-en)/(n+1), 0ll);
	FOR(i,1,n) A[i] -= max((A[i]-en)/(n+1), 0ll) * (n+1);
	x -= T; assert(x>=0);
	while(x) {
		A[max_element(A+1,A+n+1)-A] -= (n+1);
		-- x;
	}
	return;
}
int main()
{
	FAST
	cin>>n;
	FOR(i,1,n)cin>>A[i];
	sum = accumulate(A+1, A+n+1, 0ll);
	reduce(sum-n*(n-1));
	ll ofs=0;
	while(*max_element(A+1,A+n+1) + ofs >= n) {
		A[max_element(A+1,A+n+1)-A] -= (n+1);
		++ ofs;
		++ ans;
	}
	cout<<ans<<'\n';
}
