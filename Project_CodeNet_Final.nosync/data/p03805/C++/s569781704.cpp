#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;
  int a[M], b[M];
  int perm[N];
  int i, j;
  for(i=1; i<=M; i++)
    cin >> a[i] >> b[i];

  //順列を生成するための配列
  for(i=1; i<=N; i++)
    perm[i] = i;

  //グラフ宣言．N*Nの隣接行列で表現する
  //要素がない場所は-1にしておく
  vector<vector<int>> graph(N+1, vector<int>(N+1, -1));

  //グラフの生成
  for(i=1; i<=M; i++){
    graph[a[i]][b[i]] = b[i];
    graph[b[i]][a[i]] = a[i];
  }

 
 int ans = 0;
 do{
   //順列に沿って道があるかをみていく
   for(i=1; i<=N-1; i++){
     //道がない(初期化-1のままである)ならば次の順列へ
     if(graph[ perm[i] ][ perm[i+1] ] == -1)
     break;
   }

   //上の探索において順列に沿って最後まで辿れたとき
   if(i == N)
     ans++;
 }while(next_permutation(perm+2, perm+N+1));
 
 cout << ans << endl;
 
  return 0;
}
