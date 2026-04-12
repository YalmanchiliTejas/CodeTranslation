#include <bits/stdc++.h>
using namespace std;

int answer = 0;
int N;
vector<vector<int>> edges;
void dfs(int currentNode, vector<bool> visited)
{
    visited.at(currentNode) = true;
    bool allVisited = true;
    for(bool ed : visited){
        if(!ed){
            allVisited = false;
            break;
        }
    }
    if(allVisited){
        answer++;
        return;
    }
    for(int nextNode: edges.at(currentNode))
    {
        if(visited.at(nextNode)){
            continue;
        }
        dfs(nextNode, visited);
    }
}

int main()
{
    int M;
    cin >> N >> M;
    edges = vector<vector<int>>(N);
    for(int i = 0; i < M ;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.at(a).push_back(b);
        edges.at(b).push_back(a);
    }
    vector<bool> visited(N, false);
    dfs(0, visited);
    cout << answer << endl;
    return 0;
}