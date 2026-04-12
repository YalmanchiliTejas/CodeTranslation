#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100010;
const int mod = 1e9 + 7;

char s[N];
int d, n, a[N];
int f[10010][110];

int dfs(int cnt, int limit, int lead, int s) {
	if(!cnt) return !s && !lead;
	if(~f[cnt][s] && !limit && !lead) return f[cnt][s];
	int sum = 0, ed = limit ? a[cnt] : 9;
	for(int i = 0; i <= ed; ++i) {
		(sum += dfs(cnt - 1, limit && (i == ed), lead && (!i), (s + i) % d)) %= mod;
	}
	if(!limit && !lead) return f[cnt][s] = sum;
	return sum;
}

int main() {
	memset(f, -1, sizeof(f));
	scanf("%s%d", s + 1, &d);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) a[i] = s[i] - '0';
	reverse(a + 1, a + n + 1);
	printf("%lld\n", dfs(n, 1, 1, 0));
}