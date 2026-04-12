#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#ifndef debug_on
#define debug_on 0
#endif

#define dbg \
    if(debug_on) cerr << "DEBUG:"
#define ast(cond)           \
    do {                    \
        if((cond) == false) \
        {                   \
            if(debug_on)    \
            cerr << "ASSERT" << #cond " failed at line:" << __LINE__ << endl;   \
            exit(1);        \
        }                   \
    }while(0)

const int MAX_N = 9;
int N, M;
vector<int> A[MAX_N];
bool visited [MAX_N];

int DFS(int cur, int depth)
{
    if(visited[cur])
        return 0;
    if(depth == N)
        return 1;

    visited[cur] = 1;

    int num_path = 0;
    for(size_t j = 0; j < A[cur].size(); ++j)
    {
        const int next = A[cur][j];
        if(visited[next]) continue;
        num_path += DFS(next, depth + 1);
    }

    visited[cur] = 0;
    return num_path;
}

int main(int, char *[])
{
    cin >> N >> M;
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    const int path = DFS(1, 1);
    cout << path << endl;

    return 0;
}
