#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll p = 998244353 ;

ll n, m, fact[8005], invfact[8005];
vector<ll> s, f0, f1, f2, s0, s1, s2, t;

typedef complex<double> base;
void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(int i=0; i<n/2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	/* In NTT, let prr = primitive root. Then,
	 * 		int ang = ipow(prr, (mod - 1) / n);
	 * 				if(inv) ang = ipow(ang, mod - 2);
	 * 						for(int i=0; i<n/2; i++){
	 * 									roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
	 * 											}
	 * 													Others are same. If there is /= n, do *= ipow(n, mod - 2).
	 * 															In XOR convolution, roots[*] = 1. 
	 * 																	*/
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 1;
	while(n < max(v.size(), w.size())) n <<= 1;
	n <<= 1;
	fv.resize(n);
	fw.resize(n);
	fft(fv, 0);
	fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w, ll mod){
	int n = 1;
	while(n < max(v.size(), w.size())) n <<= 1;
	n <<= 1;
	vector<base> v1(n), v2(n);
	vector<base> r1(n), r2(n);
	for(int i=0; i<v.size(); i++){
		v1[i] = base(v[i] >> 15, v[i] & 32767);
	}
	for(int i=0; i<w.size(); i++){
		v2[i] = base(w[i] >> 15, w[i] & 32767);
	}
	fft(v1, 0);
	fft(v2, 0);
	for(int i=0; i<n; i++){
		int j = (i ? (n - i) : i);
		base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
		base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
		base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
		base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
		r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
		r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
	}
	fft(r1, 1);
	fft(r2, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++){
		ll av = (ll)round(r1[i].real());
		ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
		ll cv = (ll)round(r2[i].imag());
		av %= mod, bv %= mod, cv %= mod;
		ret[i] = (av << 30) + (bv << 15) + cv;
		ret[i] %= mod;
		ret[i] += mod;
		ret[i] %= mod;
	}
	return ret;
}


ll exp(ll x, ll k) {
	if (k == 0)
		return 1;
	if (k%2 == 1)
		return x*exp(x, k-1)%p;
	ll y = exp(x, k/2);
	return y*y%p;
}

ll inv(ll x) { return exp(x, p-2); }

void init() {
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < 8005; ++i) {
		fact[i] = i*fact[i-1]%p;
		invfact[i] = inv(fact[i]);
	}
}

ll c(int x, int y) {
	if (x < y || x < 0 || y < 0)
		return 0;
	return fact[x]*invfact[y]%p*invfact[x-y]%p;
}

ll comp(ll k, ll k1) {
	if (k == k1)
		return (c(k, 2) + k + 1)%p;
	else
		return (c(k, k-k1+2)+2*c(k, k-k1+1)+c(k,k-k1))%p;
}

int main() {
	cin >> n >> m;
	init();

	s.resize(n+1);
	f0.resize(n+1);
	f1.resize(n+1);
	f2.resize(n+1);

	for (int i = 0; i <= n; ++i)
		s[i] = c(n, i);
	for (int i = 0; i <= n; ++i) {
		f0[i] = invfact[i];
		f1[i] = 2*invfact[i+1];
		f2[i] = invfact[i+2];
	}

	reverse(f0.begin(), f0.end());
	reverse(f1.begin(), f1.end());
	reverse(f2.begin(), f2.end());

	for (int i = 0; i < m; ++i) {
		t = s;
		for (int i = 0; i <= n; ++i)
			s[i] = (s[i]*fact[i])%p;
		s0 = multiply(s, f0, p);
		s1 = multiply(s, f1, p);
		s2 = multiply(s, f2, p);
		for (int j = n; j <= 2*n; ++j) {
			ll tot = 0;
			if (j >= n+2)
				tot = (tot + s2[j]*invfact[j-n-2])%p;
			if (j >= n+1)
				tot = (tot + s1[j]*invfact[j-n-1])%p;
			tot = (tot + s0[j]*invfact[j-n])%p;
			tot = (tot + p - (j-n)*t[j-n]%p)%p;
			s[j-n] = tot;
		}
	}

	cout << s[0] << endl;
}