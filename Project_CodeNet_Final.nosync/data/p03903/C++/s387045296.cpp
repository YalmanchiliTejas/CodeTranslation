#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
int parent[4005][4005];

struct path{
    int from;
    int to;
    ll cost;
};

struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

bool comp(path a, path b){
    if(a.cost > b.cost){
        return true;
    }
    return false;
}

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    vector<path> pathes;
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        struct path in;
        in.from = a;
        in.to = b;
        in.cost = c;
        pathes.push_back(in);
    }
    sort(pathes.begin(), pathes.end(), comp);
    ll cost[4005];
    UnionFind uni(n + 1);
    ll sum = 0;
    for(int time = 1; time <= n - 1; time++){
        path test;
        while(true){
            test = pathes.back();
            pathes.pop_back();
            if(uni.issame(test.from, test.to)){
                continue;
            }
            break;
        }
        cost[time] = test.cost;
        sum += cost[time];
        uni.merge(test.from, test.to);
        for(int i = 1; i <= n; i++){
            uni.root(i);
        }
        for(int i = 1; i <= n; i++){
            parent[time][i] = uni.root(i);
        }
    }
    int q;
    cin >> q;
    for(int time = 1; time <= q; time++){
        int s, t;
        cin >> s >> t;
        int ok = n - 1;
        int ng = 0;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(parent[mid][s] == parent[mid][t]){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << sum - cost[ok] << endl;
    }
    return 0;
}