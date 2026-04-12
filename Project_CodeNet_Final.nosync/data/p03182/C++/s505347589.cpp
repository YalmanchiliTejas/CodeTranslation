#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200001
ll t1[N << 2], t2[N << 2];
vector<pair<int, int> > a[N];
void up(int x, int L, int R, int l, int r, ll c) {
    if (l <= L && R <= r) return (void)(t1[x] += c, t2[x] += c);
    int mid = (L + R) >> 1;
    if (l <= mid) up(x << 1, L, mid, l, r, c);
    if (r > mid) up(x << 1 | 1, mid + 1, R, l, r, c);
    t1[x] = max(t1[x << 1], t1[x << 1 | 1]) + t2[x];
}
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        a[y].push_back(make_pair(x, z));
    }
    for (int i = 1; i <= n; i++) {
        up(1, 1, n, i, i, t1[1]);
        for (auto &it : a[i]) up(1, 1, n, it.first, i, it.second);
    }
    printf("%lld\n", max(t1[1], 0ll));
    return 0;
}