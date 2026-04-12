#include <bits/stdc++.h>
using namespace std;

struct edge {int to; int weight;};
typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;
    vector<P> x(N), y(N);
    for(int i=0; i<N; ++i) {
        int s, t;
        cin >> s >> t;
        x[i] = P(s, i);
        y[i] = P(t, i);
    }

    sort(begin(x), end(x));
    sort(begin(y), end(y));

    vector<vector<edge>> cost(N, vector<edge>(0));
    for(int i=0; i+1<N; ++i) {
        cost[x[i].second].push_back({x[i+1].second, x[i+1].first - x[i].first});
        cost[x[i+1].second].push_back({x[i].second, x[i+1].first - x[i].first});
        cost[y[i].second].push_back({y[i+1].second, y[i+1].first - y[i].first});
        cost[y[i+1].second].push_back({y[i].second, y[i+1].first - y[i].first});
    }
    
    // Prim's algorithm
    priority_queue<P, vector<P>, greater<P>> mincost;
    vector<bool> used(N, false);
    mincost.push(P(0,0));
    long long res = 0;

    while(!mincost.empty()) {
        P v = mincost.top(); mincost.pop();
        if(used[v.second]) continue;
        used[v.second] = true;
        res += v.first;

        for(edge e : cost[v.second]) {
            mincost.push(P(e.weight, e.to));
        }
    }

    cout << res << endl;
}