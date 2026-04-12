#include <bits/stdc++.h>
using namespace std;
int n, md, ans[200005];
struct node
{
	int x, id;
}a[200005];
bool cmp(node u, node v) {return u.x < v.x;}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].x);
		a[i].id = i;
	}
	md = n / 2;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1, j = n; i < j; i++, j--) ans[a[i].id] = a[md + 1].x, ans[a[j].id] = a[md].x;
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}