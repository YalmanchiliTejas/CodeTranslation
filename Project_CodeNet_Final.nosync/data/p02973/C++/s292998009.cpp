#include <cstdio>
#include <climits>
#include <algorithm>
int n;
int a[100005];
int d[100005];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		d[i] = INT_MIN;
	}
	d[1] = a[1];
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] <= d[ans])
			d[++ans] = a[i];
		else {
			int l = 1, r = ans, mid;
			while (l <= r) {
				mid = (l + r) / 2;
				if (d[mid] >= a[i])
					l = mid + 1;
				else
					r = mid - 1;
			}
			int pos = l;
			d[pos] = a[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}