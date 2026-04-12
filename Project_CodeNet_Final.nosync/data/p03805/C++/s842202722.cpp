#include <bits/stdc++.h>
using namespace std;
//One-stroke Path

int cnt = 0;
vector<bool> use;

void calc(vector<vector<int> > &G, int n, vector<int> &E){
    if(E.size() == G.size()){
        bool is_unique = true;
        for(auto e : E){
            if(use[e] != false){
                is_unique = false;
            }
            use[e] = true;
        }
        if(is_unique){
            // for(int i  = 0; i < E.size();++i) cout << E[i] + 1 << " ";
            // cout << endl;   
            cnt++;
        }
        for(int i  = 0; i < use.size();++i)use[i] = false;
        return;
    }

    for(auto e : G[n]){
        bool is_exist = false;
        for(int i = 0; i < E.size(); ++i){
            if(e == E[i])is_exist = true;
        }
        if(is_exist)continue;
        E.push_back(e);
        calc(G, e, E);
        E.pop_back();
    }
    return;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N);
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    
    use.assign(N, false);
    vector<int> E;
    E.push_back(0);
    calc(G, 0, E);
    cout << cnt << endl;
    return 0;
}