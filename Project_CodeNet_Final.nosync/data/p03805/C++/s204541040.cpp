#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

using Graph = vector<vector<int>>;
vector<bool> seen;

int dfs(const Graph &G, int v)
{
    bool allComp = true;
    for(auto visit:seen)
    {
        if(!visit) allComp = false;
    }
    if(allComp) return 1;

    int ret = 0;
    seen[v] = true;
    for(auto next_v:G[v])
    {
        if(seen[next_v]) continue;
        seen[next_v] = true;
        ret += dfs(G,next_v);
        seen[next_v] = false;
    }
    return ret;
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    Graph graph(N);
    for(int i=0;i<M;i++)
    {
        int A,B;
        cin >> A >> B;
        graph[A-1].push_back(B-1);
        graph[B-1].push_back(A-1);
    }
    seen.assign(N,false);

    cout << dfs(graph,0) << endl;

    return 0;
}