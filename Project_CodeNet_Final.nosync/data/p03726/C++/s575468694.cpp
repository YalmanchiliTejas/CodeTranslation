#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int MAXN = 100000;
set<int> g[MAXN + 1];
int deg[MAXN + 1], del[MAXN + 1];

struct point {
    int v;
};

bool operator<(const point& first, const point& second) {
    if(deg[first.v] != deg[second.v])
        return deg[first.v] < deg[second.v];
    else
        return first.v < second.v;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    if(n & 1) {
        cout << "First\n";
        return 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].insert(b);
        g[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(auto x: g[i]) {
            if(deg[x] == 1)
                cnt++;
        }
        if(cnt >= 2) {
            cout << "First\n";
            return 0;
        }
    }
    set<point> s;
    for(int i = 1; i <= n; i++) {
        s.insert({ i });
    }
    while(!s.empty()) {
        auto it = s.begin();
        if(deg[it->v] > 1)
            break;
        int temp = it->v;
        int v = *g[it->v].begin();
        s.erase({ v });
        for(auto u: g[v]) {
            s.erase({ u });
            deg[u]--;
            if(deg[u] == 0)
                deg[u] = MAXN + 1;
            if(u != temp)
                s.insert({ u });
            g[u].erase(v);
        }
    }
    for(auto it: s) {
        int i = it.v;
        if(deg[i] == MAXN + 1) {
            cout << "First\n";
            return 0;
        }
    }
    cout << "Second\n";
    return 0;
}