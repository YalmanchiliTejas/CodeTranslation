#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int L = 30;

int a[L], n;

int f[L];

int main()
{
	scanf("%d", &n);
	for (int s = 0; s < n; s++) scanf("%d", &a[s]);
	int ans = 1, m = a[0];
	for (int s = 1; s < n; s++)
		if (a[s] >= m)
		{
			m = a[s];
			ans++;
		}
	printf("%d", ans);
}
