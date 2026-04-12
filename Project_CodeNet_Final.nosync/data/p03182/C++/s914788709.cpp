#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200001
ll s[N << 2], t[N << 2];
vector<pair<int, int> > a[N];
void add(int x, int L, int R, int l, int r, ll c) {
    if (l <= L && R <= r) return (void)(s[x] += c, t[x] += c);
    int mid = (L + R) >> 1;
    if (l <= mid) add(x << 1, L, mid, l, r, c);
    if (r > mid) add(x << 1 | 1, mid + 1, R, l, r, c);
    s[x] = max(s[x << 1], s[x << 1 | 1]) + t[x];
}
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        a[y].emplace_back(x, z);
    }
    for (int i = 1; i <= n; i++) {
        add(1, 1, n, i, i, s[1]);
        for (auto &it : a[i]) add(1, 1, n, it.first, i, it.second);
    }
    printf("%lld\n", max(s[1], 0ll));
    return 0;
}