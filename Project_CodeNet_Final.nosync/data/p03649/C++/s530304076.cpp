#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long w[51], sum;
bool Pos(long long T) {
	int i, ss = 0;
	for (i = 1; i <= n; i++) {
		int t = (w[i] + T) % (n + 1);
		if (t == n)return false;
		ss += t;
	}
	if (ss == sum - T)return true;
	return false;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		sum += w[i];
	}
	for (long long T = max(0ll, sum - n*n); T <= sum; T++) {
		if (Pos(T)) {
			printf("%lld\n", T);
			return 0;
		}
	}
}