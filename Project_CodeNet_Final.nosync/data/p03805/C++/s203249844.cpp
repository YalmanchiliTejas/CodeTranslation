#include <iostream>
#include <vector>
#include <utility>

void dfs(int N, int &count, std::vector<std::pair<int, int> > &edge, std::vector<bool> &flag, int node, int depth)
{
    if(depth == N-1){
        count++; return;
    }
    flag[node] = true;
    for(auto &&itr = edge.begin(); itr != edge.end(); itr++){
        if(itr->first == node && flag[itr->second] == false) dfs(N, count, edge, flag, itr->second, depth+1);
        if(itr->second == node && flag[itr->first] == false) dfs(N, count, edge, flag, itr->first, depth+1);
    }
    flag[node] = false;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, int> > edge(M);
    for(int i=0; i<M; i++) std::cin >> edge[i].first >> edge[i].second;

    int count = 0;
    std::vector<bool> flag(N, false);
    dfs(N, count, edge, flag, 1, 0);
    std::cout << count << std::endl;
}