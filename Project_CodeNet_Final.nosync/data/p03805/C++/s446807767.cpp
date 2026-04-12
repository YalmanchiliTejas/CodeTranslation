#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <malloc.h>
#include <stack>
#include <cstring>
#include <string>
#include <set>
#include <unordered_map>
#define INT long long int
#define MOD 1000000007
#define oo 987654321
using namespace std;

int n, m, chk[110];
vector<int> G[110];

int dfs(int x)
{
    int cnt = 0, ret = 0;
    for(int i = 1 ; i <= n ; i++ )
        if( chk[i] ) cnt++;
    if( cnt == n ) return 1;
    for(int i = 0 ; i < G[x].size() ; i++ )
        if( !chk[G[x][i]] ) chk[G[x][i]] = 1, ret += dfs(G[x][i]), chk[G[x][i]] = 0;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++ )
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    chk[1] = 1;
    cout<<dfs(1)<<endl;
    return 0;
}


