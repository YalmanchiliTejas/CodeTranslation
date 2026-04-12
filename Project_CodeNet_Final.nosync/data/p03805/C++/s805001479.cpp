#include <iostream>
#include <stack>
using namespace std;
const int MAX = 10;

stack<int> path;
int edge[MAX][MAX];

bool isInPath(int k){ //pathにkが含まれるかを判定
  stack<int> tmpStack;
  tmpStack = path;
  while(!(tmpStack.empty())){
    if(k == tmpStack.top()) return true;
    else tmpStack.pop();
  }
  return false;
}

int countPath(int k,int N){
  int sum = 0;
  if(path.size()==N){
    path.pop();
    return 1;
  }
  for(int i=0;i<N;i++){
    if(edge[k][i]==1 && !(isInPath(i))){
      path.push(i);
      sum += countPath(i,N);
    }
  }
  path.pop();
  return sum;
}

int main(){
  int N,M; 
  cin >> N >> M;
  
  for(int i=0;i<N;i++) //edgeの初期化
    for(int j=0;j<N;j++) edge[i][j] = 0;

  for(int i=0;i<M;i++){ //edgeの入力. ただし頂点は0からスタート
    int a,b;
    cin >> a >> b;
    edge[a-1][b-1] = 1;
    edge[b-1][a-1] = 1;
  }
  path.push(0);
  cout << countPath(0,N) << endl;
  return 0;
}