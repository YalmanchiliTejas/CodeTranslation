/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int n,m,ans;
vi g[10],vis(10);

void dfs(int u,int c){
    if (c == n) {
        ans++;
        return ; 
    }
    for (auto &it: g[u]){
        if (!vis[it]){
            vis[it] = 1;
            dfs(it,c+1);
            vis[it] = 0;
        }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vis[1] = true;
    dfs(1,1);
    cout << ans << endl;
    return 0;
}
