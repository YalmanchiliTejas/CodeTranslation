#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,A=1,Z=0;
  cin>>N>>M;
  vector<int> v(N);
  for(int i=0;i<N;i++){
    v.at(i)=i;
    A*=(i+1);
  }
  A/=N;
  vector<vector<int>> G(N,vector<int>(N));
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G.at(a).at(b)++;
    G.at(b).at(a)++;
  }
  for(int i=0;i<A;i++){
    int B=0;
    for(int j=1;j<N;j++){
      if(G.at(v.at(j)).at(v.at(j-1))==0){
        B++;
        break;
      }
    }
    if(B==0){
      Z++;
    }
    next_permutation(begin(v),end(v));
  }
  cout<<Z<<endl;
}


