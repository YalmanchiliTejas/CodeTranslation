#include <iostream>
#include <memory>
#define MAX_N 8
#define MAX_M 28
using namespace std;

int N,M;
bool g[MAX_N][MAX_N] = {false};
int dp[1 << MAX_N][MAX_N];//dpテーブル

//すでに訪れた頂点をＳ、現在位置がvとする
int rec(int S ,int v){
    if(S ==(1 << N) - 1){
        return 1;//全ての頂点を訪問した。
    }
    int res = 0;
    for(int u = 0; u < N; u++){
        if(!(S >> u & 1) && g[v][u] == true){//まだuには訪問していない　かつ、その辺は存在するか
            //次にuに移動する
            res += rec(S | 1 << u, u);
        }
    }
    return res;
}

int main(){
    cin >> N >> M;
    int f,t;
    for(int i = 0; i < M; i++){ 
        cin >> f >> t;
        g[f-1][t-1] = true;
        g[t-1][f-1] = true;
    }
    //bitDPで計算する
    cout << rec(1,0) << endl;//頂点1からスタートする。
    return 0;
}