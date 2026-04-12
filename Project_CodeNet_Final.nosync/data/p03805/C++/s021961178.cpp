#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> graph(8,vector<bool>(8)) ;
vector<bool> visit(8);

int dfs(int v, int N){
    
    
    bool all_Visit = true;  // 変数：全て訪問済
    
    // 全て訪問済か確認
    for(int i = 0; i < N; i++){
        if(visit[i] == false) all_Visit = false;
    }
    
    // 全て訪問のとき1を返して加える
    if(all_Visit) return 1;
    
    
    int ret = 0;  // 変数：今回の答えの値リピート
    
    for(int i = 0; i < N; i++){
        if(graph[v][i] == false) continue;  // 判定：入力時に値が入ってない
        if(visit[i]) continue; // ルート自身が存在しない時
        
        visit[i] = true;
        ret += dfs(i, N);
        visit[i] = false;
    }
    
    return ret;
}





int main(void){
    
    int N, M;
    
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A--, B--;
        graph[A][B] = graph[B][A] = true;
    }
    
    //vector<bool> visit(8);
    for(int i = 0; i < N; i++){
        visit[i] = false;
    }
    
    visit[0] = true;
    cout << dfs(0, N) << endl;
}
