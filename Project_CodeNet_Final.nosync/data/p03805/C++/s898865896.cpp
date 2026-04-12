#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
vector<int> graph[10];
int visited[10];
int n;
int dfs(int now){
    int res = 0;
    visited[now] = 1;
    int cnt = 0;
    rep(i,n){
        if(visited[i])cnt++;
    }
    if(cnt == n)return 1;
    for(int next : graph[now]){
        if(visited[next])continue;
        res += dfs(next);
        visited[next] = 0;
    }
    



        
    return res;

}
int main()
{
    int m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    cout << dfs(0) << endl;
    return 0;
}