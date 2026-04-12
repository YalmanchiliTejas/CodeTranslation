#include <bits/stdc++.h>
using namespace std;

int S_max=3001;
int64_t MOD=998244353;

int main(){
  int N;
  cin>>N;
  int S;
  cin>>S;
  vector<int> A(N);
  for(int i=0;i<N;++i) cin>>A[i];

  //g[L][S]はf[L][R][S]のRを走る和
  vector<vector<int64_t>> g(N+1,vector<int64_t>(S_max,0));
  for(int i=0;i<=N;++i) g[i][0]=1;


  //漸化式
  for(int i=N-1;i>=0;--i){
    for(int j=1;j<=S;++j){
      if(A[i]==j) g[i][j]=(N-i)+g[i+1][j];
      else if(A[i]<j) g[i][j]=g[i+1][j]+g[i+1][j-A[i]];
      else g[i][j]=g[i+1][j];
      g[i][j] %= MOD;
    }
  }

  int64_t ans=0;
  for(int i=0;i<N;++i){
    ans += g[i][S];
    ans %= MOD;
  }

  cout<<ans<<endl;

}
