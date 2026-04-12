#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <time.h>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) (min(a,b) <= (x) && (x) <= max(a,b)) //hei
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[4] = {
	{ -1 ,0 },{ 0 , 1 },{ 1 ,0 },{ 0 ,-1 }
};

//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define chmax(a,b) a = max(a,b)
#define chmin(a,b) a = min(a,b)

struct Edge {
	int from, to;
	ll w;
	bool operator<(const Edge& rhs) const {
		return MP(w, MP(from, to)) < MP(rhs.w, MP(rhs.from, rhs.to));
	}

};
typedef vector<vector<Edge>> Graph;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll facmemo[200000] = {};

ll factorial(ll n) {//階乗
	if (facmemo[n] != 0) return facmemo[n];
	if (n == 0) return 1;
	ll ret = n * factorial(n - 1);
	ret %= MODU;
	return facmemo[n] = ret;
}

ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x %mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}
ll divmod(ll a, ll b, ll m) { // a/b(mod m)
								  // a/b (mod m)
								  // a*b^-1
								  // b^-1 * b = 1
								  // b^(m-1) = 1 
								  // b^(m-2) * b = 1
								  // b^-1 = b^(m-2)

								  // a/b = a * b^(m-2)

	return (a * 1LL * mod_pow(b, m - 2, m)) % m;
}
ll ncr(ll n, ll r) {
	if (r == 0) return 1;
	if (n < r) return 1;
	return divmod(factorial(n), (factorial(r) * (factorial(n - r))) % MODU, MODU);
}

bool sankaku(int a, int b, int c) {
	return a <= b + c && b <= a + c && c <= b + a;
}
ll lcm(ll m, ll n)
{
	return m * n / gcd(m, n);
}

signed main() {
	int n, m;
	cin >> n >> m;
	if (n == m) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
