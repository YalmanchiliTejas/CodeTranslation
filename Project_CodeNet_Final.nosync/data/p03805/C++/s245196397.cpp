#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/


int N;
bool graph[10][10], visited[10];

int dfs(int v){
    visited[v] = true;

    bool all_visited = true;
    for(int i=1; i<=N; i++) if(visited[i] == false) all_visited = false;
    if(all_visited){
        visited[v] = false;
        return 1;
    }

    int ret = 0;
    for(int i=1; i<=N; i++){
        if(graph[v][i] == true && visited[i] == false){
            ret += dfs(i);
        }
    }


    visited[v] = false;
    return ret;
}


int main(){
    int M; cin >> N >> M;

    vector<int> a(M), b(M);
    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    cout << dfs(1) << endl;

}