#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int L, k, d;
int main() {
	scanf("%d%d%d", &L, &k, &d);
	int ans = (L - d) / (k + d);
	printf("%d\n", ans);
	return 0;
}