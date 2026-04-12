#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <climits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <set>
#include <array>
#include <unordered_map>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define VS vector<string>
#define VI vector<ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define pcc pair<char,char>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define eps 1e-14
#define FST first
#define SEC second
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15)

namespace {
	struct input_returnner {
		ll N; input_returnner(ll N_ = 0) :N(N_) {}
		template<typename T> operator vector<T>() const { vector<T> res(N); for (auto &a : res) cin >> a; return std::move(res); }
		template<typename T> operator T() const { T res; cin >> res; return res; }
		template<typename T> T operator - (T right) { return T(input_returnner()) - right; }
		template<typename T> T operator + (T right) { return T(input_returnner()) + right; }
		template<typename T> T operator * (T right) { return T(input_returnner()) * right; }
		template<typename T> T operator / (T right) { return T(input_returnner()) / right; }
		template<typename T> T operator << (T right) { return T(input_returnner()) << right; }
		template<typename T> T operator >> (T right) { return T(input_returnner()) >> right; }
	};
	template<typename T> input_returnner in() { return in<T>(); }
	input_returnner in() { return input_returnner(); }
	input_returnner in(ll N) { return std::move(input_returnner(N)); }
}

ll MOD = 1e9 + 7;

void solve();

signed main() {
	SETUP;
	solve();
	system("pause");
	return 0;
}

#define int ll

// binomial coefficients O(n^2)
// res[i][j] = C(i,j) (i , j <= n)
// C(i,j) =  C(i-1, j-1) + C(i-1, j)
vector<vector<int> > BinomialCoefficients(int n) {
	vector<vector<int > > res;
	res.resize(max(n+1,2LL));
	res[0].push_back(1);
	res[1].push_back(1);
	res[1].push_back(1);

	FOR(i, 2, res.size()){
		res[i].push_back(1);
		FOR(j,1,i){
			res[i].push_back((res[i - 1][j - 1] + res[i - 1][j])%MOD);
		}
		res[i].push_back(1);
	}
	return res;
}

// Stirling NUmber of The Second Kind O(n^2)
// note: NOT symmetry!!!
// S(n, k) = S(n, k-1) + k*S(n-1, k)
vector<vector<int> > StirlingNumber2(int n) {
	vector<vector<int > > res;
	res.resize(max(n+1,2LL));
	res[0].push_back(1);
	res[1].push_back(1);
	res[1].push_back(1);

	FOR(i, 2, res.size()) {
		res[i].push_back(1);
		FOR(j,1,i){
			res[i].push_back((res[i-1][j - 1] + (j+1)*res[i-1][j]) % MOD);
		}
		res[i].push_back(1);
	}
	return res;
}

void solve() {
	int N; cin >> N >> MOD;
	vector<vector<int> > b = BinomialCoefficients(N);
	vector<vector<int> > s2 = StirlingNumber2(N);
	vector<int> pow2(N*N+1);
	vector<int> powpow2(N+1);
	pow2[0] = 1;
	powpow2[0] = 2;
	FOR(i, 1, pow2.size()) pow2[i] = (pow2[i - 1] * 2)%MOD;
	FOR(i, 1, powpow2.size()) powpow2[i] = (powpow2[i - 1] * powpow2[i - 1]) % MOD;
	vector<int> ways(N + 1);

	int res = 0;
	REP(i, ways.size()) {
		int w = 0;
		REP(j, i + 1) {
			int temp = (s2[i][j] * pow2[(N - i)*j]) % MOD;
			temp = (temp * powpow2[N - i]) % MOD;
			w = (w + temp) % MOD;
		}
		int temp = (w * b[N][i]) % MOD;
		temp *= (i % 2 == 0 ? 1 : -1);
		res = (res + temp);
		while (res < 0) res += MOD;
		res %= MOD;
	}
	cout << res << endl;
}
