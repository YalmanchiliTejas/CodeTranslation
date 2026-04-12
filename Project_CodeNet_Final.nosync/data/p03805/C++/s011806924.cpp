#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define INF 100000
#define rep(i, n) for(int i=0; i<n; ++i)
#define REP(i, s, t) for(int i=s; i<=s; ++i)

using namespace std;

const int nmax=8;
bool graph[nmax][nmax];


int dfs(int v, int N, bool visited[nmax])
{
    bool all_visited=true;

    // if all points are visited, add 1 to answer
    rep(i, N)
    {
        if(visited[i]==false) all_visited=false;
    }
    if(all_visited) return 1;

    int ret=0;

    rep(i, N)
    {
        // adjacent && not visited
        if(graph[v][i]==false) continue;
        if(visited[i]) continue;

        visited[i]=true;
        ret+=dfs(i, N, visited);
        visited[i]=false;
    }

    return ret;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    rep(i, M)
    {
        int A, B;
        cin >> A >> B;
        graph[A-1][B-1]=graph[B-1][A-1]=true;
    }

    bool visited[nmax];
    rep(i, N) visited[i]=false;

    visited[0]=true;
    cout << dfs(0, N, visited) << endl;

    return 0;
}
