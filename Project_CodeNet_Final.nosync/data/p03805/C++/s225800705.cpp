
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using VI=std::vector<ll>;
using VC=std::vector<char>;
using VB=std::vector<bool>;
using VD=std::vector<ld>;
using VVI=std::vector<VI>;
using VVC=std::vector<VC>;
using VS=std::vector<string>;
using PLL =std::pair<ll,ll>;
using PLD=std::pair<ld,ld>;
using VPLL=std::vector<PLL>;
#define print(x) std::cout<<x<<"\n"
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).std::rbegin(),(x).std::rend()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *std::max_element((x).begin(),(x).std::end())
#define MIN(x) *std::min_element((x).begin(),(x).std::end())
#define SORTR(x) std::sort((x).std::rbegin(),(x).std::rend())
#define SORT(x) std::sort((x).begin(),(x).std::end())
#define SUM(x) std::accumulate((x).begin(),(x).end(), 0)
#define FILL(x,a) std::fill(x.begin(),x.end(),a)
#define EACH(i,x) for(typeof((x).std::begin()) i=(x).begin(); i!=(x).end(); ++i)
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


ll dfs(VB visited,VVI ab,ll s=0){
	visited[s]=true;
	if(!EXIST(visited,false)) return 1;
	ll ret=0;
	for(auto &v:ab[s]){
		if(visited[v]) continue;
		else{
			ret+=dfs(visited,ab,v);
		}
	}
	return ret;
}

void Main()
{
	ll n, m, l;
	ll res = 0;
	string s, t, u;
	string sres = "No or NO";

	cin >> n>>m;
	VVI ab(n);
	rep(i, m) {
		ll a, b;
		cin >> a >> b;
		--a; --b;
		ab[a].emplace_back(b);
		ab[b].emplace_back(a);
	}
	VB visited(n,false);
	res=dfs(visited,ab);
	print(res);
	return;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
