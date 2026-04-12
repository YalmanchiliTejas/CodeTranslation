#include <bits/stdc++.h>

#pragma region Macro
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define SORT(v) sort(v.begin(), v.end())
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define vvi vector<vector<int>>
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#pragma endregion

// auto mod int
// source : https://github.com/atcoder-live/library
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
const int MOD = 998244353;
struct mint {
	ll x; // typedef long long ll;
	mint(ll x=0):x((x%mod+mod)%mod){}
	mint operator-() const { return mint(-x);}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}
	
	// for prime mod
	mint inv() const { return pow(mod-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

void solve(){
	#define int ll
	// ここに処理を記述
	// コンパイル時はエイリアス「gpp」--> c++17でコンパイル
	
	int n;
	cin >> n;

	vi a(n);
	mint sum = 0;
	rep(i,n){
		cin >> a[i];
		sum += a[i];
	}

	mint ans=0;

	rep(i,n-1){
		sum -= a[i];
		mint add = (mint)a[i] * sum;
		ans += add;
	}

	cout << ans << endl;

}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	
	solve();
	return 0;
}