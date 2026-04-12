#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	string s;
	cin >> n >> s;

	REP(i, 2) {
		REP(j, 2) {
			Array ans(n, -1);//wolf:0 sheep:1
			ans[n-1] = i;
			ans[0] = j;

			bool flag = true;
			REP(k, n) {
				if (s[k] == 'o') {
					if (ans[k] == 1) {
						if (ans[(k + 1) % n] == -1) {
							ans[(k + 1) % n] = ans[(k - 1 + n) % n];
						}
						else {
							if (ans[(k + 1) % n] != ans[(k - 1 + n) % n]) {
								flag = false;
								break;
							}
						}
					}
					else {
						if (ans[(k+1) % n] == -1) {
							if (ans[(k-1+n) % n] == 1) {
								ans[(k + 1) % n] = 0;
							}
							else {
								ans[(k + 1) % n] = 1;
							}
						}
						else {
							if (ans[(k + 1) % n] == ans[(k - 1 + n) % n]) {
								flag = false;
								break;
							}
						}
					}
				}
				else {
					if (ans[k] == 0) {
						if (ans[(k + 1) % n] == -1) {
							ans[(k + 1) % n] = ans[(k - 1 + n) % n];
						}
						else {
							if (ans[(k + 1) % n] != ans[(k - 1 + n) % n]) {
								flag = false;
								break;
							}
						}
					}
					else {
						if (ans[(k + 1) % n] == -1) {
							if (ans[(k - 1 + n) % n] == 1) {
								ans[(k + 1) % n] = 0;
							}
							else {
								ans[(k + 1) % n] = 1;
							}
						}
						else {
							if (ans[(k + 1) % n] == ans[(k - 1 + n) % n]) {
								flag = false;
								break;
							}
						}
					}
				}
			}


			if (flag) {
				for (auto i : ans) {
					if (i == 0) {
						cout << "W";
					}
					else {
						cout << "S";
					}
				}
				cout << endl;
				return 0;
			}
		}
	}
	


	cout << -1 << endl;

	return 0;
}