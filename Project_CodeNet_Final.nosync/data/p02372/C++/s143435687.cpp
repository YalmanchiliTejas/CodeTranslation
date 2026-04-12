#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
int n;
struct eg{ int v,w;};
vector<eg> grf[MAXN];
int in[MAXN],out[MAXN];

void dfs1(int u,int par){
    for(auto nbr: grf[u]){
        if(nbr.v == par)continue;
        dfs1(nbr.v,u);
        in[u] = max(in[u], in[nbr.v]+nbr.w);
    }
}

void dfs2(int u,int par){
    // out[u]=0;
    int mx1=-1, mx2= -1;
    for(auto nbr : grf[u]){
        if( nbr.v == par) continue;
        if( in[nbr.v] + nbr.w>= mx1){
            mx2 = mx1; mx1= in[nbr.v]+nbr.w;
        }
        else if( in[nbr.v] +nbr.w > mx2){
            mx2 = in[nbr.v]+nbr.w;
        }
    }
    for(auto nbr: grf[u]){
        if(nbr.v == par)continue;
        int use = mx1;
        if( in[nbr.v]+nbr.w == mx1){ use=mx2; }
        out[nbr.v] =  max(out[u]+nbr.w, use+nbr.w );
        dfs2(nbr.v,u);
    }
}

int main() {
    // freopen("./input.txt","r",stdin);
    // freopen("./output.txt","w",stdout);

    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n-1; i++){
        int a,b,c; cin>>a>>b>>c;
        grf[a].push_back({b,c});
        grf[b].push_back({a,c});
    }
    dfs1(0,-1);
    dfs2(0,-1);
    for(int i=0; i<n; i++){
        cout<< max(in[i],out[i])<<"\n";
    }
}
