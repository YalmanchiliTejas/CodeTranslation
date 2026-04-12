#pragma GCC optimize("O2")

#include <bits/stdc++.h>
#ifdef DEBUG
	#include "debug.hpp"
#endif

using namespace std;

#define all(c) (c).begin(), (c).end()
#define traverse(c, it) for(auto it = (c).begin(); it != (c).end(); it++)
#define rep(i, N) for(int i = 0; i < (N); i++)
#define rep1(i, N) for(int i = 1; i <= (N); i++)
#define rep2(i, s, e) for(int i = (s); i <= (e); i++)
#define rep3(i, s, e, d) for(int i = (s); (d) >= 0 ? i <= (e) : i >= (e); i += (d))
#define pb push_back


#ifdef DEBUG
	#define debug(x...) { dbg::depth++; string dbg_vals = dbg::to_string(x); dbg::depth--; dbg::fprint(__func__, __LINE__, #x, dbg_vals); }
	#define light_debug(x) { dbg::light = 1; dbg::dout << __func__ << ":" << __LINE__ << "  " << #x << " = " << x << endl; dbg::light = 0; }
#else
	#define debug(x...)
	#define light_debug(x) 
#endif

template<typename T>
inline T& ckmin(T& a, T b) { return a = a > b ? b : a; }

template<typename T>
inline T& ckmax(T& a, T b) { return a = a < b ? b : a; }

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int mod;
class Modular {
	int value;
	//int mod;
public:
	Modular(long long x) { value = (int)((x % mod + mod) % mod); }

	inline Modular& operator +=(Modular x) { value += x.value; if(value >= mod) value -= mod; return *this; }

	inline Modular& operator -=(Modular x) { value -= x.value; if(value < 0) value += mod; return *this; }

	inline Modular& operator *=(Modular x) { value = (int)((long long)x.value * value % mod); return *this; }

	inline Modular& operator /=(Modular x) { *this *= x.pow(-1); } //TODO : Make this Extended Euclid to handle composite moduli.

	inline Modular operator -() const { return Modular(-value); }

	inline Modular& operator ++() { return *this += 1; }

	inline Modular& operator --() { return *this -= 1; }

	inline Modular operator ++(int) { Modular t = *this; *this += 1; return t; }

	inline Modular operator --(int) { Modular t = *this; *this -= 1; return t; }

	Modular pow(int n) const { 
		while(n < 0) n += mod - 1;
		Modular v(1), a(value);
		for(; n; a *= a, n >>= 1)
			if(n & 1) v *= a;
		return v;
	}

	inline Modular operator +(Modular x) const { return x += *this; }

	inline Modular operator -(Modular x) const { return *this + (-x); }

	inline Modular operator *(Modular x) const { return x *= *this; }

	inline Modular operator /(Modular x) const { return (*this) * x.pow(-1); } 

	inline bool operator ==(Modular x) const { return value == x.value; }

	inline bool operator !=(Modular x) const { return value != x.value; }

	inline explicit operator int() const { return value; }

	Modular fact() const { 
		Modular x(1);
		for(int i = 1; i <= value; ++i) x *= i;
		return x;
	}

	friend ostream& operator <<(ostream& os, Modular x) { return os << x.value; }

	friend istream& operator >>(istream& is, Modular& x) { is >> x.value; x.value %= mod; return is; }
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	#ifdef DEBUG
		freopen("debug", "w", stderr);
	#endif
	
	ll N; int X; cin >> N >> X >> mod;

	vector<int> vis(mod);
	vector<int> vals;
	Modular cur(X);
	int p = -1;
	rep1(i, N) {
		vals.pb(int(cur));
		vis[int(cur)] = i;
		cur *= cur;
		if(vis[int(cur)]) { p = vis[int(cur)] - 1; break; }
	}

	if(p != -1){
		int period = vals.size() - p;
		ll sum = 0;
		ll ans = 0;
		rep(i, p) ans += vals[i];
		rep2(i, p, (int)vals.size() - 1)
			sum += vals[i];
		N -= p;
		ans += sum * (N / period);
		N %= period;
		rep2(i, p, p + N - 1) ans += vals[i];
		cout << ans << '\n';

	} else {
		cout << accumulate(all(vals), 0LL) << '\n';
	}


	#ifdef DEBUG
		dbg::dout << "\nExecution time: " << clock() << "ms\n";
	#endif

	return 0;
}
