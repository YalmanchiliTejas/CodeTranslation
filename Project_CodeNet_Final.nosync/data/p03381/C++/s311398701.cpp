#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[200005], b[200005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int l = b[n / 2], r = b[n / 2 + 1];
    for (int i = 1; i <= n; i++)
        if (a[i] <= l) printf("%d\n", r);
        else printf("%d\n", l);
	return 0;
}
