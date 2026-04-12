#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
void chkax (int &x, int y) { x = max (x, y); }
void chkin (int &x, int y) { x = min (x, y); }
int n;
int a[200005], b[200005], id[200005];
int ama, ami = inf, bma, bmi = inf;
int dma, dmi = inf;
int cmp (int x, int y) {
	return a[x] < a[y];
}
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d %d", &a[i], &b[i]);
        if (a[i] > b[i]) swap(a[i], b[i]);
        id[i] = i;
        chkax (ama, a[i]), chkin (ami, a[i]);
        chkax (bma, b[i]), chkin (bmi, b[i]);
    }
    long long ret = (long long)(ama - ami) * (bma - bmi);
    sort (id+1, id+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        chkax (dma, b[id[i]]), chkin (dmi, b[id[i]]);
        ret = min (ret, (long long)(max(dma, a[id[n]]) - min(dmi, a[id[i+1]])) * (bma - ami));
    }
    printf ("%lld\n", ret);
    return 0;
}