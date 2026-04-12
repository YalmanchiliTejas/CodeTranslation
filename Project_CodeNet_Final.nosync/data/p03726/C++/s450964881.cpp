#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

const int MN = 100010;
int n;
vector<int> g[MN];

int match(int v, int p) {
    int umt = 0;
    foreach(u, g[v]) {
        if (*u == p) continue;
        umt += match(*u, v);
    }
    if (umt >= 2) return umt;
    return 1-umt;
}

int main() {
    scanf("%d", &n);
    rep(i, 0, n-1) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (match(0, -1)) puts("First");
    else puts("Second");
    return 0;
}