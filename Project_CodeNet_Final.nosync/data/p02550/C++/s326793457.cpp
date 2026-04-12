#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxm = 1e5 + 5;

ll n;
int x, m, s, ans, tot;
int nxt[maxm];
ll sum[maxm];

int main(){
	scanf("%lld%d%d", &n, &x, &m);
	memset(nxt, -1, sizeof(nxt));
	for(s = x; !~nxt[s]; s = 1ll * s * s % m)
		nxt[s] = 1ll * s * s % m;
	for(int t = x; t != s && n; --n, t = nxt[t])
		ans += t;
	if(!n){
		printf("%lld\n", ans);
		return 0;
	}
	sum[1] = s; tot = 1;
	for(int t = nxt[s]; t != s; t = nxt[t]){
		++tot;
		sum[tot] = sum[tot - 1] + t;
	}
	printf("%lld\n", ans + 1ll * sum[tot] * (n / tot) + sum[n % tot]);
	return 0;
}
