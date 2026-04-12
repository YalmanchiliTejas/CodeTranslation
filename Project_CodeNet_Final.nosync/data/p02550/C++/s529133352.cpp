#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> P;

constexpr ll INF = 1e15;
constexpr ll mod = 998244353;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n,x,m;
	cin >> n >> x >> m;
	vector<ll> ai;	
	vector<ll> sums;
	ai.push_back(x);
	sums.push_back(0);
	sums.push_back(x);
	map<int, int> his;
	his[x] = 0;	
	for (ll i = 1; i <= n; i++) {
		ll nx = ai.back();
		nx *= nx;
		nx %= m;
		if (his.count(nx)) {
			ll pi = his[nx];
			ll pValue = sums[pi];
			ll loop = i - pi;
			ll loopValue = sums[i] - sums[pi];
			ll p = n - pi;
			ll add = (p / loop)* loopValue;
			ll rest = p % loop + pi;
			ll rValue = sums[rest] - sums[pi];
			ll all = pValue + add + rValue;
			cout << all << endl;
			return 0;
		}
		ai.push_back(nx);
		sums.push_back(sums.back() + nx);
		his[nx] = i;
	}
	cout << sums[n] << endl;
	return 0;
}
