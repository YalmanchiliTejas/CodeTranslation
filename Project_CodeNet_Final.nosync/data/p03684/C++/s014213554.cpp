#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int INFTY = 1000000005;
const int WHITE = 0;
const int BLACK = 1;
pair<int, int> X[MAX], Y[MAX];
vector<pair<int, int>> adj[MAX];
int N;

long long prim() {
    long long sum = 0ll;
    int d[MAX], color[MAX];
    priority_queue<pair<int, int>> PQ;

    for (int i = 0; i < N; i++) {
        d[i] = INFTY;
        color[i] = WHITE;
    }

    d[0] = 0;
    PQ.push(make_pair(0, 0));

    while (!PQ.empty()) {
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;
        if (color[u] == BLACK) continue;
        color[u] = BLACK;
        d[u] = -f.first;
        sum += -f.first;


        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].second;
            if (color[v] == BLACK) continue;
            PQ.push(make_pair(-adj[u][i].first, v));
        }
    }

    return sum;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i].first, &Y[i].first);
        X[i].second = Y[i].second = i;
    }
    sort(X, X+N);
    sort(Y, Y+N);
    for (int i = 1; i < N; i++) {
        adj[X[i-1].second].push_back(make_pair(X[i].first-X[i-1].first, X[i].second));
        adj[X[i].second].push_back(make_pair(X[i].first-X[i-1].first, X[i-1].second));
        adj[Y[i-1].second].push_back(make_pair(Y[i].first-Y[i-1].first, Y[i].second));
        adj[Y[i].second].push_back(make_pair(Y[i].first-Y[i-1].first, Y[i-1].second));
    }

    long long ans = prim();
    printf("%lld\n", ans);
    return 0;
}