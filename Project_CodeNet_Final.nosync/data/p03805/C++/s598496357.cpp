#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

#define DEBUG 0
#define REP(i, n) for (int i = 0; i < (n); i++) 
typedef long long ll;
typedef pair<int,int> pint;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int nMax = 8;
bool graph[nMax][nMax];

//dfs訪問済み
int dfs(int v, int n, bool visited[nMax])
{
    bool all_visited = true;
    for(int i = 0; i < n; ++i)
    {
        if(visited[i] == false)
        {
            all_visited = false;
        }
    }

    //すべて訪問していたら
    if(all_visited)
    {
        return 1;
    }
    int ret = 0;
    for(int i = 0; i < n; ++i)
    {
        //つながっていない
        if(graph[v][i] == false)continue;
        //訪問済み
        if(visited[i]) continue;

        //1次的に訪問済にする
        visited[i] = true;
        ret += dfs(i,n,visited);
        visited[i] = false;
    }
    return ret;
}

int main() { 
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    bool visited[nMax];
    REP(i,n)visited[i] = false;

    visited[0] = true;
    int res = dfs(0,n,visited);

    cout << res << endl;
 
    return 0;

}