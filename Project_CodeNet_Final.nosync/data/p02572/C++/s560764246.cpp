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

typedef vector<vector<int>> Graph;
void add_edge(Graph& g, int from, int to, bool isDirected) {
	g[from].push_back(to);
	if (!isDirected) g[to].push_back(from);
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }


struct ModInt {
	ModInt() : mInt(-1) {};
	ModInt(ll n) : mInt(n) {};
	//~ModInt(){};
	ll mInt;
	static vector<ModInt> mFact;
	static ll mMod;
	//todo
	ModInt& operator=(const ModInt& a) { mInt = a.mInt; return *this; }
	ModInt& operator+=(const ModInt& a) { mInt += a.mInt; mInt %= mMod; return *this; }
	ModInt& operator-=(const ModInt& a) { mInt -= a.mInt; if (mInt < 0) mInt += mMod; return *this; }
	ModInt& operator*=(const ModInt& a) { mInt *= a.mInt; mInt %= mMod; return *this; }
	ModInt operator+(const ModInt a) { return ModInt(mInt + a.mInt % mMod); }
	ModInt operator-(const ModInt a) { return ModInt(mInt - a.mInt < 0 ? mInt - a.mInt + mMod : mInt - a.mInt); }
	ModInt operator*(const ModInt a) { return ModInt(mInt * a.mInt % mMod); }
	ModInt& operator=(const ll& a) { mInt = a; return *this; }
	ModInt& operator+=(const ll& a) { mInt += a; mInt %= mMod; return *this; }
	ModInt& operator-=(const ll& a) { mInt -= a; if (mInt < 0) mInt += mMod; return *this; }
	ModInt& operator*=(const ll& a) { mInt *= a; mInt %= mMod; return *this; }
	ModInt operator+(const ll a) { return ModInt(mInt + a % mMod); }
	ModInt operator-(const ll a) { return ModInt(mInt - a < 0 ? mInt - a + mMod : mInt - a); }
	ModInt operator*(const ll a) { return ModInt(mInt * a % mMod); }
	ModInt operator++() { return ModInt(++mInt % mMod); }
	ModInt operator--() { return ModInt(++mInt % mMod); }
	bool operator==(ModInt a) { return mInt == a.mInt; }
	bool operator!=(ModInt a) { return mInt != a.mInt; }
	friend ostream& operator<<(ostream& os, const ModInt& n) {
		return os << n.mInt;
	}
	friend istream& operator>>(istream& is, ModInt& n) {
		return is >> n.mInt;
	}
};

ll ModInt::mMod = MOD;
vector<ModInt> ModInt::mFact(1, 1);

void setFact(ll n) {
	ModInt::mFact[0] = 1;
	rep1(i, n) ModInt::mFact[i] *= ModInt::mFact[i - 1];
}

void setMod(ll mod) {
	ModInt::mMod = mod;
}

ModInt mod_pow(ModInt a, ll b) {
	ModInt ret = 1;
	while (b > 0) {
		if (b & 1) ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

ModInt mod_pow(ll a, ll b) { return mod_pow(ModInt(a), b); }

ModInt inv(ModInt n) {
	return mod_pow(n, n.mMod - 2);
}

ModInt fact(ModInt n) {
	ll s = ModInt::mFact.size();
	if (s - 1 >= n.mInt) return ModInt::mFact[n.mInt];

	ModInt fac = ModInt::mFact[s - 1];
	for (int i = s; i <= n.mInt; ++i) {
		fac *= i;
		ModInt::mFact.push_back(fac);
	}
	return fac;
}


ModInt comb(ll n, ll r) {
	ModInt com = 1;
	if (n / 2 < r) return comb(n, n - r);
	else {
		for (int i = 0; i < r; ++i)
			com *= n - i;
		return com * inv(fact(r));
	}
}

void setComb(vector<ModInt>& combs, ll n, ll r) {
	// nCk = nCk-1 * n-k+1/k
	// combs[i] = nCi
	ModInt comb = 1;
	combs[0] = combs[n] = comb;
	if (n / 2 < r) setComb(combs, n, n - r);
	else {
		for (ll i = 1; i <= r; ++i) {
			comb *= inv(i) * (n - i + 1);
			combs[i] = combs[n - i] = comb;
		}
	}
}

void setComb(vector<ModInt>& combs, ll n) { if (combs.size() < n + 1) cerr << "setComb : need n+1 size" << endl; else setComb(combs, n, (n + 1) / 2); }

void setCombAll(vector<vector<ModInt>>& combs, ll n) {
	if (combs.size() < n - 1) cerr << "setCombAll : n" << n << " is small" << endl;
	rep(i, n + 1) rep(j, i + 1) {
		if (j == 0 || j == i) combs[i][j] = 1;
		else combs[i][j] = combs[i - 1][j - 1] + combs[i - 1][j];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n; cin >> n;

	vector<ModInt> a(n); 

	rep(i, n) { cin >> a[i];}

	ModInt ans = 0, sum = 0;
	rep(i,n){ans += a[i]*sum; sum += a[i]; } 

	cout << ans << endl;
}

