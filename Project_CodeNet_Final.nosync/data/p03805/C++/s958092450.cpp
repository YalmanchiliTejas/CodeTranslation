#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  bool G[10][10]={false};
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G[a][b]=true;
    G[b][a]=true;
  }
  vector<int>ord(N);
  for(int i=0;i<N;i++){
    ord[i]=i;
  }
  int res=0;
  do{
    if(ord[0]!=0)continue;
    bool ok=true;
    for(int i=0;i<N-1;i++){
      int from=ord[i];
      int to=ord[i+1];
      if(!G[from][to])ok=false;
    }
    if(ok)res++;
  }while(next_permutation(ord.begin(),ord.end()));
  cout<<res<<endl;
}