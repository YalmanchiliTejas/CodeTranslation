#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<bool> > g(N,vector<bool>(N,false));
    vector<int> V(N-1);
    rep(i,N-1)V[i] = i+1;
    rep(i,M){
        int u,v;cin >> u >> v;
        u--;v--;
        g[u][v] = g[v][u] = true;
    }
    int res = 0;

    do{
        int u = 0;
        rep(i,V.size()){
            if(!g[u][V[i]])break;
            u = V[i];
            if(i == V.size()-1)res++;
        }


    }while (next_permutation(V.begin(),V.end()));
    cout << res << endl;
    return 0;
}