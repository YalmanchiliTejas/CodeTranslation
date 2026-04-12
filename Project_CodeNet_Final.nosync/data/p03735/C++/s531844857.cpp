#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int INF = 1e9 + 100;

int main() {
	int N;
	scanf("%d", &N);
	priority_queue<PII> pq;
	int Xs = INF, Xm = 0;
	int Ys = INF, Ym = 0;
	for(int i = 0; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		pq.push(MP(y, x));
		Xs = min(Xs, x);
		Ys = min(Ys, y);
		Xm = max(Xm, x);
		Ym = max(Ym, y);
	}
	ll ans = 1ll * (Xm - Xs) * (Ym - Ys);
	while(!pq.empty()) {
		PII u = pq.top(); pq.pop();
		if(u.S >= u.F) break;
		Xm = max(Xm, u.F);
		Ys = min(Ys, u.S);
		swap(u.F, u.S);
		pq.push(u);
		debug("%lld %lld -- %lld %lld\n", Xm, Xs, pq.top().F, Ys);
		ans = min(ans, 1ll * (Xm - Xs) * (pq.top().F - Ys));
	}
	cout << ans << endl;
	return 0;
}
