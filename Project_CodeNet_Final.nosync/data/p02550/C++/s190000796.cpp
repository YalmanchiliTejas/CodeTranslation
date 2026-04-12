#include <bits/stdc++.h>
using namespace std;

long long n;
int x, m;
int nxt[100005];
long long ans;

int main() {
	scanf("%lld", &n);
	scanf("%d%d", &x, &m);
	memset(nxt, -1, sizeof nxt);
	long long cur = x;
	while (n > 0) {
		ans += cur;
		n--;
		if (nxt[cur] != -1) {
			int temp = nxt[cur];
			long long cyclew = cur;
			int cycle = 1;
			while (temp != cur) {
				cycle++;
				cyclew += temp;
				temp = nxt[temp];
			}
			ans += cyclew * (n / cycle);
			n %= cycle;
			temp = nxt[cur];
			while (n > 0) {
				ans += temp;
				n--;
				temp = nxt[temp];
			}
			break;
		}
		nxt[cur] = (cur * cur) % m;
		cur = nxt[cur];
	}
	printf("%lld\n", ans);
	return 0;
}
