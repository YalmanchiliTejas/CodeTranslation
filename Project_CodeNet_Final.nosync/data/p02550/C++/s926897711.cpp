#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <numeric> //lcm
#include <iomanip> //double精度 setprecision

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep1(i,n) for(int i = (n); i >= 1; --i)
#define REP(i,n,m) for(int i = (n); i < (m); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cerr << v << " "; cerr << endl;
#define debug2D(vec2D, w) for(auto vec : vec2D) { for (auto v : vec) cerr << setw(w) << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

const char en = '\n';

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

typedef vector<vector<int>> Graph;
void add_edge(Graph& g, int from, int to, bool isDirected) {
	g[from].push_back(to);
	if (!isDirected) g[to].push_back(from);
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

//int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};


//O(sqrt(n))
map<ll, int> primeFactor(ll n) {
	map<ll, int> ret;

	while (n % 2 == 0) {
		n /= 2;
		ret[2]++;
	}

	int i = 3;
	while (n > 1 && (ll)i * i <= n) {
		while (n % i == 0) {
			n /= i;
			ret[i]++;
		}
		i += 2;
	}

	if (n != 1) ret.insert({ n,1 });

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,x,m; cin >> n >> x >> m;
	vector<ll> a(m,0), sum(m+1,0), ainv(m,-1);
	ll i = 0;
	a[0] = x; ainv[x] = 0;
	sum[1] = x;
	while (ainv[a[i] * a[i] % m] == -1) {
		i++;
	  a[i] = a[i-1]*a[i-1] % m;
		sum[i+1] = sum[i] + a[i];
		ainv[a[i]] = i;
	}

	ll l = ainv[a[i]*a[i]%m];

	ll loopL = i+1-l;

	//cerr << l << " " << loopL << endl;
	//debug(a);
	//debug(ainv);
	//debug(sum);

	if (i < n) cout << sum[l] + ((n-l) / loopL)*(sum[i+1] - sum[l]) + sum[(n-l) % loopL + l] - sum[l] << endl;
	else cout << sum[n] << endl;
}

