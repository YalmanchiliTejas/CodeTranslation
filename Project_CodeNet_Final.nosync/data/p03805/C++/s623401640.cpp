#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define fi first
#define se second
#define pb(i) push_back(i)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define mes(a,b) memset(a,b,sizeof(a))
#define sbs(i,j) substr(i,j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6+10;
const int INF = 0x3f3f3f3f;
const int inf = - INF;
const int mod = 1e9+7;
const double pi = acos(-1.0);

int edges[15][15];
bool vis[15];
int n,m;
int dfs(int x){
    bool all_vis=true;
    rep(i,1,n)
        if(!vis[i]) all_vis=false;
    if(all_vis) return 1;
    int res=0;
    rep(i,1,n){
        if(vis[i]) continue;
        if(edges[x][i]){
            vis[i]=true;
            res+=dfs(i);
            vis[i]=false;
        }
    }
    return res;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m){
        int x,y;
        cin>>x>>y;
        edges[x][y]=true;
        edges[y][x]=true;
    }
    vis[1]=true;
    cout<<dfs(1)<<endl;
    return 0;
}