#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAXN = 100010;
int x[MAXN], y[MAXN];
pair<int, int> xsorted[MAXN];
pair<int, int> ysorted[MAXN];
int par[MAXN];
int rnk[MAXN];
void makeset(int x){
    par[x] = x;
    rnk[x] = 1;
}
int get(int x){
    if(par[x] == x) return x;
    return (par[x] = get(par[x]));
}
void unite(int x, int y){
    int xr = get(x);
    int yr = get(y);
    if(xr == yr) return;
    if(rnk[xr] > rnk[yr]){
        par[yr] = xr;
        rnk[xr] += rnk[yr];
    } else {
        par[xr] = yr;
        rnk[yr] += rnk[xr];
    }
}
struct edge{
    int val, u, v;
    edge(){

    }
    edge(int _val, int _u, int _v){
        val = _val;
        u = _u;
        v = _v;
    }
    bool operator <(const edge &a) const{
        return val < a.val;
    }
};
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i]  >> y[i];
        xsorted[i] = {x[i], i};
        ysorted[i] = {y[i], i};
    }
    sort(xsorted + 1, xsorted + n + 1);
    sort(ysorted + 1, ysorted + n + 1);
    vector<edge> edges;
    for(int i = 1; i <= n - 1; i++){
        edge e;
        e.val = xsorted[i + 1].first - xsorted[i].first;
        e.u = xsorted[i + 1].second;
        e.v = xsorted[i].second;
        edges.push_back(e);
        e.val = ysorted[i + 1].first - ysorted[i].first;
        e.u = ysorted[i + 1].second;
        e.v = ysorted[i].second;
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; i++) makeset(i);
    long long ans = 0;
    for(auto ed : edges){
        int ur = get(ed.u);
        int vr = get(ed.v);
        if(ur == vr) continue;
        ans += ed.val;
        unite(ur, vr);
    }
    cout << ans << endl;
    return 0;
}
