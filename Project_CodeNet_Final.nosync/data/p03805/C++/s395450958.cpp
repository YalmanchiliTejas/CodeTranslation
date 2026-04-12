#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M; cin>>N>>M;
  vector<vector<bool>>C(N,vector<bool>(N,false));
  for(int i=0;i<M;i++){
    int a,b; cin>>a>>b;
    C[a-1][b-1]=true;
    C[b-1][a-1]=true;
  }
  int count=1;
  for(int i=1;i<N;i++)count*=i;
  int ans=0;
  vector<int>B(N);
  for(int i=0;i<N;i++)B[i]=i+1;
  for(int i=0;i<count;i++){
    for(int j=1;j<N;j++){
      if(!C[B[j]-1][B[j-1]-1])break;
      if(j==N-1)ans++;
    }
    next_permutation(B.begin(),B.end());
  }
  cout<<ans<<endl;
}