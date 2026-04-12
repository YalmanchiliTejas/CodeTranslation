#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<ll,P>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define REP(i,b,e) for(ll i=b; i<e; i++)
#define ALL(vec) vec.begin(),vec.end()
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n;
	scanf("%d", &n);
	V a(n);
	SCAN(a);
	std::sort(ALL(a));
	if(n%2==0){
		ll ans = 0;
		REP(i, 0, n/2) ans -= a[i];
		REP(i, n/2, n) ans += a[i];
		ans *= 2;
		ans -= a[n/2];
		ans += a[n/2-1];
		printf("%ld\n", ans);
	}else{
		ll ans1 = 0, ans2 = 0;
		REP(i, 0, n/2) ans1 -= a[i];
		REP(i, n/2, n) ans1 += a[i];
		ans1 *= 2;
		ans1 -= a[n/2];
		ans1 -= a[n/2+1];

		REP(i, 0, n/2+1) ans2 -= a[i];
		REP(i, n/2+1, n) ans2 += a[i];
		ans2 *= 2;
		ans2 += a[n/2];
		ans2 += a[n/2-1];
		printf("%ld\n", std::max(ans1, ans2));

	}
	return 0;
}

