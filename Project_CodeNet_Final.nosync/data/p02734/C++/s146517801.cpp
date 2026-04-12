#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 3005;
const int MOD = 998244353;

int n, s, i, j, k, r[N], tab[N], res;

void loop() {
	
}

int main() {
scanf("%d %d", &n, &s);
for (i=1;i<=n;i++) scanf("%d", &tab[i]);
r[tab[1]] = 1;
if (tab[1] == s) res = n; else res = 0;
for (i=2;i<=n;i++) {
	if (tab[i] > s) continue;
	res = ((n - i + 1) * 1LL * r[s - tab[i]] + res) % MOD;
	if (tab[i] == s) res = ((n - i + 1) * 1LL * i + res) % MOD;
	for	(k=s - tab[i];k>=0;k--) r[k + tab[i]] = (r[k + tab[i]] + r[k]) % MOD;
	r[tab[i]] = (r[tab[i]] + i) % MOD;	
	//printf("%d %d\n", i, res);
}
printf("%d\n", res);
return 0;
}