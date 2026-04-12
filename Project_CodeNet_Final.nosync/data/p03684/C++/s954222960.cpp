#include "bits/stdc++.h"
using namespace std;
const int maxn = 100100;
struct edge{
    int u, v, w;
    edge(){}
    edge(int a, int b, int c): u(a), v(b), w(c){}
};
int dad[maxn];
int find(int x){
    return (x == dad[x])?x:dad[x] = find(dad[x]);
}
int main(){
    for(int e = 0; e < maxn; e++) dad[e] = e;
    vector<edge> values;
    int n;
    scanf("%d", &n);
    vector<edge> solve;
    for(int e = 0; e < n; e++){
        int a, b;
        scanf("%d %d", &a, &b);
        // printf("%d %d\n", a, b);
        solve.push_back(edge(a, b, e));
    }
    sort(solve.begin(), solve.end(), [](edge a, edge b){
        return a.u < b.u;
    });
    for(int e = 0; e < n; e++){
        // printf("%d %d %d\n", solve[e].w, solve[e].u, solve[e].v);
        if(e)
        values.push_back(edge(solve[e].w, solve[e-1].w,
            min(abs(solve[e].u - solve[e-1].u), abs(solve[e].v - solve[e-1].v))));
        if(e + 1 < n)
        values.push_back(edge(solve[e].w, solve[e+1].w,
            min(abs(solve[e].u - solve[e+1].u), abs(solve[e].v - solve[e+1].v))));
    }
    sort(solve.begin(), solve.end(), [](edge a, edge b){
        return a.v < b.v;
    });
    for(int e = 0; e < n; e++){
        // printf("%d\n", solve[e].w);
        if(e)
        values.push_back(edge(solve[e].w, solve[e-1].w,
            min(abs(solve[e].u - solve[e-1].u), abs(solve[e].v - solve[e-1].v))));
        if(e + 1 < n)
        values.push_back(edge(solve[e].w, solve[e+1].w,
            min(abs(solve[e].u - solve[e+1].u), abs(solve[e].v - solve[e+1].v))));
    }
    sort(values.begin(), values.end(), [](edge a, edge b){
        return a.w < b.w;
    });
    long long cost = 0;
    for(int e = 0; e < values.size(); e++){
        edge a = values[e];
        if(find(a.u) != find(a.v)){
            // printf("%d %d %d\n", a.u, a.v, a.w);
            dad[find(a.u)] = find(a.v);
            cost += a.w;
        }

    }
    printf("%lld\n", cost);
    return 0;
}
