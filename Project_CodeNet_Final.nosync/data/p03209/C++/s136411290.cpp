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

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep1(i,n) for(int i = (n); i >= 1; --i)
#define REP(i,n,m) for(int i = (n); i < (m); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cerr << v << " "; cerr << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

template<class T> inline bool chmax(T& a, T b) { if (a <= b) { a = b; return true; } else return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

struct UnionFind {
	UnionFind(int n) {
		par = new int[n + 1];
		size = new int[n + 1];
		height = new int[n + 1];
		for (int i = 0; i <= n; ++i) {
			par[i] = i;
			size[i] = 1;
			height[i] = 1;
		}
	}

	void unite(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b) return;
		if (height[a] < height[b]) {
			par[a] = b;
			size[b] += size[a];
		}
		else {
			par[b] = a;
			size[a] += size[b];
			if (height[a] == height[b]) {
				height[a]++;
			}
		}

	}

	int root(int a) {
		return par[a] == a ? a : par[a] = root(par[a]);
	}

	int getSize(int a) {
		return size[root(a)];
	}

	bool isSame(int a, int b) {
		return root(a) == root(b);
	}

	int* size;
	int* height;
	int* par;
};

void dfs(UnionFind& uf, vector<vector<int>>& tree, int a, int b) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n,x; cin >> n >> x;

	ll layer = 1;
	vector<ll> p(n+1); p[0] = 1;
	rep(i,n) { layer = 2*layer + 3; p[i+1] = 2*p[i] + 1; }
	

	ll l = 1, r = layer + 1, level = n;
	ll ans = 0;
	while (level >= 0) {
		ll mid = (l + r) / 2;
		if (x < l) break;
		if (r <= x) { ans += p[level]; break; }
		if (level == 0 && l == x) { ans++; break; }

		if (mid == x) { ans += p[level - 1] + 1; break; }
		if (mid < x) { l = mid + 1; r--; ans += p[level - 1] + 1; }
		else { r = mid; l++; }
		level--;
	}
	cout << ans << endl;

}