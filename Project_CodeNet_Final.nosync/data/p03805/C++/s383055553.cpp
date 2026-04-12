#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

bool path[10][10] = {};

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> v(N);
  rep(i,N){
    v[i] = i;
  }
  //無効グラフの作成
  rep(i,M){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    path[a][b] = true;
    path[b][a] = true;
  }
  //N!全探索
  int res = 0;
  do{
    if(v[0] != 0) break;
    bool flag = true;
    rep(i,N-1){
      if(!path[v[i]][v[i+1]]) flag = false;
    }
    if(flag) res++;
  }while(next_permutation(v.begin(),v.end()));
  cout << res << endl;
}