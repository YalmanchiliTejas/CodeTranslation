#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <queue>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int i=(m);(i)<(n);(i)++)
#define ll long long
int n,m;
vector<vector<int> > G;
vector<bool> visited;
int dfs(int cur){
    bool all_v = true;
    for(bool x:visited){
        if(x==false){
            all_v = false;
            break;
        }
    }

    if(all_v)return 1;

    int ret = 0;
    for(int x:G[cur]){
        if(visited[x])continue;
        visited[x]=true;
        ret += dfs(x);
        visited[x]=false;
    }
    return ret;
}

int main(){
    cin >> n >> m;
    G.resize(n);
    visited.resize(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    visited[0]= true;
    cout << dfs(0) << endl;

    return 0;
}