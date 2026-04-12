#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > pip;

struct Edge {
    int cost;
    int from;
    int to;

    bool operator<(const Edge& another) const {
        return cost < another.cost;
    }
};

#define MAX 100001
vector<Edge> edges;
pip points[MAX];
int ace[MAX];


bool cmp_x(pip p1, pip p2) {
    return p1.second.first < p2.second.first;
}

bool cmp_y(pip p1, pip p2) {
    return p1.second.second < p2.second.second;
}

int ancestor(int x) {
    return x == ace[x] ? x : ace[x]=ancestor(ace[x]);
}

int main(void) {
    int N, x, y;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &x, &y);
        points[i] = make_pair(i, make_pair(x, y));
    }

    sort(points, points+N, cmp_x);
    for(int i = 1; i < N; i++) {
        pip p1 = points[i], p2 = points[i-1];
        edges.push_back(Edge{p1.second.first - p2.second.first, p1.first, p2.first});
    }

    sort(points, points+N, cmp_y);
    for(int i = 1; i < N; i++) {
        pip p1 = points[i], p2 = points[i-1];
        edges.push_back(Edge{p1.second.second - p2.second.second, p1.first, p2.first});
    }
    sort(edges.begin(), edges.end());

    for(int i=0; i<N; i++) ace[i] = i;
    ll ans = 0;
    int num = 0;
    for(int i=0; i<edges.size(); i++) {
        Edge e = edges[i];
        int from = e.from, to = e.to;

        if(ancestor(from) != ancestor(to)) {
            ans += e.cost;
            ace[ancestor(from)] = ancestor(to);
            num++;
        }
        
        if(num == N) break;
    }

    return !printf("%lld\n", ans);
}