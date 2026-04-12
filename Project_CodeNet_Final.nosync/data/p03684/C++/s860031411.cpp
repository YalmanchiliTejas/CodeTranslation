#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x[100000];
int y[100000];

int par[100000];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main() {
    int n, i;
    long long ans = 0;
    vector <pair<int, int> > v, w;
    vector <pair<int, pair<int, int> > > z;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
    
    for (i = 0; i < n; i++) {
        v.push_back(make_pair(x[i], i));
        w.push_back(make_pair(y[i], i));
    }
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    for (i = 0; i + 1 < n; i++) {
        z.push_back(make_pair(v[i + 1].first - v[i].first, make_pair(v[i].second, v[i + 1].second)));
        z.push_back(make_pair(w[i + 1].first - w[i].first, make_pair(w[i].second, w[i + 1].second)));
    }
    
    sort(z.begin(), z.end());
    
    for (i = 0; i < n; i++) par[i] = i;
    
    for (i = 0; i < z.size(); i++) {
        int x = z[i].second.first;
        int y = z[i].second.second;
        
        if (find(x) == find(y)) continue;
        
        unite(x, y);
        ans += z[i].first;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
