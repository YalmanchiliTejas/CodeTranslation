#include<bits/stdc++.h>
using namespace std;
long N,M,K;
long D[20];
int roomlump[110];
long v[105][105];
long long dist[1<<17],INF=2000;
queue<long long> que;

int main(){
  cin>>N>>M>>K;
  fill(roomlump,roomlump+110,-1);

  for(int i=0;i<M;i++){
    cin>>D[i];
    D[i]--;
    roomlump[D[i]]=i;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      cin>>v[i][j];
      v[i][j]--;
    }
  }
  long long initial=((1<<M)-1);
  fill(dist,dist+(1<<M),INF);
  que.push(initial);
  dist[(1<<M)-1]=0;

  while(!que.empty()){
    long long current = que.front();
    que.pop();
    for(int j=0;j<K;j++){
      long long next=0;
      for(int i=0;i<M;i++){
        if((current)&(1<<i)){
          if(roomlump[v[D[i]][j]]!=-1){
            next |= 1<<(roomlump[v[D[i]][j]]);
          }
        }
      }
      if(dist[next]>dist[current]+1){
        dist[next]=dist[current]+1;
        if(next!=0) que.push(next);
      }
    }
  }
  cout<<dist[0]<<endl;
  return 0;
}