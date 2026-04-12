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

constexpr ll MOD = 1'000'000'007LL;

int main(){
	int n; scanf("%d", &n);
	ll sm = 0, sn = 0;
	REP(i, n){
		ll a; scanf("%lld", &a);
		sm += a;
		sn += a*a % MOD;
	}
	sm %= MOD;
	sn %= MOD;
	ll ans = (sm*sm % MOD - sn + MOD) % MOD;
	if(ans%2) ans += MOD;
	ans = ans / 2 % MOD;
	printf("%lld\n", ans);
}
