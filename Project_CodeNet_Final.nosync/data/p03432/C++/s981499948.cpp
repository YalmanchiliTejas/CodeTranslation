#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

const int mod = 998244353;
int add(int a, int b) { a += b; if(a >= mod) a -= mod; return a; }
void add_self(int & a, int b) { a = add(a, b); }
void add_self(ll & a, int b) { a = add(a, b); }
int sub(int a, int b) { a -= b; if(a < 0) a += mod; return a; }
void sub_self(int & a, int b) { a = sub(a, b); }
int mul(int a, int b) { return (ll) a * b % mod; }
void mul_self(int & a, int b) { a = mul(a, b); }
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) mul_self(r, a);
		mul_self(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }
#define div div_ok
int div(int a, int b) { return mul(a, my_inv(b)); }



#define REP(i,n) for(int i = 0; i < int(n); ++i)
/*Precision error max_ans/1e15 (2.5e18) for (long) doubles.
So integer rounding works for doubles with answers 0.5*1e15,
e.g. for sizes 2^20 and RANDOM positive integers up to 45k.
Those values assume DBL_MANT_DIG=53 and LDBL_MANT_DIG=64.
For input in [0, M], you can decrease everything by M/2.
If there are many small vectors, uncomment "BRUTE FORCE".*/
typedef double ld; // 'long double' is 2.2 times slower
struct C {
	ld real, imag;
	C operator * (const C & he) const {
		return C{real * he.real - imag * he.imag,
				real * he.imag + imag * he.real};
	}
	void operator += (const C & he) {
		real += he.real; imag += he.imag;
	}
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].real, om[k].imag * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.real - y.real, x.imag - y.imag};
			}
	}
	if(rev) REP(i, n) a[i].real /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b, bool split = false) {
	if(a.empty() || b.empty()) return {};
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	/* if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
		return ans; } */
	while(n&(n-1)) ++n;
	// http://codeforces.com/blog/entry/48417
	auto speed = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].real + w[j].real * r, w[i].imag
				- w[j].imag * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { // standard fast version
		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].real = a[i];
		REP(i, b.size()) in[i].imag = b[i];
		dft(in, false);
		REP(i, n) done[i] = speed(in, i, 0) * speed(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].real) : done[i].real;
	//REP(i,ans.size())err=max(err,abs(done[i].real-ans[i]));
	}
	else { // Split big INTEGERS into pairs a1*M+a2,
		const T M = 1<<16; // where M = sqrt(max_absvalue).
		vector<C> t[2]; // This version is 2.2-2.5 times slower.
		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a;
			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		int mno = 1;
		for(int s = 0; s < 3; ++s, mul_self(mno, M)) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
			dft(prod, true);
			REP(i, ans.size()) add_self(ans[i], mul(llround(prod[i].real)%mod, mno));
		}
	}
	return ans;
}


















const int nax = 10123;
int fac[nax], inv_fac[nax];

int binomial(int a, int b) {
	assert(a >= b && b >= 0);
	return mul(fac[a], mul(inv_fac[b], inv_fac[a-b]));
}

int main() {
	fac[0] = 1;
	for(int i = 1; i < nax; ++i) fac[i] = mul(fac[i-1], i);
	for(int i = 0; i < nax; ++i) inv_fac[i] = my_inv(fac[i]);
	
	int h, w;
	cin >> h >> w;
	
	vector<int> dp(h + 1);
	dp[0] = 1;
	while(w--) {
		vector<ll> changed(h + 1), extra(h + 1);
		for(int i = 0; i <= h; ++i) {
			changed[i] = mul(dp[i], inv_fac[i]);
			extra[i] = inv_fac[i+2];
		}
		vector<ll> pom = multiply(changed, extra, true);
		vector<int> nowy(h + 1);
		for(int i = 0; i <= h; ++i) {
			nowy[i] = pom[i];
			//~ for(int j = 0; j <= i; ++j)
				//~ add_self(nowy[i], mul(extra[i-j], changed[j]));
			mul_self(nowy[i], fac[i+2]);
			sub_self(nowy[i], mul(i, dp[i]));
		}
		dp = nowy;
	}
	int answer = 0;
	for(int i = 0; i <= h; ++i)
		add_self(answer, mul(dp[i], binomial(h, i)));
	printf("%d\n", answer);
	//~ debug() << imie(dp);
}
