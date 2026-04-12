#include<bits/stdc++.h>
using namespace std;

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){ // vは現在の頂点
 bool all_visited=true;
 for(int i=0; i<N; i++){
  if(visited[i]==false){ // 全ての頂点を通過した場合はvisited[i]=trueになるため、
    all_visited=false;}
 }

 if(all_visited){return 1;} // aii_visited=trueで1通りのルートがresに追加される

 int ret=0; // 繋がっていないならres=0がresに追加される
 for(int i=0; i<N; i++){
  if(graph[v][i]==false){continue;} // graph[v][i]がどこかに繋がっているなら以下の処理実行
  if(visited[i]){continue;} // i(Bの値)がまだ未到達(false)の場合は以下の処理実行
  visited[i]=true; // i(Bの値)がまだ未到達の場合は到達したことにしてtrueにする
  ret+=dfs(i, N, visited);  // i(Bの値)の処理を再帰dfsで行う
  visited[i]=false; // 一度そのルートで通った辺はfalseにしてリセットする
 }

 return ret; // この数値が返される
}

int main(){
int N, M;
 cin>>N>>M;
 for(int i=0; i<M; i++){
  int A, B;
  cin>>A>>B;
  graph[A-1][B-1]=graph[B-1][A-1]=true; // 頂点A, Bは互いに繋がっていることを表す
 }

 bool visited[nmax];
 for(int i=0; i<N; i++){
  visited[i]=false; // 処理前なのでまだ全ての辺は未通過(false)にする
 }

 visited[0]=true; // Bの初期値を通過済み(true)にする
 cout<<dfs(0, N, visited);
 return 0;
}