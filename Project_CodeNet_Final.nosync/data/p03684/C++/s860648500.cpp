#include <bits/stdc++.h>

using namespace std;

struct edge {
    int w, a, b;
};

struct union_find {
    vector<int> par;

    union_find(int n) {
        par.resize(n, -1);
    }

    int find(int i) {
        if (par[i] < 0) return i;
        else return par[i] = find(par[i]);
    }

    void merge(int i, int j) {
        int pi = find(i);
        int pj = find(j);

        if (pi == pj) return;

        if (par[pi] < par[pj]) {
            par[pj] = pi;
        } else if (par[pi] > par[pj]) {
            par[pi] = pj;
        } else {
            par[pj] = pi;
            par[pi]--;
        }
    }
};

int main() {
    int N;
    scanf("%d", &N);

    vector<int> x(N), y(N);
    vector<int> by_x(N), by_y(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        by_x[i] = i;
        by_y[i] = i;
    }

    sort(by_x.begin(), by_x.end(), [&](int a, int b) {
        return x[a] < x[b];
    });
    sort(by_y.begin(), by_y.end(), [&](int a, int b) {
        return y[a] < y[b];
    });

    vector<edge> edges;
    for (int i = 0; i < N - 1; ++i) {
        edges.push_back({x[by_x[i + 1]] - x[by_x[i]], by_x[i], by_x[i + 1]});
        edges.push_back({y[by_y[i + 1]] - y[by_y[i]], by_y[i], by_y[i + 1]});
    }
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w;
    });

    union_find uf(N);

    int cost = 0;
    for (int i = 0; i < edges.size(); ++i) {
        if (uf.find(edges[i].a) != uf.find(edges[i].b)) {
            cost += edges[i].w;
            uf.merge(edges[i].a, edges[i].b);
        }
    }

    printf("%d\n", cost);

    return 0;
}
