/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>
 
// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std
 
Jehian Norman Saviero;
 
// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
 
// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")
 
// MACROS FOR ATTRIBUTE
#define fi first
#define se second
 
// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))
 
// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

const ll MD = 1e9+7;

inline ll MUL(ll a, ll b) {
	return (a * b) % MD;
}

inline ll ADD(ll a, ll b) {
	return (a + b) % MD;
}

inline ll SUB(ll a, ll b) {
	return ((a - b) % MD + MD) % MD;
}

inline ll powMod(ll a, ll p) {
	ll res = 1;
	for (; p; p >>= 1, a = MUL(a,a)) {
		if (p & 1) res = MUL(res,a);
	}
	return res;
}

inline ll DIV(ll a, ll b) {
	return MUL(a, powMod(b, MD-2));	
}

int main() {
	int N;
	sci(N);
	ll dat[N];
	ll sum = 0;
	ll sumSqr = 0;
	for (int i = 0; i < N; ++i) {
		scll(dat[i]);
		sum = ADD(sum, dat[i]);
		sumSqr = ADD(sumSqr, MUL(dat[i],dat[i]));
	}
	ll ans = DIV(SUB(MUL(sum, sum), sumSqr),2LL);
	printf("%lld\n", ans);
	return 0;
}