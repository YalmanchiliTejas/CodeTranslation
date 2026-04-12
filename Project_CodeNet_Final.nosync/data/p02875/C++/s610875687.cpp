#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#include <bitset>
#include <stack>
using namespace std;
 
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define ktya(x) sort(all(x))
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 1e18
#define INFLL 1000000000000000007LL
#define SIZE 200105
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define PI (acos(-1))
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
// ll MOD = 1000000007;
ll MOD=998244353;
typedef ll Weight;
struct Edge {
	int src, dst;
	Weight weight;
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
int N,K;
ll gcd(ll a, ll b) {
	return b != 0 ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
	ll g = a; x = 1; y = 0;
	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
	return g;
}
ll invMod(ll a, ll m) {
	ll x, y;
	if (extgcd(a, m, x, y) == 1) return (x + m) % m;
	else                         return 0; // unsolvable
}



ll powMod(ll x, ll k, ll m) {//x^k (mod n)
	if (k == 0)     return 1;
	if (k % 2 == 0) return powMod(x*x % m, k/2, m);
	else            return x*powMod(x, k-1, m) % m;
}
int main(){
	ll N;
	cin>>N;
	N/=2;
	ll ans=powMod(3,2*N,MOD);
	ll fu=0;
	ll kumi=1;
	ll po2=1;
	for(int i=0;i<=N-1;i++){
		ll hoge=(kumi*po2)%MOD;
		hoge*=2;
		hoge%=MOD;
		ans-=hoge;
		ans+=MOD;
		ans%=MOD;
		kumi*=(2*N-i);
		kumi%=MOD;
		kumi*=invMod(i+1,MOD);
		kumi%=MOD;
		po2*=2;
		po2%=MOD;
	}
	cout<<ans<<endl;


}