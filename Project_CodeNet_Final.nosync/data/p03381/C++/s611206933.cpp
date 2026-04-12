#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int Maxn = 200010;
struct lnode {
	int x, id;
	bool operator<(const lnode &A) const { return x < A.x; }
}list[Maxn];
int n;
int ans[Maxn];
int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", &list[i].x), list[i].id = i;
	sort(list+1, list+n+1);
	for(i = 1; i <= n/2; i++) ans[list[i].id] = list[n/2+1].x;
	for(i = n/2+1; i <= n; i++) ans[list[i].id] = list[n/2].x;
	for(i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}