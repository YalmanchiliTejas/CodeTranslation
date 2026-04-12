#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<vector<bool>>A(N,vector<bool>(N,0));
  for(int i=0;i<M;i++){
    int a,b;cin>>a>>b;A[a-1][b-1]=1;A[b-1][a-1]=1;
  }
  vector<int>v(N-1);for(int i=1;i<N;i++)v[i-1]=i;
  int ans=0;
  do{
    int s=0;
    for(int n:v){
      if(!A[s][n])break;
      s=n;
    }
    if(s==v[v.size()-1])ans++;
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans;
}