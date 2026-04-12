#include <bits/stdc++.h>
using namespace std;

int n, x[200005], id[200005], B[200005];

bool cmp(int a, int b) {
    return x[a] < x[b];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    int mid = n / 2;
    for (int i = 1; i <= mid; i++) B[id[i]] = x[id[mid + 1]];
    for (int i = mid + 1; i <= n; i++) B[id[i]] = x[id[mid]];
    for (int i = 1; i <= n; i++) printf("%d\n", B[i]);
    return 0;
}
