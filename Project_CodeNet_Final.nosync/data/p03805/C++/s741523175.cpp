#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N, vector<int>(N));
  int A, B;
  for(int i=0; i<M; i++){
    cin >> A >> B;
    G.at(A-1).at(B-1)=1;
    G.at(B-1).at(A-1)=1;
  }
  vector<int> V(0);
  for(int i=1; i<N; i++){
    V.push_back(i);
  }
  int Ans=0;
  do{
    int k=1;
    int now=0;
    for(int i=0; i<N-1; i++){
      if(G.at(now).at(V.at(i))==1){
        now=V.at(i);
      }
      else{
        k=0;
        break;
      }
    }
    Ans+=k;
  }while(next_permutation(V.begin(), V.end())==true);
  cout << Ans << endl;
}
  