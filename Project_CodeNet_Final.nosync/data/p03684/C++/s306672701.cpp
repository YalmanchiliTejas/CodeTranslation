#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int maxn = 4e5 + 100;
int s[maxn], vis[maxn], fa[maxn];
int cnt = 0;
struct node {
    int from, to, cost, pos;
} e[maxn], ss[maxn];

bool cmp1(node a, node b) {
    return a.from < b.from;
}

bool cmp2(node a, node b) {
    return a.to < b.to;
}

bool cmp3(node a, node b) {
    return a.cost < b.cost;
}

int findd(int x) {
    return x == fa[x] ? x : fa[x] = findd(fa[x]);
}

int uni(int x, int y) {
    int p1 = findd(x), p2 = findd(y);
    if (p1 == p2) return 1;
    fa[p2] = p1;
    return 0;
}

void init() {
    for (int i = 0; i < maxn; i++) {
        fa[i] = i;
    }
}

int main() {
    int n;
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        cin >> ss[i].from >> ss[i].to;
        ss[i].pos = i;
    }

    sort(ss, ss + n, cmp1);
    for (int i = 1; i < n; i++) {
        e[cnt].from = ss[i].pos;
        e[cnt].to = ss[i - 1].pos;
        e[cnt++].cost = abs(ss[i].from - ss[i - 1].from);
    }
    sort(ss, ss + n, cmp2);
    for (int i = 1; i < n ; i++) {
        e[cnt].from = ss[i].pos;
        e[cnt].to = ss[i - 1].pos;
        e[cnt++].cost = abs(ss[i].to - ss[i - 1].to);
    }
    sort(e, e + cnt, cmp3);
    long long ans = 0;
    for (int i = 0; i < cnt; i++) {
        if (!uni(e[i].from, e[i].to)) {
            ans += e[i].cost;
        }
    }
    cout << ans << endl;
    return 0;
}