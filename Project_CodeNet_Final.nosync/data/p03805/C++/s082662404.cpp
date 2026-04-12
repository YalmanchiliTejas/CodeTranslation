#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int N,M;
ll ans=0;

void dfs(int p,vector<vector<int>> E,vector<bool> used){  
    bool gg=true;
    used[p]=true;
    for (int i=0;i<N;i++){
        if (!used[i]) gg=false;
    }
    if (gg) {
        ans++;
        return;
    }

    bool cont=false;

    for (int i=0;i<E[p].size();i++){
        if (!used[E[p][i]]) {
            cont = true;
            gg = false;
            dfs(E[p][i],E,used);
        }
    }
    if (!cont) {
        return;
    }
}

int main(void){

    cin>>N>>M;
    vector<vector<int>> E(N);
    for (int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        E[a-1].push_back(b-1);
        E[b-1].push_back(a-1);
    }
    vector<bool> used(N,false);
    used[0]=true;
    dfs(0,E,used);
    cout<<ans<<endl;
    return 0;
}