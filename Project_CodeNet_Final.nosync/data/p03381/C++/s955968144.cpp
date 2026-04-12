#include <bits/stdc++.h>
using namespace std;
int a[200010], b[200010], n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b+n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= b[n/2-1]) printf("%d\n", b[n/2]);
		else printf("%d\n", b[n/2-1]);
	}
}