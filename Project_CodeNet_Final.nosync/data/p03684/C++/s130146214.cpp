#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

struct edge{int from, to, cost;};

const int MAX_N = 1e5;
int N, p[MAX_N], r[MAX_N];
P xx[MAX_N], yy[MAX_N];
edge e[2*MAX_N];

bool cmp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

void init(int n){
    for(int i=0;i<n;i++){
        p[i] = i;
        r[i] = 0;
    }
}

int find(int x){
    if(p[x]==x) return x;
    return p[x] = find(p[x]);
}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return;

    if(r[x] < r[y]) p[x] = y;
    else{
        p[y] = x;
        if(r[x]==r[y]) r[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int kruskal(){
    sort(e, e+2*N, cmp); init(N);
    
    int res = 0;
    for(int i=0;i<2*N;i++){
        edge ee = e[i];
        if(!same(ee.from, ee.to)){
            unite(ee.from, ee.to);
            res += ee.cost;
        }
    }
    return res;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int x, y; cin >> x >> y;
        xx[i].first = x; xx[i].second = i;
        yy[i].first = y; yy[i].second = i;
    }

    sort(xx, xx+N); sort(yy, yy+N);

    for(int i=0;i<N-1;i++){
        e[2*i].from = xx[i].second; e[2*i].to = xx[i+1].second; e[2*i].cost = xx[i+1].first - xx[i].first;
        e[2*i+1].from = yy[i].second; e[2*i+1].to = yy[i+1].second; e[2*i+1].cost = yy[i+1].first - yy[i].first;
    }

    cout << kruskal() << endl;
    return 0;
}