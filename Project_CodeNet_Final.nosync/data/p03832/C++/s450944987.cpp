#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define inc( i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec( i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define UB upper_bound
#define LB lower_bound
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(i, v) for(auto i =  v.begin(); i !=  v.end(); ++i)
#define RFOR(i, v) for(auto i = v.rbegin(); i != v.rend(); ++i)

template<typename T> bool setmin(T & a, T b) { if(a <= b) { return false; } else { a = b; return true; } }
template<typename T> bool setmax(T & a, T b) { if(b <= a) { return false; } else { a = b; return true; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T> ostream & operator<<(ostream & os, const vector<T> & v) {
	os << "[";
	FOR(it, v) {
		if(it != v.begin()) { os << ", "; }
		os << *it;
	}
	os << "]";
	return os;
}
template<typename F, typename S> ostream & operator<<(ostream & os, const pair<F, S> & p) {
	os << "<" << p.FI << ", " << p.SE << ">";
	return os;
}

// ---- ----

const int MOD = 1000000007;
int n, a, b, c, d;
LL dp[2][1001];

LL ex_gcd(LL a, LL b, LL & x, LL & y) {
	LL d = a;
	if(b != 0) {
		d = ex_gcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else { x = 1, y = 0; }
	return d;
}

LL divmod(LL x, LL y) {
	LL inv, m;
	ex_gcd(y, MOD, inv, m);
	if(inv < 0) { inv += MOD; }
	return x * inv % MOD;
}

int main() {
	cin >> n >> a >> b >> c >> d;
	
	int to = 0, fr = 1;
	dp[to][0] = 1;
	incII(i, a, b) { LL e = 1; swap(to, fr); inc(k, n + 1) { dp[to][k] = dp[fr][k]; }
	incII(j, 1, d) {
		if(i * j > n) { break; }
		inc1(k, i) {
			(e *= i * (j - 1) + k) %= MOD;
			e = divmod(e, k);
		}
		e = divmod(e, j);
		
		LL f = e;
		if(c <= j) {
			int l = 1;
			decII(k, 0, n - i * j) {
				(dp[to][k + i * j] += dp[fr][k] * f) %= MOD;
				(f *= i * j + l) %= MOD;
				f = divmod(f, l);
				l++;
			}
		}
		// cout << i << ": "; inc(k, n + 1) { cout << dp[to][k] << " "; } cout << endl;
	}
	}
	
	cout << dp[to][n] << endl;
	
	return 0;
}
