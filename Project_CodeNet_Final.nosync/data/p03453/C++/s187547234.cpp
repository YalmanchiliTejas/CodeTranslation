#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010, P = 1000000007;
int n, m, S, T;
ll d1[maxn], d2[maxn], f1[maxn], f2[maxn];
vector<pair<int, int>> G[maxn];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

int main() {
    scanf("%d %d %d %d", &n, &m, &S, &T);
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(d1, 0x3f, sizeof(d1));
    q.push(make_pair(d1[S] = 0, S)), f1[S] = 1;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        int v = p.second;
        if (p.first ^ d1[v]) continue;
        for (auto e : G[v]) {
            if (d1[e.first] > d1[v] + e.second) {
                d1[e.first] = d1[v] + e.second, f1[e.first] = f1[v];
                q.push(make_pair(d1[e.first], e.first));
            } else if (d1[e.first] == d1[v] + e.second) {
                (f1[e.first] += f1[v]) %= P;
            }
        }
    }
    memset(d2, 0x3f, sizeof(d2));
    q.push(make_pair(d2[T] = 0, T)), f2[T] = 1;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        int v = p.second;
        if (p.first ^ d2[v]) continue;
        for (auto e : G[v]) {
            if (d2[e.first] > d2[v] + e.second) {
                d2[e.first] = d2[v] + e.second, f2[e.first] = f2[v];
                q.push(make_pair(d2[e.first], e.first));
            } else if (d2[e.first] == d2[v] + e.second) {
                (f2[e.first] += f2[v]) %= P;
            }
        }
    }
    int ans = 1LL * f1[T] * f1[T] % P;
    for (int i = 1; i <= n; i++) {
        if (d1[i] == d1[T] / 2 && d1[i] == d2[i]) {
            int t = 1LL * f1[i] * f2[i] % P;
            ans = (ans - 1LL * t * t % P + P) % P;
        }
        for (auto e : G[i]) {
            if (d1[i] < d1[T] / 2 && d2[e.first] < d1[T] / 2 && d1[i]
                + d2[e.first] + e.second == d1[T]) {
                int t = 1LL * f1[i] * f2[e.first] % P;
                ans = (ans - 1LL * t * t % P + P) % P;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}