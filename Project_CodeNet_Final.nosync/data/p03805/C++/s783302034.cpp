#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int N,M;
vector<vector<int>> graph;
vector<bool> visited;

int dfs(int node, int cnt){
    if(cnt==N) return 1;

    visited[node] = true;

    int ret = 0;
    for(int next_node:graph[node]){
        if(visited[next_node]) continue;
        ret+=dfs(next_node, cnt+1);
    }
    visited[node] = false;
    return ret;
}

int main()
{
    cin >> N>>M;
    visited.resize(N);
    REP(i,N) visited[i] = false;

    graph.resize(N);
    REP(i,M){
        int a,b;
        cin>>a>>b;
      	a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt=0;
    cnt = dfs(0, 1);

    cout << cnt << endl;

    return 0;
}