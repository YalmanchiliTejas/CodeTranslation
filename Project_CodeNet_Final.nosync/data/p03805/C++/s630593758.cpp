#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int N;
bool g[10][10];
bool seen[10];

int dfs(int now){
    bool all_seen = true;
    for(int i=1; i<=N; i++){
        if(seen[i] == false) all_seen = false;
    }
    if(all_seen) return 1;

    int res = 0;
    for(int to=1; to<=N; to++){
        if(g[now][to] == true && seen[to] == false){
            seen[to] = true;
            res += dfs(to);
            seen[to] = false;
        }
    }

    return res;
}

int main(){
    int M; cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    seen[1] = true;
    cout << dfs(1) << endl;
    return 0;
}