/**
 * @author torith
 * @date 2018-10-31
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<int> edges[10];
int goal;

int dfs(int now, vector<int> visited){
    visited.push_back(now);
    if((int) visited.size() == goal) return 1;
    int rtn = 0;

    for (auto & e: edges[now]){
        auto r = find(visited.begin(),visited.end(),e);
        if (r == visited.end()) {
            rtn += dfs(e,visited);
        }
    }

    return rtn;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M; cin >> N >> M;
    goal = N;
    for (int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    vector<int> ini = {};
    cout << dfs(0,ini) << "\n";

    return 0;
}

