#include <bits/stdc++.h>
using namespace std;

const int maxn=int(2e5)+100;

int n;
int a[maxn], b[maxn];

void read()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
		b[i]=a[i];
	}
}
void solve()
{
	sort(b+1, b+1+n);
	int L=b[n/2], R=b[n/2+1];

	for (int i=1; i<=n; ++i)
		if (a[i]<=L) printf("%d\n", R);
		else printf("%d\n", L);
}
int main()
{
	read();
	solve();
	return 0;
}