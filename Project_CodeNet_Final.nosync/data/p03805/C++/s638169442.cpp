#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using VI=vector<ll>;
using VC=vector<char>;
using VB=vector<bool>;
using VD=vector<ld>;
using VVI=vector<VI>;
using VVC=vector<VC>;
using VS=vector<string>;
using PLL =pair<ll,ll>;
using PLD=pair<ld,ld>;
using VPLL=vector<PLL>;
#define print(x) cout<<x<<"\n
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element((x).begin(),(x).end())
#define MIN(x) *min_element((x).begin(),(x).end())
#define SORTR(x) sort((x).rbegin(),(x).rend())
#define SORT(x) sort((x).begin(),(x).end())
#define SUM(x) accumulate((x).begin(),(x).end(), 0)
#define FILL(x,a) fill(x.begin(),x.end(),a)
#define EACH(i,x) for(typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

const ll INF = 1e18;
const ld EPS   = 1e-10;
const int MOD  = int(1e9)+7;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template <class BidirectionalIterator>
bool next_partial_permutation(BidirectionalIterator first, BidirectionalIterator middle,BidirectionalIterator last){reverse(middle, last); return next_permutation(first , last);}
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll GCD(VI v){ll a = v[0]; for (ll i = 1; i<SIZE(v); i++) {a = gcd(a, v[i]);} return a;}
ll LCM(VI v){ll a = v[0]; for (ll i = 1; i<SIZE(v); i++) {a = lcm(a, v[i]);} return a;}
VI Bit2Vector(const ll bit, ll n) {	VI s;	rep(i,n) if (bit & (1 << i)) s.push_back(i); return s;}

struct DFS{
public:
	VVI to;
	VB visited;
	//ll start;

	DFS(VVI &t,VB& vis,ll s){
		//to=t;
		//visited=vis;
		//start=s;
	}

	ll search(VVI& to, vector<bool> visited, ll s = 0) {
		visited[s] = true;
		if (!EXIST(visited, false)) return 1;
		ll ret = 0;
		for (auto& v : to[s]) {
			if (visited[v]) continue;
			ret += search(to, visited, v);
		}
		return ret;
	}
};


ll dfs_search(VVI& to, vector<bool> visited, ll s = 0) {
	visited[s] = true;
	if (!EXIST(visited, false)) return 1;
	ll ret = 0;
	for (auto& v : to[s]) {
		if (visited[v]) continue;
		ret += dfs_search(to, visited, v);
	}
	return ret;
}

void Main()
{
	ll n,m,l; ll res=0;
	string s,t,u; string sres="No or NO";

	cin >> n >> m;
	VVI to(n,VI());
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	vector<bool> visited(n,false);

	DFS dfs(to,visited,0);

	dfs.visited=visited;
	dfs.to=to;

	res=dfs.search(to,visited,0);
	//res=dfs_search(to,visited,0);
	cout << res << "\n";
	return;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
