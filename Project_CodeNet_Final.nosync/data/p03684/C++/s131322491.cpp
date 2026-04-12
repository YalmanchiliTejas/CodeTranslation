// Copyright 2017 wu_qing
#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 2e5 + 10;
struct node {
    int x, y, id;
} a[N];
struct edge {
    int x, y, d;
    explicit edge(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) {
    }
};
std::vector<edge> e;
bool cmpx(node a, node b) {
    return a.x < b.x;
}
bool cmpy(node a, node b) {
    return a.y < b.y;
}
bool cmpe(edge a, edge b) {
    return a.d < b.d;
}
int n, cnt, ans, f[N];
inline int getf(int x) {
    return f[x] == x ? x : (f[x] = getf(f[x]));
}
inline void merge(int x, int y) {
    f[getf(x)] = getf(y);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    std::sort(a + 1, a + n + 1, cmpx);
    for (int i = 1; i < n; i++)
        e.push_back(edge(a[i].id, a[i + 1].id, a[i + 1].x - a[i].x));
    std::sort(a + 1, a + n + 1, cmpy);
    for (int i = 1; i < n; i++)
        e.push_back(edge(a[i].id, a[i + 1].id, a[i + 1].y - a[i].y));
    std::sort(e.begin(), e.end(), cmpe);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (edge i : e) {
        if (cnt == n - 1)
            break;
        if (getf(i.x) != getf(i.y)) {
            merge(i.x, i.y);
            ans += i.d;
            cnt++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
