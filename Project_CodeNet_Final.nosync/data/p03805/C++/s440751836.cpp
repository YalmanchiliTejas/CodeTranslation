#include<iostream>
#include<vector>

using namespace std;
using Graph = vector<vector<int>> ;
Graph G;

void dfs(int v, vector<bool> &seen, int & res){
    bool end  = true; //すべての頂点を探索済か否かを表す
    for(int i = 0; i < seen.size(); i++){
        if(!seen[i] && i != v){ 
            end = false; //頂点 v 以外の頂点を一通り全て探索済みかどうか調べる. 探索していない点が存在すれば falseを返しておく
        }
    }
    if(end){
        res++; //すべての頂点を探索したことがわかったら答えをインクリメントした上でリターンする
        return;
    }

    seen[v] = true; //その頂点を訪問済みにする
    for(auto nv: G[v]){ //vの隣接する点を調べる
        if(seen[nv])continue; //vの隣接する点の中ですでに訪問済みの点の場合は調べない（重複防止）
        dfs(nv, seen, res); //vの隣接する点についてdfsを行って再帰的に調べる
    }

    seen[v] = false;
}

int main(void){
    int N, M;
    cin >> N >> M;
    G.assign(N, vector<int>()); // グラフ入力受取 (ここでは無向グラフを想定)
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        --a; //0-indexのためデクリメント
        --b; //0-indexのためデクリメント
        G[a].push_back(b); //隣接リストを作る
        G[b].push_back(a); //隣接リストを作る
    }
    vector<bool> seen(N, false); //seen: その頂点を検知済みかどうかを表す配列
    int number_of_Hamilton_path = 0;
    dfs(0, seen, number_of_Hamilton_path); //dfs(parent, 検知済み配列, pathの数)
    cout << number_of_Hamilton_path  << endl;
    return 0;
}