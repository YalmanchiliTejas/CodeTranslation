///usr/bin/g++ -O2 $0 -o ${0%.cpp} && echo "----------" && ./${0%.cpp}; exit;
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int N = 1e5 + 10; 

struct point {
    int x, y, id; 
} p[N]; 
int n, par[N];

int find(int u) { return u == par[u] ? u : par[u] = find(par[u]); }

int main(int argc, char const *argv[]) {
    scanf("%d", &n); 
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &p[i].x, &p[i].y); 
        p[i].id = i;
    }  

    vector<pair<int, ii> > edges; 
    sort(p + 1, p + n + 1, [](point a, point b) { return a.x < b.x; });
    for(int i = 2; i <= n; ++i) 
        edges.push_back({p[i].x - p[i - 1].x, {p[i].id, p[i - 1].id}}); 
    sort(p + 1, p + n + 1, [](point a, point b) { return a.y < b.y; });
    for(int i = 2; i <= n; ++i) 
        edges.push_back({p[i].y - p[i - 1].y, {p[i].id, p[i - 1].id}}); 

    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; ++i) par[i] = i; 

    ll ans = 0; 
    for(auto e : edges) {
        int u = e.second.first, v = e.second.second; 
        u = find(u); v = find(v); 
        if(u != v) {
            par[u] = v; 
            ans += e.first; 
        }
    }
    printf("%lld\n", ans); 
}