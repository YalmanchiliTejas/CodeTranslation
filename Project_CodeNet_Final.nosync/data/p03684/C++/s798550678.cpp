#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7, N = 1e5+5;
struct City{
    int x,y,id;
    int dist(const City &t){
        return min(abs(x-t.x),abs(y-t.y));
    }
};
bool comp_x(const City &a, const City &b){
    return a.x < b.x;
}
bool comp_y(const City &a, const City &b){
    return a.y < b.y;
}
struct Edge{
    int a,b,c;
    bool operator<(const Edge &t)const{
        return c < t.c;
    }
};
int par[N];
int getpar(int u){
    if(par[par[u]] == par[u])
        return par[u];
    return par[u] = getpar(par[u]);
}
bool unite(int a, int b){
    a = getpar(a);
    b = getpar(b);
    if(a == b)
        return false;
    par[a] = b;
    return true;
}
int main(){
    iota(par,par+N,0);
    int n;
    cin >> n;
    vector<City> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x >> arr[i].y;
        arr[i].id = i;
    }
    vector<Edge> edges;
    sort(arr.begin(),arr.end(),comp_x);
    for(int i = 0; i < n-1; ++i)
        edges.push_back({arr[i].id,arr[i+1].id,arr[i].dist(arr[i+1])});
    sort(arr.begin(),arr.end(),comp_y);
    for(int i = 0; i < n-1; ++i)
        edges.push_back({arr[i].id,arr[i+1].id,arr[i].dist(arr[i+1])});
    sort(edges.begin(),edges.end());
    int ans = 0;
    for(auto cur : edges)
        if(unite(cur.a,cur.b))
            ans += cur.c;
    cout << ans << '\n';
}
