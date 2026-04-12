#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;cin >> N >> K;
  vector<int> P(N-1);
  for(int i=0;i<N-1;i++){
    P[i] = i+1;
  }
  vector<vector<int>> M(N,vector<int>(N,0));
  for(int j=0;j<K;j++){
    int a,b;cin >> a >> b;
    M[a-1][b-1] = 1;
    M[b-1][a-1] = 1;
  }
  int count = 0;
  do{
    bool valid = true;
    if(M[0][P[0]]==0){
      valid = false;
    }
    for(int j=1;j<N-1;j++){
      if(M[P[j-1]][P[j]]==0){
        valid = false;
      }
    }
    if(valid){
      count ++;
    }
  }while(next_permutation(P.begin(),P.end()));//,P.end());
  cout << count << endl;
}