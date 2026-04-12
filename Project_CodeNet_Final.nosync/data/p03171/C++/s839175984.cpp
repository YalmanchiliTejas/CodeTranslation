#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAXN = 3010;
const ll INF  = 10e17+1;

int n, a[MAXN];
ll f[MAXN][MAXN];

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	for(int l = 0; l < n; l++){
		for(int i = 1, j = i + l; j <= n; i++, j++){
			if((n - l) & 1) f[i][j] = max(f[i+1][j] + a[i], f[i][j-1] + a[j]);
			else f[i][j] = min(f[i+1][j] - a[i], f[i][j-1] - a[j]);
		}
	}
	printf("%lld\n",f[1][n]);
	return 0;
}