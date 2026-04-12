#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000
int c[N];
int n, x, y;

int find(int z) {
	int l = -1;
	int r = N;
	int m;
	while ((l + 1) < r) {
		m = (l + r) / 2;
		if (c[m] >= z)l = m;
		else r = m;
	}
	return r;
}


int main() {
	f(i, N)c[i] = -1;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		y = find(x);
		c[y] = x;
	}
	x = 0;
	f(i, N) if (c[i] >= 0)x++;
	printf("%d\n", x);

	return 0;
}