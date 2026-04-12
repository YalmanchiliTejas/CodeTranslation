#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<tuple>
#include<vector>
#include<map>
using namespace std;

static const int maxN = 8, maxM = 32;

bool checkPath(const vector<int>& node, const int edgeList[maxN][maxN]){
  //vectorの隣のパスが存在するかを調べる
  bool flag = true;
  for(int i = 0; i < node.size() - 1; i++){
    if(node[0] != 0){
      flag = false;
      break;
    }
    else if(edgeList[node[i]][node[i + 1]] == 0){
      flag = false;
      break;
    }
  }
  return flag;
}

int main(void){
  int N, M;
  int a[maxM], b[maxM];
  int edgeList[maxN][maxN];
  vector<int> node;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    cin >> a[i] >> b[i];
  }
  //0~N-1に添字を一個ずらす
  for(int i = 0; i < M; i++){
    a[i] = a[i] - 1, b[i] = b[i] - 1;
  }
  for(int i = 0; i < N; i++){
    node.push_back(i);//0~N-1をストックする。
  }
  //EdgeListでエッジの情報を管理
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      edgeList[i][j] = 0;
    }
  }
  for(int i = 0; i < M; i++){
    edgeList[a[i]][b[i]]++;
    edgeList[b[i]][a[i]]++;
    //cout << node[i] << endl;
  }
  /*for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(edgeList[i][j] != 0) cout << i << " " << j << " " << edgeList[i][j] << endl;
    }
  }*/

  //N個の並び替えを行なって，パスが存在するかをチェックしてみる。
  int cntPath = 0;
  do{
    if(checkPath(node, edgeList)) cntPath++;
  }while(next_permutation(node.begin(), node.end()));
  cout << cntPath << endl;
  return 0;
}
