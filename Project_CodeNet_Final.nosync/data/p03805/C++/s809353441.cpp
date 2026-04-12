#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
void dfs(int start, int v_cnt);     // 再帰関数
bool used[10];              // 訪問したかどうか
int adjacency[50][50];      // 隣接行列

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < M; i++){
        adjacency[a[i]][b[i]] = 1;
        adjacency[b[i]][a[i]] = 1;
    }
    
    used[1] = true;
    dfs(1, N);
    
    cout << ans << endl;
}

void dfs(int start, int v_cnt){
    bool flag = true;
    for(int i = 1; i <= v_cnt; i++){
        if(!used[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        ans++;
        return;
    }
    
    for(int i = 1; i <= v_cnt; i++){
        if(!used[i] && adjacency[start][i] != 0){
            used[i] = true;
            dfs(i, v_cnt);
            used[i] = false;
        }
    }
    
    return;
}

