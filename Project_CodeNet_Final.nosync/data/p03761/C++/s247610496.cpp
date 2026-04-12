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

#define MOD 998244353
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
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


//nCr,nPr,modの逆元
class Combination {
public:
	Array fact;//n！
	Array inv;//n!の逆元
	ll mod;
	Combination(ll n, ll _mod) {
		mod = _mod;
		fact.resize(n + 1);
		fact[0] = 1;
		REP(i, n) {
			fact[i + 1] = (fact[i] * (i + 1LL)) % mod;
		}
		inv.resize(n + 1);
		inv[n] = mod_inv(fact[n]);
		for (int i = n; i > 0; i--) {
			inv[i - 1] = inv[i] * i % mod;
		}
	}
	//modの逆元
	ll mod_inv(ll x) {
		ll n = mod - 2;
		ll res = 1LL;
		while (n > 0) {
			if (n & 1) res = res * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return res;
	}
	ll nCr(ll n, ll r) {
		return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod;
	}
	ll nPr(ll n, ll r) {
		return (fact[n] * inv[n - r]) % mod;
	}
	ll nHr(ll n, ll r) {
		//重複組み合わせ：n種類のものからr個取り出す組み合わせ
		return nCr(r + n - 1, r);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	cin >> n;
	vector<string> s(n);
	REP(i, n) cin >> s[i];

	map<ll, ll> mp;
	REP(i,s[0].size()) {
		mp[s[0][i]]++;
	}

	for (int j = 1; j < n; j++) {
		map<ll, ll> mp2;
		REP(i, s[j].size()) {
			mp2[s[j][i]]++;
		}
		auto it = mp.begin();
		while(it!=mp.end()) {
			if (mp2.find(it->first)==mp2.end()) {
				it=mp.erase(it);
			}
			else {
				it->second = min(it->second, mp2[it->first]);
				it++;
			}
		}
	}

	for (auto i : mp) {
		while (i.second--) {
			cout << (char)i.first;
		}
	}
	cout << endl;

	return 0;
}