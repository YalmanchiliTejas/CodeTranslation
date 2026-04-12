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

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f3f3f3f3fLL
#define SIZE 8080
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
ll MOD=1e9+7;
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
typedef vector<Edges> Graph;
ll bik[114514];
ll bikinv[114514];
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
void bikcal(int NN){
	ll hoge=(ll)1;
	bik[0]=(ll)1;
	bikinv[0]=(ll)1;
	for(int i=1;i<=NN;i++){
		hoge=(hoge*i)%MOD;
		bik[i]=hoge;
		bikinv[i]=invMod(bik[i],MOD);
	}
}


ll Comb(int a,int b){
	ll ret;
	ret=(((bik[a]*bikinv[b])%MOD)*bikinv[a-b])%MOD;
	return ret;
}


ll powMod(ll x, ll k, ll m) {//x^k (mod n)
if (k == 0)     return 1;
if (k % 2 == 0) return powMod(x*x % m, k/2, m);
else            return x*powMod(x, k-1, m) % m;
}
ll dp[1111][1111]={0};
int main(){
	int N,A,B,C,D;
	cin>>N>>A>>B>>C>>D;
	dp[A-1][0]=1;
	dp[0][0]=1;
	bikcal(1111);
	for(int i=A;i<=B;i++){
		for(int j=0;j<=N;j++){
			dp[i][j] = dp[i-1][j];
			for(int k=C;k<=D&&k*i<=j;k++){
				dp[i][j]=dp[i][j]+dp[i-1][j-k*i]*bik[N-j+i*k]%MOD *bikinv[N-j]%MOD *bikinv[k]%MOD*powMod(bikinv[i],k,MOD)%MOD;
				dp[i][j] %= MOD;
			}
		
		}
	}
	
	cout<<dp[B][N]<<endl;
}


















