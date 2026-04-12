#include<bits/stdc++.h>
using namespace std;
 
#define MAX_N 100
#define MAX_M 16
int N,M,K;
 
int s[MAX_M];
int t[MAX_N];
 
vector<int> G[MAX_N];
int d[(1<<MAX_M)];
 
int main(){
  memset(t,-1,sizeof(t));
   
  cin>>N>>M>>K;
  for(int i=0;i<M;i++){
    cin>>s[i];
    s[i]--;
    t[s[i]]=i;
  }
   
  for(int i=0;i<N;i++){
    G[i].resize(K);
    for(int j=0;j<K;j++){
      cin>>G[i][j];
      G[i][j]--;
    }
  }
 
  memset(d,-1,sizeof(d));
  d[ (1<<M)-1 ]=0;
  queue<int> Q;
  Q.push( (1<<M)-1 );
  while(!Q.empty()){
    int bit=Q.front();Q.pop();
    if(bit==0){
      cout<<d[bit]<<endl;
      break;
    }
    for(int i=0;i<K;i++){
      int nbit=0;
      for(int j=0;j<M;j++){
        int to=G[s[j]][i];
        if(bit>>j&1)
          if(t[to]!=-1)
            nbit|=(1<<t[to]);
      }
      if(d[nbit]==-1){
        d[nbit]=d[bit]+1;
        Q.push(nbit);
      }
    }
  }
  return 0;
}