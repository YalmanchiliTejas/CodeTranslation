#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for(int i=0; i<N; i++){
    P[i]=i+1;
  }
  bool E[9][9]={};
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    E[a][b]=E[b][a]=true;
  }
  int count=0;
  do{
    bool f =true;
    for(int i=0; i<N-1; i++){
      if(E[P[i]][P[i+1]]) continue;
      f=false; break;
    }
    if(f) count++;
  }while(next_permutation(P.begin()+1, P.end()));
  cout << count << endl;
  return 0;
}