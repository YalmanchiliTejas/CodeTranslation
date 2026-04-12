#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAXN = 1000050;
int N, X[MAXN], Y[MAXN], o[MAXN], p[MAXN];
vector<pair<int, pi>> edges;
long long ans;
bool cmpx(int a, int b) {
    return X[a] < X[b];
}
bool cmpy(int a, int b) {
    return Y[a] < Y[b];
}
int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &X[i], &Y[i]);
        p[i] = i;
        o[i] = i;
    }
    sort(o, o+N, cmpx);
    for (int i = 1; i < N; ++i) {
        edges.emplace_back(X[o[i]] - X[o[i-1]], pi(o[i], o[i-1]));
    }
    sort(o, o+N, cmpy);
    for (int i = 1; i < N; ++i) {
        edges.emplace_back(Y[o[i]] - Y[o[i-1]], pi(o[i], o[i-1]));
    }
    
    sort(edges.begin(), edges.end());
    for (auto e:edges) {
        int a = e.second.first, b = e.second.second;
        if (par(a) == par(b)) continue;
        ans += e.first;
        p[par(a)] = par(b);
    }
    printf("%lld\n", ans);
}