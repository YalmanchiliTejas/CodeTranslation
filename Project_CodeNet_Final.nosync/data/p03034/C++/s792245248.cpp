#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define N 112345
ll s[N];

int main(){
	int n; scanf("%d", &n);
	REP(i, n) scanf("%lld", s+i);
	int m = n-1;
	ll ans = 0;
	FOR(i, 1, N){
		int p = i;
		int q = m-i;
		ll tmp = 0;
		while(1){
			if(m%i==0 && q<=p) break;
			if(m%i!=0 && q<i) break;
			tmp += s[p]+s[q];
			LAR(ans, tmp);
			p += i;
			q -= i;
		}
	}
	printf("%lld\n", ans);
}
