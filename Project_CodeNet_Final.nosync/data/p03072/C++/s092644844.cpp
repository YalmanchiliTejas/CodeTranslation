#include <bits/stdc++.h>
using namespace std;

const int Maxn = 22;

int n;
int h[Maxn], a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        a[i] = max(a[i - 1], h[i]);
        if (a[i] <= h[i]) res++;
    }
    printf("%d\n", res);
    return 0;
}
