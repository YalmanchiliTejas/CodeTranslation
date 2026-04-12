#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<int>to[10];
int n,m,ans;

void dfs(int v, int p, vector<bool>x, vector<int>y){
    if(x[v])return;
    y.push_back(v);
    x[v]=true;
    for(int u:to[v]){
        if(u==p)continue;
        dfs(u,v,x,y);
    }
    if(y.size()==n)ans++;
}

int main(){
    cin>>n>>m;
    rep(i,m){
        int a,b; cin>>a>>b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0,-1,vector<bool>(n,false),vector<int>());
    cout<<ans<<endl;
}