//C
#include<bits/stdc++.h>
#define se second
#define fi first
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const double PI = 2 * acos(0);

int main() {
	int N;
	scanf("%d", &N);
	LL bef = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		ans += (bef * x) % MOD;
		ans %= MOD;
		bef += x;
		bef %= MOD;
	}
	printf("%lld\n", ans);
}