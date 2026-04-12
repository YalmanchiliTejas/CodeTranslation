#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

Graph G;

//vは頂点
void dfs(int v, vector<bool> &seen, int &res){
    bool end = true; //すべての頂点を探索済みか否かを表す
    
    for (int i = 0; i < seen.size(); i++){
        if (!seen[i] && i != v){
            end = false; 
            //頂点v以外の頂点を一通りすべて探索済みか？
            //探索していない点が存在すればfalse
        }
    }
    
    if (end){
        //すべての頂点を探索済み -> 答えをインクリメント
        res++;
        return;
    }
    
    seen[v] = true; //頂点vを訪問済みにする
    
    //vの隣接する点を調べる
    for (auto nv: G[v]){
        
        //v隣接点の中で訪問済み -> 調べない
        if (seen[nv]) continue;
        
        dfs(nv, seen, res);
    }
    
    //vを未訪問の状態に戻しておく
    seen[v] = false;
    
}

int main(){
    int n, m;
    cin >> n >> m;
    
    G.assign(n, vector<int>()); //入力
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        //0-indexにもどす
        a--;
        b--;
        
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<bool> seen(n, false); //頂点を検知済みか？？
    
    int numberOfHamiltonPath = 0;
    
    //dfs(parent, seen, path_number)
    dfs(0, seen, numberOfHamiltonPath);
    
    cout << numberOfHamiltonPath << endl;
}