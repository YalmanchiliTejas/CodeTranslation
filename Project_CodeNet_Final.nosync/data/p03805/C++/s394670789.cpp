#include <limits>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

template<class F>
void times_do(size_t n, F func)
{
    for(size_t i = 0; i < n; ++i) func();
}

template<class T>
T read()
{
    T value;
    std::cin >> value;
    return value;
}

template<class T>
vector<T> reads(size_t n)
{
    vector<T> a;
    a.reserve(n);
    times_do(n, [&](){
        a.push_back(read<T>());
    });
    return a;
}

template<class T>
vector<vector<T>> reads(size_t n, size_t m)
{
    vector<vector<T>> a;
    a.reserve(n);
    times_do(n, [&](){
        a.push_back(reads<T>(m));
    });
    return a;
}

int count_paths(const vector<vector<bool>>& graph, size_t index, vector<bool>& visited)
{
    if(visited[index]) return 0;
    
    visited[index] = true;
    
    if(all_of(begin(visited), end(visited), [](auto x){ return x; }))
    {
        visited[index] = false;
        return 1;
    }
    
    int paths = 0;
    for(size_t i = 0; i != graph.size(); ++i)
    {
        if(i != index && graph[index][i])
        {
            paths += count_paths(graph, i, visited);
        }
    }
    
    visited[index] = false;
    return paths;
}

int count_paths(const vector<vector<bool>>& graph)
{
    vector<bool> visited(graph.size(), false);
    return count_paths(graph, 0, visited);
}

int main()
{
    const auto N = read<size_t>();
    const auto M = read<size_t>();
    
    vector<vector<bool>> graph(N, vector<bool>(N, false));
    
    times_do(M, [&](){
        int a,b;
        cin >> a >> b;
        a--;b--;
        graph[a][b] = graph[b][a] = true;
    });
    
    cout << count_paths(graph) << '\n';
    
    return 0;
}
