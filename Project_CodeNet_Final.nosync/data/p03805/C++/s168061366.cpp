#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std; 

const int nmax = 8;
bool graph[nmax][nmax] = {false};

int dfs(int v, int n, bool visited[nmax])
{
    bool all_visited = true;
    
    for(int i=0; i<n; i++)
    {
        if(visited[i] == false)
            all_visited = false; 
    }

    if(all_visited) return 1;

    int ret = 0;

    for(int i=0; i<n; i++)
    {
        if(graph[v][i]==false) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, n, visited);
        visited[i] = false;
    }

    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    bool visited[nmax] = {false};
    
    visited[0] = true;
    
    std::cout << dfs(0, n, visited) << std::endl;

    return 0;
}
