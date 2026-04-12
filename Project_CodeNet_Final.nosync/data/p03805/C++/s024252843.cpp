#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
       
using namespace std;
       
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
 
// #define MAX 100010
 
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES

bool vis[10];
int g[10][10];
int n;

int dfs(int u)
{
    int done=1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            done=0;
    }
    if(done)
        return 1;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(g[u][i]==false)
            continue;
        if(vis[i])
            continue;
        vis[i]=true;
        ans+=dfs(i);
        vis[i]=false;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    // #endif
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a][b]=1;
        g[b][a]=1;
    }
    vis[0]=true;
    cout<<dfs(0)<<endl;
    return 0;
}