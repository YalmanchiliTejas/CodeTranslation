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
#define debug2D(vec2D, w) for(auto vec : vec2D) { for (auto v : vec) cerr << setw(w) << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

const char en = '\n';

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

typedef ll Weight;
typedef vector<vector<Weight>> Graph;
void add_edge(vector<vector<Weight>>& g, Weight from, Weight to, bool isDirected) {
	g[from].push_back(to);
	if (!isDirected) g[to].push_back(from);
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  cin >> n;
	//vector<ll> a(n); rep(i,n) cin >> a[i];

	if (n >= 30) cout << "Yes" << endl;
	else cout << "No" << endl;

}
