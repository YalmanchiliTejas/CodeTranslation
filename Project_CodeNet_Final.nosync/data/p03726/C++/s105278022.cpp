#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
vector <int> a[MAXN];
int perfect(int pos, int fa) {
	int cnt = 0;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) cnt += perfect(a[pos][i], pos);
	if (cnt >= 2) return 2;
	else return cnt ^ 1;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if (perfect(1, 0)) printf("First\n");
	else printf("Second\n");
	return 0;
}