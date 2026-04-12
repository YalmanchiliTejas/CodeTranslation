#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a); i<int(b); ++i)
#define RFOR(i,a,b) for(int i=(b)-1; i>=int(a); --i)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,int(n)+1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
#define al(d) d.begin(),d.end()
#define fill(n) std::setfill('0')<<std::right<<std::setw(n)
#define intmax 2147483647
#define llmax 9223372036854775807
#define mod 1000000007
template <typename T>
using vec = std::vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using pii = std::pair<int, int>;
using ll = long long;
using vll = vec<ll>;
using ld = long double;
#define pair(a,b) "("<<a<<","<<b<<")"
#define pairr(a,b,c) "("<<a<<","<<b<<","<<c<<")"
#define lmin(a,b) (a<b)? a : b

template <typename T>
void putv(vector<T>& V){
	// cout << "The elements in the vector are: " << endl;
	for(auto x: V)
		cout << x << " ";
	cout << endl;
}
template <class T>
vector<T> getv(int n){
	vector<T> vec;
	rep(i,n){
		T input;
		cin >> input;
		vec.emplace_back(input);
	}
	return vec;
}

////Graph
using Weight = ll;
using Flow = int;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;
void add_edge(Graph &g, int a, int b, Weight w = 1){
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1){
	g[a].emplace_back(a, b, w);
}
void init_weighted_graph(Graph &g, int N, int M){
	vector<Edge> empty_Edges;
	g = Graph(N,empty_Edges);
	rep(i,M){
		int a,b,w;
		cin >> a >> b >> w;
		add_edge(g,a-1,b-1,w);
	}
// 例えば
//// 3 3
//// 1 2 1
//// 1 3 1
//// 2 3 3
// から
//// The Adjacency List of
//// G=(V,E) (n=3,m=6)
//// 0: (1,1)(2,1)
//// 1: (0,1)(2,3)
//// 2: (0,1)(1,3)
// を得る．
}
void init_weighted_directed_graph(Graph &g, int N, int M){
	vector<Edge> empty_Edges;
	g = Graph(N,empty_Edges);
	rep(i,M){
		int a,b,w;
		cin >> a >> b >> w;
		add_arc(g,a-1,b-1,w);
	}
}
void show_weighted_graph(const Graph &g){
	int N = g.size();
	int M = 0;
	rep(s,N)
		M += g[s].size();
	cout << "///////////////////////"<<endl;
	cout <<"The Adjacency List of" <<endl<< "G=(V,E) (n="<<N<<","<<"m="<<M<<")"<<endl;
	rep(s,N){
		cout << s << ": ";
		int size = g[s].size();
		rep(t,size)
			cout << pair(g[s][t].dst, g[s][t].weight);
		cout << endl;
	}
	cout << "////////////////////////"<<endl<<endl;
}
// a->bが存在するか
bool is_adj(Graph &g, int a, int b){
	for(auto e: g[a])
		if(b==e.dst)
			return true;
	return false;
}

// O(V^3)
Matrix warshallFloyd(const Graph &g) {
	auto const inf = numeric_limits<Weight>::max()/8;
	int n = g.size();
	Matrix d(n,Array(n,inf));
	rep(i,n) d[i][i]=0;
	rep(i, n) for(auto &e: g[i]) d[e.src][e.dst] = min(d[e.src][e.dst],e.weight);
	rep(k,n) rep(i,n) rep(j,n)
		if(d[i][k]!=inf && d[k][j]!=inf) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
	return d;
}

//////////

void out(bool ans){
	if(ans == true) cout << "yes" << endl;
	else cout << "no" << endl;
}
void Out(bool ans){
	if(ans == true) cout << "Yes" << endl;
	else cout << "No" << endl;
}
void OUT(bool ans){
	if(ans == true) cout << "YES" << endl;
	else cout << "NO" << endl;
}

//// Mathematical functions
ll gcd(const ll a, const ll b){
	return (b==0) ? a : gcd(b,a%b);
}
ll lcm(const ll a, const ll b){
	return a*(b/gcd(a,b));
}
ll Manhattan_dist(ll x1, ll y1, ll x2, ll y2){
	return abs(x1-x2) + abs(y1-y2);
}
// nをpで何回割れるか
ll hmt_p_divide_n(ll p, ll n){
	ll s = 0;
	while(n%p == 0){
		n /= p;
		s++;
	}
	return s;
}
int digit(ll n){
	int cntr = 0;
	while(n>0){
		n/=10;
		cntr++;
	}
	return cntr;
}
// generarized absolute value
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

// unsigned long long nCr(int n, int r){
// 	unsigned long long ans = 1;
// 	for(int i=n; i>n-r; --i) ans*=i;
// 	for(int i=1; i<r+1; ++i) ans/=i;
// 	return ans;
// }

unsigned long long memo[100][100] = {};
unsigned long long binom(const int n, const int r){
	if(n<r) return 0;
	if(r==0 || n==r) return 1;
	if(memo[n][r]>0) 
		return memo[n][r];
	else
		return memo[n][r] = binom(n-1,r) + binom(n-1,r-1);
}
ll pw(ll x, int y) {
	ll a = 1;
	while(y){
		if(y&1)
			a = (a*x)%mod; 
		x = (x*x)%mod;
		y >>= 1;
	}
	return a;
}
ll modinv(ll x){

	return pw(x, mod-2);
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
int main(){
	int n;
	cin >> n;
	vi H = getv<int>(n);

	int m = 0;
	int ret = 0;
	rep(i,n)
		if(m<=H[i]){
			m = max(m,H[i]);
			ret++;
			// cout << i << "から見える" << endl;
		}

	cout << ret << endl;
}