#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int mod = 1e9+7;

int n,m;
int graph[10][10];

int jud(int flag[])
{
    for(int i = 0; i < n; i++) if(flag[i] == 0) return 0;
    return 1;
}

int dfs(int now,int flag[])
{
    if(jud(flag)) return 1;
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(graph[i][now] && flag[i] == 0){
            flag[i] = 1;
            ret += dfs(i,flag);
            flag[i] = 0;
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        a--,b--;
        graph[a][b] = graph[b][a] = 1;
    }

    int flag[8] = {1};
    cout << dfs(0,flag) << endl;
}