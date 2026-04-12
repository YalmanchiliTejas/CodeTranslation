#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

bool graph[10][10];
bool seen[10];

int N, M;

int dfs(int now){
    seen[now] = true;
    bool flg = true;
    for(int i=0; i<N; i++) if(!seen[i]) flg = false;
    if(flg) { seen[now] = false; return 1;} 

    int res = 0;
    for(int to=0; to<N; to++){
        if(graph[now][to] && seen[to] == false){
            res += dfs(to);
        }
    }

    seen[now] = false;
    return res;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        graph[a][b] = graph[b][a] = true;
    }

    cout << dfs(0) << endl;
}