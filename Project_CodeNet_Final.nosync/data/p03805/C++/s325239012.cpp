#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,M,a,b,ans=0;
  cin>>N>>M;
  int Path[N][N];
  int v[N];
  bool exist;
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin>>a>>b;
      Path[a-1][b-1]=1;
      Path[b-1][a-1]=1;
    }
  }
  for(int i=0;i<N;i++){
    v[i]=i;
  }
  do{
    exist=true;
    if(v[0]!=0){
      exist=false;
    }else{
      for(int i=0;i<N-1;i++){
        if(Path[v[i]][v[i+1]]!=1){ 
          exist=false;
          break;
        }
      }
    }
    if(exist){
      ans++;
    }
    }while(next_permutation(v,v+N));
  cout<<ans<<endl;
}