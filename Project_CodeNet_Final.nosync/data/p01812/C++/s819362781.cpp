#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main(){
  int N, M, K;
  cin >> N >> M >> K;
  int D[M], V[N][K];
  for(int i = 0; i < M; ++i){
    cin >> D[i];
    --D[i];
  }
  map<int,int> R;
  for(int i = 0; i < M; ++i){
    R[D[i]] = i+1;
  }
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < K; ++j){
      cin >> V[i][j];
      --V[i][j];
    }
  }
  queue<int> que;
  //queue< pair<int,int> > que;
  map<int,int> L;
  int d = (1<<M)-1;
  que.push(d);
  //que.push(make_pair(d,1));
  L[d] = 1;
  while(!que.empty()){
    int s = que.front(), len = L[s];
    //int s = que.front().first, len = que.front().second;
    que.pop();
    for(int i = 0; i < K; ++i){
      int t = 0;
      for(int j = 0; j < M; ++j){
	if(((s>>j)&1) && R[V[D[j]][i]]){
	  t |= (1<<(R[V[D[j]][i]]-1));
	}
      }
      if(!t){
	cout << len << endl;
	return 0;
      }
      if(len+1 < L[t] || !L[t]){
	que.push(t);
      //que.push(make_pair(t,len+1));
	L[t] = len+1;
      }
    }
  }
  return 0;
}