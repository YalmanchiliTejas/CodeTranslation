#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 3005;

LL res[N][N], sum[N][N];
int i, j, tab[N], n;

LL get(int a, int b) {
	if (res[a][b] != -1) return res[a][b];
	if (a == b) {
		res[a][b] = tab[a];
		return res[a][b];
	}
	res[a][b] = sum[a][b] - min(get(a + 1, b), get(a, b - 1));
	return res[a][b];
}

int main() {
scanf("%d", &n);
for (i=0;i<n;i++) scanf("%d", &tab[i]);
for (i=0;i<n;i++) for (j=i;j<n;j++) res[i][j] = -1;
for (i=0;i<n;i++) {
	sum[i][i] = tab[i];
	for (j = i + 1; j < n;j++) sum[i][j] = sum[i][j - 1] + tab[j];
}
printf("%lld\n", -sum[0][n - 1] + 2 * get(0, n - 1));
return 0;
}