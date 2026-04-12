#include<bits/extc++.h>
#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector,O3")
using namespace std;
using ll = long long;using ull = unsigned long long;using ul = unsigned;using db = double;using __gnu_pbds::null_type;
#ifdef _debug 
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) 0&&0
#endif
#define eout(i) {cout << (i) << '\n';exit(0);}
#define priority_queue __gnu_pbds::priority_queue
#define unordered_map __gnu_pbds::gp_hash_table
#define rep(a, b) {for(int _i = a;_i > 0;--_i){b;}}
#define multe int _T;for(cin >> _T;_T--;)
template<typename T> inline ostream& operator << (ostream &ou, const vector<T> &a){for(auto it = a.begin();it != a.end();++it)ou << (it != a.begin() ? " " : "") << *it;return ou;}
template<typename T1, typename T2>inline istream& operator >> (istream &in, pair<T1, T2> &a){return in >> a.first >> a.second;}
template<typename T1, typename T2>inline ostream& operator << (ostream &ou, const pair<T1, T2> &b){return ou << b.first << ' ' << b.second;}
template<typename T> void read(int n, T s){while(n--)cin >> *s, ++s;}
template<typename T> void write(int n, T s){while(n--)cout << *s << " \n"[n==0], ++s;}
pair<long long, long long> ext_gcd(const long long &a, const long long &b){static vector<pair<long long,long long>> togo;pair<long long, long long> res{0ll, 1ll};togo.reserve(20);togo.emplace_back(a, b);while(true){long long a = togo.back().first, b = togo.back().second;if(a % b)togo.emplace_back(b, a % b);else break;}togo.pop_back();while(!togo.empty()){res = {res.second, res.first - togo.back().first / togo.back().second * res.second};togo.pop_back();}return res;} 
long long ext_inv(const long long &a, const long long &p){return (ext_gcd(a, p).first + p) % p;}
vector<int> kfunc(const string &w){vector<int> k(w.size());for(int q = 0, i = 1;i < w.size();++i){for(;q > 0 and w[i] != w[q];q = k[q-1]);k[i] = (q += w[i] == w[q]);}return k;}
vector<int> zfunc(const string &w){vector<int> z(w.size());for(int l = 0, i = 1;i < w.size();++i){z[i] = max(0, min(l+z[l] - i, z[i-l]));for(;i+z[i] < w.size() and w[i+z[i]] == w[z[i]];++z[i])l = i;}return z;}
template<typename T> using rbtree = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T> inline long long pow(long long v, long long t, const T &p){long long res = 1;for(;t;t >>= 1, v = v * v % p)if(t & 1)res = res * v % p;return res;}
template<typename T> inline void floyd_warshall(vector<vector<T>> &dp){for(int i = 0;i < dp.size();++i)for(int j = 0;j < dp.size();++j)for(int k = 0;k < dp.size();++k)dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);}
template<typename T> inline vector<vector<T>> operator * (const vector<vector<T>> &a, const vector<vector<T>> &b){assert(a.front().size() == b.size());vector<vector<T>> res(a.size(), vector<T>(b.front().size()));for(int i = 0;i < a.size();++i)for(int j = 0;j < b.front().size();++j)for(int k = 0;k < a.front().size();++k)res[i][j] += a[i][k] * b[k][j];return res;}
template<typename T> inline vector<vector<T>> pow(vector<vector<T>> v, long long t){vector<vector<T>> res;for(;t;t >>= 1, v = v * v)if(t & 1)res = (res.empty() ? v : res * v);return res;}
template<typename T1, typename T2>inline pair<T1,T2> operator + (const pair<T1,T2> &a, const pair<T1,T2> &b){return {a.first + b.first, a.second + b.second};}
template<typename T1, typename T2>inline pair<T1,T2> operator - (const pair<T1,T2> &a, const pair<T1,T2> &b){return {a.first - b.first, a.second - b.second};}
template<typename T1, typename T2>inline long long operator ^ (const pair<T1,T2> &a, const pair<T1,T2> &b){return (long long)a.first * b.second - (long long)a.second * b.first;}
int n, m;
int s, t;
#define int ll
#define ull ll
const int maxn = 100001;
const int p = 1e9+7;
ull froms[maxn], fromt[maxn], cnta[maxn], cntb[maxn];
vector<pair<int,ull>> edge[maxn];
struct info{
	int pos;
	ull cost;
	info(int pos, ull cost):pos(pos), cost(cost){};
};
struct cmp{
	bool operator()(const info &a, const info &b)const{
		return a.cost > b.cost;
	}
};
const ll inf = 1ll << 59;
void dij(int s, ull *d, ull *dp){
	fill(d, d+n+1, inf);
	priority_queue<info, cmp> togo;
	d[s] = 0;
	dp[s] = 1;
	togo.push(info(s, 0));
	while(togo.size()){
		int now = togo.top().pos;
		ull cost = togo.top().cost;
		togo.pop();
		if(cost > d[now])continue;
		for(auto &i : edge[now]){
			if(i.second+d[now] < d[i.first]){
				d[i.first] = d[now] + i.second;
				dp[i.first] = dp[now];
				togo.push(info(i.first, d[i.first]));
			}
			else if(i.second+d[now] == d[i.first]){
				dp[i.first] = (dp[i.first]+dp[now]) % p;
			}
		}
	}
}
// vector<pair<pair<int,int>, ull>> alle;
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> s >> t;
	for(int a, b, d;m--;){
		cin >> a >> b >> d;
		// alle.push_back({{a, b}, d});
		edge[a].emplace_back(b, d);
		edge[b].emplace_back(a, d);
	}
	for(int i = 1;i <= n;++i)sort(edge[i].begin(), edge[i].end());
	dij(s, froms, cnta);
	dij(t, fromt, cntb);
	ull res = cnta[t] * cnta[t] % p;
	ull len = froms[t];
	assert(fromt[s] == froms[t]);
	for(int a = 1;a <= n;++a)for(auto &e : edge[a]){
		int b = e.first;
		ull d = e.second;
		// if(froms[b]+fromt[a] < froms[a]+fromt[b])swap(a, b);
		if(froms[a]+fromt[b] + d == len){
			assert((froms[a]<fromt[b]+d && fromt[b]<froms[a]+d) == 
			((froms[a]<<1) < len and (fromt[b]<<1) < len));
				if((froms[a]<<1) < len and (fromt[b]<<1) < len){
				res = (res+p-(
					(cnta[a]*cntb[b]%p)*(cnta[a]*cntb[b]%p)%p
				)) % p;
			}
		}
	}
	for(int i = 1;i <= n;++i){
		if(froms[i]+fromt[i] == len and froms[i] == fromt[i]){
			res = (res+p-(
				cnta[i]*cntb[i]%p*cnta[i]%p*cntb[i]%p
			)) % p;
		}
	}
	cout << res << '\n';
}
