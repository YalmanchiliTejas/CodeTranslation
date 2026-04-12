#include<bits/stdc++.h>
using namespace std;

vector<int> g[15];
bool used[15]={};
int N;

int solve(int u,int pa=-1){
    bool all=true;
    for(int i=0;i<N;i++){
        if(used[i]==true) continue;
        all=false;
    }
    if(all) return 1;
    int ans=0;
    for(auto v:g[u]){
        if(v==pa||used[v]) continue;
        used[v]=true;
        ans+=solve(v,u);
        used[v]=false;
    }
    return ans;
}

int main(){
    int M; cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    used[0]=true;
    cout << solve(0) << endl;
}