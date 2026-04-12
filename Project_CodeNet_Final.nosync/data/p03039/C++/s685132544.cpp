#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const long long mod = 1e9 + 7;
const long long MAX_P = 200010;
typedef long long ll;
long long qp(int a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
long long qp(int a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
long long INF = 1e10;
class combination {
public:
	ll fact[MAX_P]; // n! mod pのテーブル(O(p))
	ll p;
	// factテーブルを初期化する
	combination(ll x) {  // x : 余り(1e9 + 7など)
		p = x;
		fact[0] = 1;
		for (ll i = 1; i < MAX_P; i++) {
			fact[i] = fact[i - 1] * i % p;
		}
	}
	//拡張ユークリッドの互除法
	ll extgcd(ll a, ll b, ll& x, ll& y) {
		ll d = a;
		if (b != 0) {
			d = extgcd(b, a%b, y, x);
			y -= (a / b) * x;
		}
		else {
			x = 1; y = 0;
		}
		return d;
	}
	//mod上の逆元
	ll mod_inverse(ll a, ll m) {
		ll x, y;
		extgcd(a, m, x, y); //extgcdが必要
		return (m + x % m) % m;
	}
	//n! = a p^eとしたときの a mod pを求める O(log_p a)
	ll mod_fact(ll n, ll p, ll& e) {
		e = 0;
		if (n == 0) return 1;

		//pの倍数の部分を計算
		ll res = mod_fact(n / p, p, e);
		e += n / p;

		//(p - 1)!≡-1なので、(p-1)!^(n/p)はn/pの偶奇だけで計算できる
		if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
		return res * fact[n % p] % p;
	}

	//mod p 上の二項係数
	ll mod_comb(ll n, ll k) {
		if (n < 0 || k < 0 || n < k) return 0;
		ll e1, e2, e3;
		ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
		if (e1 > e2 + e3) return 0;
		return a1 * mod_inverse(a2 * a3 % p, p) % p;
	}
};
int main() {
	ll n, m, k; cin >> n >> m >> k;
	combination c(mod);
	ll lyn, rn;
	lyn = 0; rn = 0;
	for (int i = 1; i < n; i++) {
		lyn += qp(m, 2, mod) * (n - i)*i;
		lyn %= mod;
	}
	for (int i = 1; i < m; i++) {
		rn += qp(n, 2, mod) * (m - i)*i;
		rn %= mod;
	}
	cout << c.mod_comb(n*m - 2, k - 2) * (lyn + rn) % mod << endl;
	return 0;
}