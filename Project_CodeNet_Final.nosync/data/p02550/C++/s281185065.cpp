#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
template<typename T>
using pque = priority_queue<T, vector<T>, greater<T>>;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 112345
vector<ll> v;
bool u[N] = {};

int main(){
	ll n, x, m; scanf("%lld%lld%lld", &n, &x, &m);
	v.EB(x); u[x] = true;
	for(;;){
		x = x*x % m;
		if(u[x]) break;
		v.EB(x);
		u[x] = true;
	}
	ll p = 0;
	while(v[p] != x) p++;
	ll q = v.size() - p;
	printf("%lld\n", 
			accumulate(v.begin(), v.begin() + min(p, n), 0)
			+
			max(n-p, 0LL) / q * accumulate(v.begin() + min(p, n), v.end(), 0LL)
			+
			accumulate(v.begin() + p, v.begin() + p + max(n-p, 0LL) % q, 0LL)
			);
}
