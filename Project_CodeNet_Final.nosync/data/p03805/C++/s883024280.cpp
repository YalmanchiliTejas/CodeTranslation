#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  int edge[N][N];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      edge[i][j] = false;
    }
  } 
  for(int i=0;i<M;i++){
    int a, b;
    cin >> a >> b;
    edge[a-1][b-1] = true;
    edge[b-1][a-1] = true;
  }

  int vertex[N];
  for(int i=0;i<N;i++) vertex[i] = i;

  int ans = 0;
  do{
    /*for(int i=0;i<N;i++) cout << vertex[i] << " ";
    cout <<endl;*/
    bool judge = true;
    for(int i=0;i<N-1;i++){
      if(!edge[vertex[i]][vertex[i+1]]){
        judge = false;
        break;
      }
    }
    if(judge){
      ans++;
    }
  }while(next_permutation(vertex+1,vertex+N));

  cout << ans <<endl;
  return 0;
}