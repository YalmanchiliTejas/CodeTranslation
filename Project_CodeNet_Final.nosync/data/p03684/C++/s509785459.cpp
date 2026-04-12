#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

int n;
const int maxn = 2e5 + 5;

int x[maxn], y[maxn];

pair<int, pair<int, int> > p[maxn];
int tot;
typedef pair<int, int> pii;

pii z[maxn];
int fa[maxn];
int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i = 1;i <= n;i++){
        z[i] = make_pair(x[i], i);
    }
    tot = 0;
    sort(z + 1, z + 1 + n);
    for(int i = 1;i < n;i++){
        int u = z[i].second;
        int v = z[i + 1].second;
        p[++tot] = make_pair(z[i + 1].first - z[i].first, make_pair(u, v));
    }
    for(int i = 1;i <= n;i++){
        z[i] = make_pair(y[i], i);
    }
    sort(z + 1, z + 1 + n);
    for(int i = 1;i < n;i++){
        int u = z[i].second;
        int v = z[i + 1].second;
        p[++tot] = make_pair(z[i + 1].first - z[i].first, make_pair(u, v));
    }
    sort(p + 1, p + 1 + tot);
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    long long ans = 0;
    for(int i = 1;i <= tot;i++){
        int u = p[i].second.first;
        int v = p[i].second.second;
        int fx = Find(u);
        int fy = Find(v);
        if(fx != fy){
            fa[fx] = fy;
            ans += p[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
