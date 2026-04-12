#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int graph[10][10];

//vは現在地
int dfs(int v, int n, int visited[10]){
    //すべて訪れたかどうか
    int res = 1;
    for(int i = 0; i < n; i++)
    {
        if(visited[i]==0){
            res = 0;
        }
    }
    //すべて訪れていたら1を返す
    if(res==1) return 1;

    //最終的な返り値
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i]==1 && visited[i]==0){
            //次の目的地をiにする
            visited[i] = 1;
            cnt += dfs(i, n, visited);
            //i+1の場合も確かめるため、元に戻す
            visited[i] = 0;
        }
    }
    
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }
    int visited[10];
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    cout << dfs(0, n, visited) << endl;
    return 0;
}