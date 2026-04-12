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

const int MAXN = 55;
ll a[MAXN];
ll r[MAXN];

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld", &a[i]);
	ll ans = 0;
	ll sum = 0;
	while(1) {
		for(int i = 0; i < N; i++) {
			sum -= r[i];
			a[i] += sum;
			r[i] = (a[i] - N) / N + 1;
			if(a[i] < N) r[i] = 0;
			a[i] -= N * r[i];
			ans += r[i];
			sum += r[i];
			debug("a[%d], r: %lld, %lld (%lld)\n", i, a[i], r[i], sum);
		}
		if(sum > 0) continue;
		bool fin = true;
		for(int i = 0; i < N; i++)
			if(a[i] >= N)
				fin = false;
		if(fin) break;
	}
	cout << ans << endl;
	return 0;
}
