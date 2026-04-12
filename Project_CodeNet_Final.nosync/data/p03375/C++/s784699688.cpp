#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {cww() {CIN_ONLY{ios::sync_with_stdio(false); cin.tie(0);}}
}star;
#define DEBUG if(0)
#endif

#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r){bool a = l>r; if (a)l = r; return a;}
template <typename T>inline bool chmax(T &l, T r){bool a = l<r; if (a)l = r; return a;}
template <typename T>istream& operator>>(istream &is, vector<T> &v){for (auto &it : v)is >> it;return is;}

class range {private: struct I { int x; int operator*() { return x; }bool operator!=(I& lhs) { return x<lhs.x; }void operator++() { ++x; } }; I i, n;public:range(int n) :i({ 0 }), n({ n }) {}range(int i, int n) :i({ i }), n({ n }) {}I& begin() { return i; }I& end() { return n; }};

int mod;
//a^n (mod mod)
//O(log a)
LL Pow(LL a, LL n, int M = mod) {
	LL res = 1;
	a %= M;
	while (n) {
		if (n & 1)
			res = (res*a) % M;
		a = (a*a) % M;
		n >>= 1;
	}
	return res;
}
LL cnt[112345];
// mを法とするaの逆元
// O(log a)
inline LL invMod(LL a, LL m = mod) {
	LL b = m, u = 1, v = 0;
	while (b) {
		LL t = a / b;
		swap(a -= t * b, b);
		swap(u -= t * v, v);
	}
	return (u % m + m) % m;
}


// 階乗
// O(n)
constexpr int SZ = 112345;
LL fact[SZ];
LL rfact[SZ];
LL f[3123][3123];
void init() {
	fact[0] = 1;
	for (int i = 1; i < SZ; i++)
		fact[i] = fact[i - 1] * i%mod;
	rfact[SZ - 1] = invMod(fact[SZ - 1]);
	for (int i = SZ - 1; i > 0; i--) {
		rfact[i - 1] = rfact[i] * i%mod;
	}
	for (int i : range(3123))
		for (int j : range(3123))
			f[i][j] = 0;
	f[0][0] = 1;
	for (int i : range(1, 3123)) {
		for (int j : range(0, i + 1)) {
			if(j>0)f[i][j] += f[i - 1][j - 1];
			f[i][j] += (j+1) * f[i - 1][j];
			f[i][j] %= mod;
		}
	}
}

// 組み合わせnCk (mod mod)
// O(1)
LL Comb(LL n, LL k) {
	LL u = fact[n];
	LL d = (rfact[k] * rfact[n - k]) % mod;
	return u * d%mod;
}

int main() {
	int N;
	while (cin >> N >> mod) {
		init();
		for (int i : range(N + 1)) {
			
			cnt[i] = 0;
			LL p = Pow(2, Pow(2, N - i, mod - 1));
			LL beet = Pow(2, N - i);
			LL t = 1;
			for (int j : range(i+1)) {
				cnt[i] += t*f[i][j] % mod;
				t = t * beet%mod;
			}
			cnt[i] %= mod;
			cnt[i] = cnt[i] * p % mod;
			cnt[i] = cnt[i] * Comb(N, i) % mod;
		}
		LL ret = 0;
		for (int i : range(N + 1)) {
			if (i % 2 == 0)ret += cnt[i];
			else ret += mod - cnt[i];
		}
		cout << ret % mod << endl;
	}
	return 0;
}
