#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    vector<int> D(M);
    for(int i=0;i<M;i++){
      cin>>D[i];
      D[i]--;
    }

    vector<int> darkness(N,-1);
    for(int i=0;i<M;i++){
      darkness[D[i]]=i;
    }

    vector<vector<int> > v(N, vector<int>(K));
    for(int i=0;i<N;i++){
      for(int j=0;j<K;j++){
        cin>>v[i][j];
        v[i][j]--;
      }
    }
    vector<int> dist((1<<M),2000);
    queue<int> que;
    que.push((1<<M)-1);
    dist[(1<<M)-1]=0;
    while(!que.empty()){
      int now=que.front();
      que.pop();
      for(int k=0;k<K;k++){
        int next_mask=0;
        for(int m=0;m<M;m++){
          if(now & (1<<m)){
            int next = v[D[m]][k];
            if(darkness[next]<0)continue;
            next_mask |= (1<<darkness[next]);
          }
        }
        if(dist[next_mask]>dist[now]+1){
          dist[next_mask]=dist[now]+1;
          que.push(next_mask);
          if(next_mask==0){
            cout<<dist[0]<<endl;
            return 0;
          }
        }
      }
    }
}